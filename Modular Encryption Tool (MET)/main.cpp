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
    int mode, operation;
    std::string text;

    // Select mode: Morse Code or Binary
    std::cout << "Select mode:\n1. Morse Code\n2. Binary\n";
    std::cin >> mode;

    // Select operation: Encrypt or Decrypt
    std::cout << "Select operation:\n1. Encrypt\n2. Decrypt\n";
    std::cin >> operation;

    std::cout << "Enter text: ";
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

    std::cout << "Result: " << result << std::endl;

    return 0;
}
