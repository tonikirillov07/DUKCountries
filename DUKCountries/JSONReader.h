#pragma once
#include <nlohmann/json.hpp>

using json = nlohmann::json;

ref class JSONReader
{
public:
	static json readJSON(const char* filename);
};

