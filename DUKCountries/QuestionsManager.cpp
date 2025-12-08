#include "QuestionsManager.h"
#include "CountryDataManager.h"
#include <algorithm> 
#include <random> 
#include <msclr\\marshal_cppstd.h>
#include <cstdlib> 
#include <iostream>

cliext::vector<Question^>^ QuestionsManager::getQuestionsList(int count, const char* dataFile) {
	std::random_device rd;       
	std::mt19937 randomFunction(rd());
	std::uniform_int_distribution<> dist(0, 2);

	cliext::vector<Question^>^ questions = gcnew cliext::vector<Question^>();

	Question^ question;
	CountryData^ countryInfo1;
	CountryData^ countryInfo2;
	CountryData^ countryInfo3;
	CountryData^ mainCountryInfo;
	CountryDataManager countryDataManager;

	int mainCountryDataIndex;

	for (int i = 0; i < count; i++) {
		countryInfo1 = countryDataManager.getRandomCountryFromFile(dataFile);
		countryInfo2 = countryDataManager.getRandomCountryFromFile(dataFile);
		countryInfo3 = countryDataManager.getRandomCountryFromFile(dataFile);

		cli::array<CountryData^>^ countries = gcnew cli::array<CountryData^>{ countryInfo1, countryInfo2, countryInfo3 };

		mainCountryDataIndex = dist(randomFunction);
		mainCountryInfo = countries[mainCountryDataIndex];

		question = gcnew Question(countries, mainCountryDataIndex);

		questions->push_back(question);
	}

	return questions;
}