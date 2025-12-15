#include "Main.h"
#include "MainForm.h"

using namespace System;
using namespace System::Windows::Forms;


/*
	Запуск программы
*/

int main() {
	//Базовые настройки окна: рендер текста и стили
	Application::SetCompatibleTextRenderingDefault(false);
	Application::EnableVisualStyles();

	//Запуск
	DUKCountries::MainForm mainForm;
	Application::Run(% mainForm);
}