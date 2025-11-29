#include "JSONReader.h"
#include <fstream>
#include <nlohmann/json.hpp>
#include <msclr\\marshal_cppstd.h>

json JSONReader::readJSON(const char* filename) {
    std::ifstream inputStream(filename);
    if (!inputStream.is_open()) {
        auto managedFilename = msclr::interop::marshal_as<System::String^>(filename);
        System::Windows::Forms::MessageBox::Show(
            "Cannot open file: " + managedFilename,
            "Error",
            System::Windows::Forms::MessageBoxButtons::OK,
            System::Windows::Forms::MessageBoxIcon::Error);
        return nullptr;
    }

    nlohmann::json parsedJSON = nlohmann::json::parse(inputStream);
    inputStream.close();

    return parsedJSON;
}