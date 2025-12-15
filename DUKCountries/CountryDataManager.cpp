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

std::wstring stringToWString(std::string str);
int findCountryIndex(size_t dataSize);

std::vector<int> generatedIndecies;

/*
	Возвращает случайную страну из файла по пути filename
*/
CountryData^ CountryDataManager::getRandomCountryFromFile(const char* filename) {
	//Создание JSON-объекта
	nlohmann::json data = JSONReader::readJSON(filename);
	if (data == nullptr)
		throw new runtime_error("Failed to read data from file");

	//Генерация случайного индекса и получение по нему объекта item
	int randomIndex = findCountryIndex(data.size());
	auto item = data[randomIndex];

	//Получение данных из объектов
	std::wstring countryStr = stringToWString(item["country"].get<std::string>());
	std::wstring capitalStr = stringToWString(item["capital"].get<std::string>());

	//Конвертация данных из wstring в System::String
	System::String^ country = gcnew System::String(countryStr.c_str());
	System::String^ capital = gcnew System::String(capitalStr.c_str());

	//Создание и добавление объекта CountryData
	CountryData^ info = gcnew CountryData(country, capital);
	generatedIndecies.push_back(randomIndex);

	return info;
}

//Находит случайный индекс
int findCountryIndex(size_t dataSize) {
	srand(time(0));

	int randomIndex = (rand() % (dataSize - 1));
	bool isFound = false;

	//Очистка использованных индексов, если перебрали все возможные индексы
	if (generatedIndecies.size() == dataSize)
		generatedIndecies.clear();

	//Пока не нашли нужный индекс, увеличиваем случайно сгенерированный на 1, ограничив его длинной списка
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

//Конвертирует std::string в std::wstring
std::wstring stringToWString(std::string str)
{
	std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;
	return converter.from_bytes(str);
}

