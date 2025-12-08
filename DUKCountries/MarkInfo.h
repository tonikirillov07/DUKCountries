#pragma once
#include <vector>
#include <string>

ref class MarkInfo
{
private:
	System::String^ date;
	int mark;

public:
	MarkInfo(System::String^ date, int mark) {
		this->date = date;
		this->mark = mark;
	}

	MarkInfo(MarkInfo^ markInfo) {
		this->date = markInfo->date;
		this->mark = markInfo->mark;
	}

	MarkInfo() {}

	System::String^ getDate();
	std::vector<std::string> getSplitDate();
	int getMark();
	int getMonth();
	int getDay();
	int getYear();
};

