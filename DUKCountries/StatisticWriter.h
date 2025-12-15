#pragma once
ref class StatisticWriter
{
public:
	void addNewResultsData(const char* date, int rightAsnwers, const char* filename);
	void clearStatistics(const char* filename);
};

