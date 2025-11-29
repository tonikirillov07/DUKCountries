#pragma once
#include <string>

using namespace std;

public ref class CountryData
{
public: 
	System::String^ country;
	System::String^ capital;

	CountryData(System::String^ country, System::String^ capital) {
		this->country = country;
		this->capital = capital;
	}

	CountryData(CountryData^ countryData) {
		this->country = countryData->country;
		this->capital = countryData->capital;
	}
	
	CountryData() {}
};

