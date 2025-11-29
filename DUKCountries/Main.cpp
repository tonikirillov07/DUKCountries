#include "Main.h"
#include "MainForm.h"

using namespace System;
using namespace System::Windows::Forms;

int main() {
	Application::SetCompatibleTextRenderingDefault(false);
	Application::EnableVisualStyles();

	DUKCountries::MainForm mainForm;
	Application::Run(% mainForm);
}