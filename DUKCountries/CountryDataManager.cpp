#include "CountryDataManager.h"
#include <algorithm> 
#include <fstream>
#include <msclr\\marshal_cppstd.h>
#include <cstdlib> 
#include <locale>
#include <codecvt>
#include <cliext/vector>
#include "JSONReader.h"

using namespace cliext;

inline std::wstring utf8_to_wstring(const std::string& str);
int findCountryIndex(size_t dataSize);

std::vector<int> generatedIndecies;

CountryData^ CountryDataManager::getRandomCountryFromFile(const char* filename) {
	nlohmann::json data = JSONReader::readJSON(filename);
	if (data == nullptr)
		return gcnew CountryData();

	int randomIndex = findCountryIndex(data.size());

	auto& item = data[randomIndex];

	std::wstring countryStr = utf8_to_wstring(item["country"].get<std::string>());
	std::wstring capitalStr = utf8_to_wstring(item["capital"].get<std::string>());

	System::String^ country = gcnew System::String(countryStr.c_str());
	System::String^ capital = gcnew System::String(capitalStr.c_str());

	CountryData^ info = gcnew CountryData(
		country,
		capital);

	generatedIndecies.push_back(randomIndex);

	return info;
}

int findCountryIndex(size_t dataSize) {
	srand(time(0));
	int randomIndex = (rand() % (dataSize - 1));
	bool isFound = false;

	if (generatedIndecies.size() == dataSize)
		generatedIndecies.clear();

	while (!isFound) {
		if (std::find(generatedIndecies.begin(), generatedIndecies.end(), randomIndex) != generatedIndecies.end()) {
			randomIndex++;

			if (randomIndex >= dataSize)
				randomIndex = 0;
		}
		else 
		{
			isFound = true;
		}
	}

	return randomIndex;
}

inline std::wstring utf8_to_wstring(const std::string& str)
{
	std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;
	return converter.from_bytes(str);
}

