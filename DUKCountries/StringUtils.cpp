#include "StringUtils.h"

//Преобразовывает System::String в массив char
char* StringUtils::convertSystemStringToChars(System::String^ line) {
	int length = line->Length;

	//Записываем все символы из System::String в массив charsArray
	char* charsArray = new char[length];
	for (int i = 0; i < length; i++) {
		charsArray[i] = line->ToCharArray()[i];
	}

	return charsArray;
}