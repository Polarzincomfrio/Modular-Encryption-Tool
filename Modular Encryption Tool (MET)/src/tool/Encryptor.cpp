#include "Encryptor.h"

namespace MET {
	std::string Encryptor::textToBinary(const std::string& text)
	{
        std::string binary;  // String to hold the resulting binary representation
        for (char c : text) {  // Loop through each character in the input text
            binary += std::bitset<8>(c).to_string() + " ";  // Convert the character to an 8-bit binary string and append to the result string
        }
        return binary;  // Return the resulting binary representation string
	}

	std::string Encryptor::textToMorse(const std::string& text)
	{
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
}