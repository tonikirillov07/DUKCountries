#include "StringUtils.h"

char* StringUtils::convertSystemStringToChars(System::String^ line) {
	int length = line->Length;

	char* charsArray = new char[length];
	for (int i = 0; i < length; i++) {
		charsArray[i] = line->ToCharArray()[i];
	}

	return charsArray;
}