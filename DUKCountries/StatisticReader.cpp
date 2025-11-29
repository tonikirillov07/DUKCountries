#include "StatisticReader.h"
#include <fstream>
#include <nlohmann/json.hpp>
#include <msclr\\marshal_cppstd.h>
#include "JSONReader.h"

using json = nlohmann::json;

cliext::vector<MarkInfo^>^ StatisticReader::readAllMarksInfosFromFile(const char* filename) {
    nlohmann::json data = JSONReader::readJSON(filename);
    cliext::vector<MarkInfo^>^ marksInfos = gcnew cliext::vector<MarkInfo^>();

    for (int i = 0; i < data.size(); i++) {
        auto& item = data[i];

        std::string dateStr = item["date"].get<std::string>();
        int mark = item["mark"].get<int>();

        MarkInfo^ markInfo = gcnew MarkInfo(gcnew System::String(dateStr.c_str()), mark);
        marksInfos->push_back(markInfo);
    }

    return marksInfos;
}