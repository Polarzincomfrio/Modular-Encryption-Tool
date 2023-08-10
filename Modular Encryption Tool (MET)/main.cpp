#include "MorseCodeTable.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <bitset>
#include <sstream>
#include <vector>
#include <iomanip>
#include <cassert>
#include <map>


// Function to convert plain text to Morse code
std::string toMorseCode(const std::string& text) {
    std::string morse;  // String to hold the resulting Morse code
    for (char c : text) {  // Loop through each character in the input text
        if (morseCodeTable.find(std::toupper(c)) != morseCodeTable.end()) {  // Check if the character is in the Morse code table
            morse += morseCodeTable[std::toupper(c)] + " ";  // Append the Morse code equivalent to the result string
        }
        else {
            morse += " ";  // If the character is not in the table, add a space to the result string
        }
    }
    return morse;  // Return the resulting Morse code string
}

// Function to convert Morse code to plain text
std::string fromMorseCode(const std::string& morse) {
    std::string text;  // String to hold the resulting plain text
    std::istringstream iss(morse);  // Create a string stream to tokenize the Morse code string
    std::string morseChar;  // String to hold each Morse code character
    while (iss >> morseChar) {  // Loop through each tokenized Morse code character
        for (const auto& pair : morseCodeTable) {  // Loop through each pair in the Morse code table
            if (pair.second == morseChar) {  // If the Morse code character matches a value in the table
                text += pair.first;  // Append the corresponding plain text character to the result string
                break;  // Exit the loop after finding the matching Morse code
            }
        }
    }
    return text;  // Return the resulting plain text string
}

// Function to convert plain text to binary representation
std::string toBinary(const std::string& text) {
    std::string binary;  // String to hold the resulting binary representation
    for (char c : text) {  // Loop through each character in the input text
        binary += std::bitset<8>(c).to_string() + " ";  // Convert the character to an 8-bit binary string and append to the result string
    }
    return binary;  // Return the resulting binary representation string
}

// Function to convert binary representation to plain text
std::string fromBinary(const std::string& binary) {
    std::string text;  // String to hold the resulting plain text
    std::istringstream iss(binary);  // Create a string stream to tokenize the binary string
    std::string binaryByte;  // String to hold each binary byte
    while (iss >> binaryByte) {  // Loop through each tokenized binary byte
        char byte = static_cast<char>(std::bitset<8>(binaryByte).to_ulong());  // Convert the binary byte to a character and store it
        text += byte;  // Append the character to the result string
    }
    return text;  // Return the resulting plain text string
}

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
    std::cout << "     /:/  /       \\:\\__\\                  " << std::endl;
    std::cout << "     \\/__/         \\/__/                  " << std::endl;
    std::cout << "\n\n";
    // ...

    std::string text;  // String to hold user input

    while (true) {  // Start an infinite loop
        int mode, operation;

        // Prompt the user to select mode
        std::cout << "Select mode:\n1. Morse Code \n2. Binary \n--------------------\n";
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
                result = toMorseCode(text);  // Convert plain text to Morse code
            }
            else if (operation == 2) {  // If operation is 'Decrypt'
                result = fromMorseCode(text);  // Convert Morse code to plain text
            }
        }
        else if (mode == 2) {  // If mode is 'Binary'
            if (operation == 1) {  // If operation is 'Encrypt'
                result = toBinary(text);  // Convert plain text to binary representation
            }
            else if (operation == 2) {  // If operation is 'Decrypt'
                result = fromBinary(text);  // Convert binary representation to plain text
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