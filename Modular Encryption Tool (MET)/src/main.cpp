#include <iostream>
#include <string>

#include "tool/Encryptor.h"
#include "tool/Decryptor.h"

using namespace MET;

int main() {

    // Write logo above the terminal
    std::cout << "      ___           ___           ___     " << std::endl;
    std::cout << "     /\\__\\         /\\  \\         /\\  \\    " << std::endl;
    std::cout << "    /::|  |       /::\\  \\        \\:\\  \\   " << std::endl;
    std::cout << "   /:|:|  |      /:/\\:\\  \\        \\:\\  \\  " << std::endl;
    std::cout << "  /:/|:|__|__   /::\\~\\:\\  \\       /::\\  \\ " << std::endl;
    std::cout << " /:/ |::::\\__\\ /:/\\:\\ \\:\\__\\     /:/\\:\\__\\" << std::endl;
    std::cout << " \\/__/~~/:/  / \\:\\~\\:\\ \\/__/    /:/  \\/__/" << std::endl;
    std::cout << "       /:/  /   \\:\\ \\:\\__\\     /:/  /     " << std::endl;
    std::cout << "      /:/  /     \\:\\ \\/__/     \\/__/      " << std::endl;
    std::cout << "     /:/  /       \\:\\__\\                   " << std::endl;
    std::cout << "     \\/__/         \\/__/        by: Joao Vitor Polverari " << std::endl;
    std::cout << "\n\n";
    // ...

    std::string text;  // String to hold user input

    while (true) {  // Start an infinite loop
        int mode, operation;

        // Prompt the user to select mode
        std::cout << "Select mode:\n1. Morse Code\n2. Binary\n--------------------\n";
        std::cin >> mode;

        // Prompt the user to select operation
        std::cout << "--------------------\nSelect operation: \n1. Encrypt \n2. Decrypt \n--------------------\n";
        std::cin >> operation;

        // Prompt the user to enter text
        std::cout << "--------------------\nEnter text: ";
        std::cin.ignore();  // Clear the newline character
        std::getline(std::cin, text);  // Read the entire line of text entered by the user

        std::string result;  // String to hold the resulting conversion

        if (mode == 1) {  // If mode is 'Morse Code'
            if (operation == 1) {  // If operation is 'Encrypt'
                result = Encryptor::textToMorse(text);  // Convert plain text to Morse code
            }
            else if (operation == 2) {  // If operation is 'Decrypt'
                result = Decryptor::morseToText(text);  // Convert Morse code to plain text
            }
        }
        else if (mode == 2) {  // If mode is 'Binary'
            if (operation == 1) {  // If operation is 'Encrypt'
                result = Encryptor::textToBinary(text);  // Convert plain text to binary representation
            }
            else if (operation == 2) {  // If operation is 'Decrypt'
                result = Decryptor::binaryToText(text);  // Convert binary representation to plain text
            }
        }

        std::cout << "Result: " << result << "\n\n--------------------\n" << std::endl;  // Display the result of the conversion

        // Ask the user if they want to continue
        std::cout << "Do you want to do another operation? (y/n): ";
        char choice;
        std::cin >> choice;

        if (choice != 'y' && choice != 'Y') {
            std::cout << "Exiting program. Goodbye!" << std::endl;
            break;  // Exit the loop if the user doesn't want to continue
        }
    }

    return 0;  // Return 0 to indicate successful program execution
}