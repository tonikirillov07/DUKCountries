#include "StatisticWriter.h"

#include <fstream>
#include <iostream>
#include <nlohmann/json.hpp>
#include <msclr\\marshal_cppstd.h>
#include "JSONReader.h"

using json = nlohmann::json;

void writeJsonFile(const std::string& filename, const json& jsonFile);

void StatisticWriter::addNewResultsData(const char* date, int mark, const char* filename) {
    json data = json(JSONReader::readJSON(filename));
    json newMark = {
        {"date", date},
        {"mark", mark}
    };

    data.emplace_back(newMark);

    writeJsonFile(filename, data);
}

void StatisticWriter::clearStatistics(const char* filename) {
    json data = json(JSONReader::readJSON(filename));
    data.clear();

    writeJsonFile(filename, data);
}

void writeJsonFile(const std::string& filename, const json& jsonFile) {
    std::ofstream outputStream(filename);
    if (!outputStream.is_open()) {
        auto managedFilename = msclr::interop::marshal_as<System::String^>(filename);
        System::Windows::Forms::MessageBox::Show(
            "Failed to write file: " + managedFilename,
            "Error",
            System::Windows::Forms::MessageBoxButtons::OK,
            System::Windows::Forms::MessageBoxIcon::Error);
        return;
    }

    outputStream << std::setw(4) << jsonFile << std::endl;

    outputStream.close();
}
