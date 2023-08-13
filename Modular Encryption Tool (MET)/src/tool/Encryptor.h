#pragma once

#include <string>
#include <sstream>
#include <bitset>

#include "../util/MorseCodeTable.h"

namespace MET {
	class Encryptor {
	public:
		static std::string textToBinary(const std::string& binary);
		static std::string textToMorse(const std::string& morse);
		static std::string textToCaesarCipher(const std::string& text, int shift);
	};
}