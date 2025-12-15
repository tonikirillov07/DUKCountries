#pragma once
#include <vector>
#include <string>

ref class MarkInfo
{
private:
	System::String^ date;
	int rightAnswers;

public:
	MarkInfo(System::String^ date, int mark) {
		this->date = date;
		this->rightAnswers = mark;
	}

	MarkInfo(MarkInfo^ markInfo) {
		this->date = markInfo->date;
		this->rightAnswers = markInfo->rightAnswers;
	}

	MarkInfo() {}

	System::String^ getDate();
	std::vector<std::string> getSplitDate();
	int getRightAnswers();
	int getMonth();
	int getDay();
	int getYear();
};

