#include "StatisticReader.h"
#include <fstream>
#include <nlohmann/json.hpp>
#include <msclr\\marshal_cppstd.h>
#include "JSONReader.h"

using json = nlohmann::json;

void sortMarksInfosByDate(cliext::vector<MarkInfo^>^ array);
int getSortSteps(cliext::vector<MarkInfo^>^ array);

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

    sortMarksInfosByDate(marksInfos);

    return marksInfos;
}

bool StatisticReader::hasStatistics(const char* filename) {
    return !JSONReader::readJSON(filename).empty();
}

void sortMarksInfosByDate(cliext::vector<MarkInfo^>^ array) {
    int stepsDone = 1;
    while (stepsDone > 0)
    {
        stepsDone = getSortSteps(array);
    }
}

int getSortSteps(cliext::vector<MarkInfo^>^ array) {
    int steps = 0;

    MarkInfo^ currentMark;
    MarkInfo^ nextMark;
    for (int i = 0; i < array->size(); i++) {
        if (i + 1 >= array->size())
            continue;

        currentMark = array[i];
        nextMark = array[i + 1];

        if ((currentMark->getYear() > nextMark->getYear()) || (currentMark->getYear() == nextMark->getYear() && currentMark->getMonth() > nextMark->getMonth()) ||
            (currentMark->getYear() == nextMark->getYear() && currentMark->getMonth() == nextMark->getMonth() && currentMark->getDay() > nextMark->getDay())) {
            MarkInfo^ temp = gcnew MarkInfo(nextMark);

            array[i] = gcnew MarkInfo(temp);
            array[i + 1] = gcnew MarkInfo(currentMark);

            steps++;
        }
    }

    return steps;
}