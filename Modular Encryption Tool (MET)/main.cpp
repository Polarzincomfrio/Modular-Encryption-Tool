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
    std::string morse;
    for (char c : text) {
        if (morseCodeTable.find(std::toupper(c)) != morseCodeTable.end()) {
            morse += morseCodeTable[std::toupper(c)] + " ";
        }
        else {
            morse += " ";
        }
    }
    return morse;
}

// Function to convert Morse code to plain text
std::string fromMorseCode(const std::string& morse) {
    std::string text;
    std::istringstream iss(morse);
    std::string morseChar;
    while (iss >> morseChar) {
        for (const auto& pair : morseCodeTable) {
            if (pair.second == morseChar) {
                text += pair.first;
                break;
            }
        }
    }
    return text;
}

// Function to convert plain text to binary representation
std::string toBinary(const std::string& text) {
    std::string binary;
    for (char c : text) {
        binary += std::bitset<8>(c).to_string() + " ";
    }
    return binary;
}

// Function to convert binary representation to plain text
std::string fromBinary(const std::string& binary) {
    std::string text;
    std::istringstream iss(binary);
    std::string binaryByte;
    while (iss >> binaryByte) {
        char byte = static_cast<char>(std::bitset<8>(binaryByte).to_ulong());
        text += byte;
    }
    return text;
}

int main() {
    std::string text;

    while (true) {
        int mode, operation;

        // Select mode: Morse Code or Binary
        std::cout << "Select mode:\n1. Morse Code \n2. Binary \n--------------------\n";
        std::cin >> mode;

        // Select operation: Encrypt or Decrypt
        std::cout << "--------------------\nSelect operation: \n1. Encrypt \n2. Decrypt \n--------------------\n";
        std::cin >> operation;

        std::cout << "--------------------\nEnter text: ";
        std::cin.ignore(); // Clear the newline character
        std::getline(std::cin, text);

        std::string result;

        if (mode == 1) {
            if (operation == 1) {
                result = toMorseCode(text);
            }
            else if (operation == 2) {
                result = fromMorseCode(text);
            }
        }
        else if (mode == 2) {
            if (operation == 1) {
                result = toBinary(text);
            }
            else if (operation == 2) {
                result = fromBinary(text);
            }
        }

        std::cout << "Result: " << result << "\n\n--------------------\n" << std::endl;

        // Ask if the user wants to continue
        std::cout << "Do you want to do another operation? (y/n): ";
        char choice;
        std::cin >> choice;

        if (choice != 'y' && choice != 'Y') {
            std::cout << "Exiting program. Goodbye!" << std::endl;
            break; // Exit the loop if user doesn't want to continue
        }
    }

    return 0;
}
