#pragma once
#include "Question.h"
#include <vector>

public ref class QuestionsManager
{
public:
	cliext::vector<Question^>^ getQuestionsList(int count, const char* dataFile);

	QuestionsManager() {};
	~QuestionsManager() {};
};

