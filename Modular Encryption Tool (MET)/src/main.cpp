#include <iostream>
#include <string>
#include <chrono>
#include <thread>

#include "tool/Encryptor.h"
#include "tool/Decryptor.h"

using namespace MET;

void printDivider() {
    std::cout << "--------------------\n";
}

int getUserInputInt(const std::string& prompt) {
    int value;
    while (true) {
        std::cout << prompt;
        if (std::cin >> value) {
            return value;
        }
        else {
            std::cout << "Invalid input. Please enter a valid integer.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
}

std::string getUserInputText(const std::string& prompt) {
    std::string text;
    while (true) {
        std::cout << prompt;
        std::cin.ignore();
        std::getline(std::cin, text);
        if (!text.empty()) {
            return text;
        }
        else {
            std::cout << "Invalid input. Please enter some text.\n";
        }
    }
}

void processMorseMode(int operation) {
    std::string text = getUserInputText("Enter text: ");
    std::string result;

    if (operation == 1) {
        result = Encryptor::textToMorse(text);
    }
    else if (operation == 2) {
        result = Decryptor::morseToText(text);
    }

    std::cout << "Result: " << result << "\n\n";
}

void processBinaryMode(int operation) {
    std::string text = getUserInputText("Enter text: ");
    std::string result;

    if (operation == 1) {
        result = Encryptor::textToBinary(text);
    }
    else if (operation == 2) {
        result = Decryptor::binaryToText(text);
    }

    std::cout << "Result: " << result << "\n\n";
}

void processCaesarMode(int operation) {
    std::string text = getUserInputText("Enter text: ");
    int shift = getUserInputInt("Enter Caesar Cipher shift value: ");
    std::string result;

    if (operation == 1) {
        result = Encryptor::textToCaesarCipher(text, shift);
    }
    else if (operation == 2) {
        result = Decryptor::caesarCipherToText(text, shift);
    }

    std::cout << "Result: " << result << "\n\n";
}

void processConversionLoop() {
    while (true) {
        printDivider();

        int mode = 0;
        while (mode < 1 || mode > 3) { // Change the mode max number if a new mode case is added
            mode = getUserInputInt("Select mode:\n1. Morse Code\n2. Binary\n3. Caesar Cipher\nYour Input: ");
            if (mode < 1 || mode > 3) { // Change the mode max number if a new mode case is added
                printDivider();
                std::cout << "Invalid mode. Please enter a valid mode.\n";
                printDivider();
            }
        }

        printDivider();

        int operation = 0;
        while (operation < 1 || operation > 2) { // Change the operation max number if a new operation case is added
            operation = getUserInputInt("Select operation:\n1. Encrypt\n2. Decrypt\nYour Input: ");
            if (operation < 1 || operation > 2) { // Change the operation max number if a new operation case is added
                printDivider();
                std::cout << "Invalid operation. Please enter a valid operation.\n";
                printDivider();
            }
        }

        printDivider();

        switch (mode) {
        case 1:
            processMorseMode(operation);
            break;
        case 2:
            processBinaryMode(operation);
            break;
        case 3:
            processCaesarMode(operation);
            break;
        default:
            std::cout << "Invalid mode. Please try again.\n\n";
        }

        char choice;
        std::cout << "Do you want to do another operation? (y/n): ";
        std::cin >> choice;

        if (choice != 'y' && choice != 'Y') {
            std::cout << "Exiting program. Goodbye!\n";
            std::this_thread::sleep_for(std::chrono::seconds(1));
            break;
        }
    }
}

int main() {
    // Print app's logo...
    std::cout << R"(
      ___           ___           ___     
     /\__\         /\  \         /\  \    
    /::|  |       /::\  \        \:\  \   
   /:|:|  |      /:/\:\  \        \:\  \  
  /:/|:|__|__   /::\~\:\  \       /::\  \ 
 /:/ |::::\__\ /:/\:\ \:\__\     /:/\:\__\
 \/__/~~/:/  / \:\~\:\ \/__/    /:/  \/__/
       /:/  /   \:\ \:\__\     /:/  /     
      /:/  /     \:\ \/__/     \/__/      
     /:/  /       \:\__\                   
     \/__/         \/__/       by: Joao Vitor Polverari
)" << std::endl;
    //...

    processConversionLoop();
    return 0;
}
