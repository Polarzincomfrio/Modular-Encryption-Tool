#include "Decryptor.h"

namespace MET {
	std::string Decryptor::binaryToText(const std::string& binary) {
        std::string text;  // String to hold the resulting plain text
        std::istringstream iss(binary);  // Create a string stream to tokenize the binary string
        std::string binaryByte;  // String to hold each binary byte
        while (iss >> binaryByte) {  // Loop through each tokenized binary byte
            char byte = static_cast<char>(std::bitset<8>(binaryByte).to_ulong());  // Convert the binary byte to a character and store it
            text += byte;  // Append the character to the result string
        }
        return text;  // Return the resulting plain text string
	}

    std::string Decryptor::morseToText(const std::string& morse) {
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
}