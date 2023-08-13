#include "Encryptor.h"

namespace MET {
    std::string Encryptor::textToBinary(const std::string& text) {
        std::string binary;

        for (char c : text) {
            binary += std::bitset<8>(c).to_string() + " ";
        }
        return binary;
    }

    std::string Encryptor::textToMorse(const std::string& text) {
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

    std::string Encryptor::textToCaesarCipher(const std::string& text, int shift) {
        std::string result = "";

        for (char c : text) {
            if (isalpha(c)) {
                char base = (isupper(c)) ? 'A' : 'a';
                char encryptedChar = base + (c - base + shift) % 26;
                result += encryptedChar;
            }
            else {
                result += c;
            }
        }
        return result;
    }
}
