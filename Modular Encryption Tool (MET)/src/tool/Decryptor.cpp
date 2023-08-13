#include "Decryptor.h"

namespace MET {

    std::string Decryptor::binaryToText(const std::string& binary) {
        std::string text;
        std::istringstream iss(binary);
        std::string binaryByte;

        while (iss >> binaryByte) {
            char byte = static_cast<char>(std::bitset<8>(binaryByte).to_ulong());
            text += byte;
        }
        return text;
    }

    std::string Decryptor::morseToText(const std::string& morse) {
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

    std::string Decryptor::caesarCipherToText(const std::string& cipherText, int shift) {
        std::string result;

        for (char c : cipherText) {
            if (isalpha(c)) {
                char base = (isupper(c)) ? 'A' : 'a';
                char decryptedChar = base + (c - base + (26 - shift)) % 26;
                result += decryptedChar;
            }
            else {
                result += c;
            }
        }
        return result;
    }
}
