#include "StatisticWriter.h"

#include <fstream>
#include <iostream>
#include <nlohmann/json.hpp>
#include <msclr\\marshal_cppstd.h>
#include "JSONReader.h"

using json = nlohmann::json;

void writeJsonFile(const char* filename, json jsonFile);

/*
* Добавляет новые данные об оценке в файл статистики по пути filename
*/
void StatisticWriter::addNewResultsData(const char* date, int rightAnswers, const char* filename) {
    json data = json(JSONReader::readJSON(filename));
    
    //Создание нового объекта статистики и добавление его к остальным объектам
    json newStatisticObject = {
        {"date", date},
        {"rightAnswers", rightAnswers}
    };

    data.push_back(newStatisticObject);

    //Перезаписываем файл статистики
    writeJsonFile(filename, data);
}

//Очищает файл со статистикой
void StatisticWriter::clearStatistics(const char* filename) {
    json data = json(JSONReader::readJSON(filename));
    data.clear();

    writeJsonFile(filename, data);
}

//Перезаписывает файл со статистикой
void writeJsonFile(const char* filename, json jsonFile) {
    //Создание объекта ofstream для записи
    std::ofstream outputStream(filename);

    //Показываем окно с ошибкой, если не удалось открыть файл filename для записи
    if (!outputStream.is_open()) {
        auto managedFilename = msclr::interop::marshal_as<System::String^>(filename);
        System::Windows::Forms::MessageBox::Show(
            "Failed to write file: " + managedFilename,
            "Error",
            System::Windows::Forms::MessageBoxButtons::OK,
            System::Windows::Forms::MessageBoxIcon::Error);
        return;
    }

    //Запись в файл при помощи потока вывода
    outputStream << std::setw(4) << jsonFile << std::endl;

    //Закрытие outputStream
    outputStream.close();
}
