#pragma once
#include "CountryData.h"
#include <cliext/vector>

public ref class Question
{
public:
    cli::array<CountryData^>^ answers;
    int correctAnswer, selectedAnswer = -1;

    void setSelectedAnswer(int selectedAnswer);

    Question(cli::array<CountryData^>^ answers,
        int correctAnswer)
        : answers(answers),
        correctAnswer(correctAnswer) {}

    Question(Question^ question) {
        this->answers = question->answers;
        this->correctAnswer = question->correctAnswer;
    }

    Question() {}

    ~Question() {
        answers->Clear(answers, 0, answers->Length);
    }
};

