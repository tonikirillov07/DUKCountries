#pragma once
#include "CountryData.h"
#include <cliext/vector>
#include <nlohmann/json.hpp>

using namespace cliext;

class CountryDataManager
{
public:
	CountryData^ getRandomCountryFromFile(const char* filename);
};

