#pragma once

#include <string>
#include <sstream>
#include <bitset>

#include "../util/MorseCodeTable.h"

namespace MET {
	class Decryptor {
	public:
        static std::string binaryToText(const std::string& binary);
		static std::string morseToText(const std::string& morse);
		static std::string caesarCipherToText(const std::string& cipherText, int shift);
	};
}