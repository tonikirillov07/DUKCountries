#include "JSONReader.h"
#include <fstream>
#include <nlohmann/json.hpp>
#include <msclr\\marshal_cppstd.h>

//Читает данные из JSON-файла по пути filename
json JSONReader::readJSON(const char* filename) {
    //Создание ifstream для чтения данных
    std::ifstream inputStream(filename);

    //Показ окна с ошибкой, если не удалось открыть файл для чтения
    if (!inputStream.is_open()) {
        auto managedFilename = msclr::interop::marshal_as<System::String^>(filename);

        System::Windows::Forms::MessageBox::Show(
            "Cannot open file: " + managedFilename,
            "Error",
            System::Windows::Forms::MessageBoxButtons::OK,
            System::Windows::Forms::MessageBoxIcon::Error);
        return nullptr;
    }

    //Запись JSON-данных в переменную parsedJSON типа nlohmann::json и закрытие inputStream
    nlohmann::json parsedJSON = nlohmann::json::parse(inputStream);
    inputStream.close();

    return parsedJSON;
}