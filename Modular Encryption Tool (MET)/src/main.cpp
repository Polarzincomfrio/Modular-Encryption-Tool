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
    std::cout << prompt;
    std::cin >> value;
    return value;
}

std::string getUserInputText(const std::string& prompt) {
    std::string text;
    std::cout << prompt;
    std::cin.ignore();
    std::getline(std::cin, text);
    return text;
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
        int mode = getUserInputInt("Select mode:\n1. Morse Code\n2. Binary\n3. Caesar Cipher\nYour Input: ");
        printDivider();
        int operation = getUserInputInt("Select operation:\n1. Encrypt\n2. Decrypt\nYour Input: ");
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
