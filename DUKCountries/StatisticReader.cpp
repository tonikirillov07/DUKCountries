#include "StatisticReader.h"
#include <fstream>
#include <nlohmann/json.hpp>
#include <msclr\\marshal_cppstd.h>
#include "JSONReader.h"

using json = nlohmann::json;

void sortMarksInfosByDate(cliext::vector<MarkInfo^>^ array);
int getSortSteps(cliext::vector<MarkInfo^>^ array);

/*
* Читает и возвращает все данные об оценках из файла статистики по пути filename
*/
cliext::vector<MarkInfo^>^ StatisticReader::readAllMarksInfosFromFile(const char* filename) {
    nlohmann::json data = JSONReader::readJSON(filename);
    cliext::vector<MarkInfo^>^ marksInfos = gcnew cliext::vector<MarkInfo^>();

    for (int i = 0; i < data.size(); i++) {
        auto item = data[i];

        //Получаем данные из объекта
        std::string dateStr = item["date"].get<std::string>();
        int mark = item["rightAnswers"].get<int>();

        //Создаем объекта MarkInfo на основе полученных данных и добавляем его в список marksInfos
        MarkInfo^ markInfo = gcnew MarkInfo(gcnew System::String(dateStr.c_str()), mark);
        marksInfos->push_back(markInfo);
    }

    //Сортируем "пузырьком" по датам
    sortMarksInfosByDate(marksInfos);

    return marksInfos;
}

bool StatisticReader::hasStatistics(const char* filename) {
    return !JSONReader::readJSON(filename).empty();
}

/*
* Сортирует список до тех пор, пока он не будет отсортирован
*/
void sortMarksInfosByDate(cliext::vector<MarkInfo^>^ array) {
    int stepsDone = 1;
    while (stepsDone > 0)
    {
        stepsDone = getSortSteps(array);
    }
}

int getSortSteps(cliext::vector<MarkInfo^>^ array) {
    //Счетчик, сколько раз пришлось поменять даты местами
    int steps = 0;

    MarkInfo^ currentMark;
    MarkInfo^ nextMark;
    for (int i = 0; i < array->size(); i++) {
        //Мы на последнем объекте в списке? Попускаем данную итерацию
        if (i + 1 >= array->size())
            continue;

        currentMark = array[i];
        nextMark = array[i + 1];

        //"Текущая" оценка получена после "последующей"?
        if ((currentMark->getYear() > nextMark->getYear()) || (currentMark->getYear() == nextMark->getYear() && 
            currentMark->getMonth() > nextMark->getMonth()) ||
            (currentMark->getYear() == nextMark->getYear() && currentMark->getMonth() == nextMark->getMonth() 
                && currentMark->getDay() > nextMark->getDay())) {
            MarkInfo^ temp = gcnew MarkInfo(nextMark);

            //Меняем местами в списке объекты оценок
            array[i] = gcnew MarkInfo(temp);
            array[i + 1] = gcnew MarkInfo(currentMark);

            //Увеличиваем счетчик
            steps++;
        }
    }

    return steps;
}