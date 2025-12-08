#include "MarkInfo.h"
#include <string>
#include <sstream>
#include "StringUtils.h"

System::String^ MarkInfo::getDate() {
	return this->date;
}

int MarkInfo::getMark() {
	return this->mark;
}

std::vector<std::string> MarkInfo::getSplitDate() {
	array<System::String^>^ chunksSystemString = getDate()->Split('/');
	std::vector<std::string> chunksStdString;

	for (int i = 0; i < chunksSystemString->Length; i++) {
		chunksStdString.push_back(std::string(StringUtils::convertSystemStringToChars(chunksSystemString[i])));
	}

	return chunksStdString;
}

int MarkInfo::getDay() {
	return std::stoi(this->getSplitDate()[0]);
}

int MarkInfo::getMonth() {
	return std::stoi(this->getSplitDate()[1]);
}

int MarkInfo::getYear() {
	return std::stoi(this->getSplitDate()[2]);
}