#pragma once
#include <cstdlib> 
#include <cliext/vector>
#include "MarkInfo.h"

using namespace cliext;

ref class StatisticReader
{
public:
	cliext::vector<MarkInfo^>^ readAllMarksInfosFromFile(const char* filename);
	bool StatisticReader::hasStatistics(const char* filename);
};

