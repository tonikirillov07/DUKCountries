#pragma once

#include <nlohmann/json.hpp>
#include <fstream>
#include <vector>
#include "iostream"
#include <cstdlib> 
#include <msclr\\marshal_cppstd.h>
#include <locale>
#include <codecvt>
#include <string>
#include <ctime>
#include <algorithm>

#include "CountryData.h"
#include "CountryDataManager.h"
#include "Question.h"
#include "QuestionsManager.h"
#include "StatisticWriter.h"
#include "StringUtils.h"

namespace DUKCountries {
	using namespace std;
	using namespace System;
	using namespace System::Reflection;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for TestForm
	/// </summary>
	public ref class TestForm : public System::Windows::Forms::Form
	{
	public:
		TestForm(System::Windows::Forms::Form^ previousForm)
		{
			this->previousForm = previousForm;

			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~TestForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: int currentQuestionIndex, correctAnswers;
	private: cliext::vector<Question^>^ questions;
	private: QuestionsManager^ questionsManager;
	private: StatisticWriter statisticWriter;
	private: System::Windows::Forms::Form^ previousForm;
	private: System::Windows::Forms::PictureBox^ pictureBox2;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::Button^ buttonBack;
	private: System::Windows::Forms::Label^ labelTitle;
	private: System::Windows::Forms::Label^ labelQuestionNumber;

	private: System::Windows::Forms::PictureBox^ pictureBox3;
	private: System::Windows::Forms::FlowLayoutPanel^ flowLayoutPanel1;
	private: System::Windows::Forms::FlowLayoutPanel^ flowLayoutPanel2;
	private: System::Windows::Forms::Label^ labelQuestion;
	private: System::Windows::Forms::GroupBox^ groupBox;

	public: System::Windows::Forms::RadioButton^ radioButtonThree;
	public: System::Windows::Forms::RadioButton^ radioButtonSecond;
	public: System::Windows::Forms::RadioButton^ radioButtonFirst;
	private: System::Windows::Forms::Button^ buttonContinue;
	private: System::Windows::Forms::Button^ buttonPreviousQuestion;
	private: System::Windows::Forms::Label^ labelMark;


	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(TestForm::typeid));
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->buttonBack = (gcnew System::Windows::Forms::Button());
			this->labelTitle = (gcnew System::Windows::Forms::Label());
			this->labelQuestionNumber = (gcnew System::Windows::Forms::Label());
			this->pictureBox3 = (gcnew System::Windows::Forms::PictureBox());
			this->flowLayoutPanel1 = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->flowLayoutPanel2 = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->labelQuestion = (gcnew System::Windows::Forms::Label());
			this->groupBox = (gcnew System::Windows::Forms::GroupBox());
			this->radioButtonThree = (gcnew System::Windows::Forms::RadioButton());
			this->radioButtonSecond = (gcnew System::Windows::Forms::RadioButton());
			this->radioButtonFirst = (gcnew System::Windows::Forms::RadioButton());
			this->buttonContinue = (gcnew System::Windows::Forms::Button());
			this->buttonPreviousQuestion = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->BeginInit();
			this->flowLayoutPanel1->SuspendLayout();
			this->flowLayoutPanel2->SuspendLayout();
			this->groupBox->SuspendLayout();
			this->SuspendLayout();
			// 
			// pictureBox2
			// 
			this->pictureBox2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->pictureBox2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.Image")));
			this->pictureBox2->Location = System::Drawing::Point(1136, 695);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(171, 148);
			this->pictureBox2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox2->TabIndex = 6;
			this->pictureBox2->TabStop = false;
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(12, 12);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(171, 148);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox1->TabIndex = 5;
			this->pictureBox1->TabStop = false;
			// 
			// buttonBack
			// 
			this->buttonBack->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->buttonBack->BackColor = System::Drawing::Color::Transparent;
			this->buttonBack->Cursor = System::Windows::Forms::Cursors::Hand;
			this->buttonBack->FlatAppearance->BorderSize = 0;
			this->buttonBack->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->buttonBack->ForeColor = System::Drawing::Color::Transparent;
			this->buttonBack->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"buttonBack.Image")));
			this->buttonBack->Location = System::Drawing::Point(1232, 12);
			this->buttonBack->Name = L"buttonBack";
			this->buttonBack->Size = System::Drawing::Size(75, 69);
			this->buttonBack->TabIndex = 7;
			this->buttonBack->UseVisualStyleBackColor = false;
			this->buttonBack->Click += gcnew System::EventHandler(this, &TestForm::buttonBack_Click);
			// 
			// labelTitle
			// 
			this->labelTitle->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
			this->labelTitle->Font = (gcnew System::Drawing::Font(L"Arial", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelTitle->Location = System::Drawing::Point(380, 261);
			this->labelTitle->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->labelTitle->Name = L"labelTitle";
			this->labelTitle->Size = System::Drawing::Size(576, 32);
			this->labelTitle->TabIndex = 8;
			this->labelTitle->Text = L"Давайте начнем!";
			this->labelTitle->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// labelQuestionNumber
			// 
			this->labelQuestionNumber->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
			this->labelQuestionNumber->Font = (gcnew System::Drawing::Font(L"Arial Black", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelQuestionNumber->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(98)),
				static_cast<System::Int32>(static_cast<System::Byte>(98)), static_cast<System::Int32>(static_cast<System::Byte>(98)));
			this->labelQuestionNumber->Location = System::Drawing::Point(33, 2);
			this->labelQuestionNumber->Name = L"labelQuestionNumber";
			this->labelQuestionNumber->Size = System::Drawing::Size(106, 26);
			this->labelQuestionNumber->TabIndex = 11;
			this->labelQuestionNumber->Text = L"0 / 0";
			// 
			// pictureBox3
			// 
			this->pictureBox3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
			this->pictureBox3->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox3->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox3.Image")));
			this->pictureBox3->Location = System::Drawing::Point(3, 3);
			this->pictureBox3->Name = L"pictureBox3";
			this->pictureBox3->Size = System::Drawing::Size(24, 24);
			this->pictureBox3->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox3->TabIndex = 10;
			this->pictureBox3->TabStop = false;
			// 
			// flowLayoutPanel1
			// 
			this->flowLayoutPanel1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->flowLayoutPanel1->Controls->Add(this->pictureBox3);
			this->flowLayoutPanel1->Controls->Add(this->labelQuestionNumber);
			this->flowLayoutPanel1->Location = System::Drawing::Point(599, 307);
			this->flowLayoutPanel1->Margin = System::Windows::Forms::Padding(0, 4, 0, 4);
			this->flowLayoutPanel1->Name = L"flowLayoutPanel1";
			this->flowLayoutPanel1->Size = System::Drawing::Size(147, 33);
			this->flowLayoutPanel1->TabIndex = 12;
			// 
			// flowLayoutPanel2
			// 
			this->flowLayoutPanel2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->flowLayoutPanel2->AutoSize = true;
			this->flowLayoutPanel2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(159)),
				static_cast<System::Int32>(static_cast<System::Byte>(160)), static_cast<System::Int32>(static_cast<System::Byte>(166)));
			this->flowLayoutPanel2->Controls->Add(this->labelQuestion);
			this->flowLayoutPanel2->ForeColor = System::Drawing::Color::Transparent;
			this->flowLayoutPanel2->Location = System::Drawing::Point(451, 377);
			this->flowLayoutPanel2->Name = L"flowLayoutPanel2";
			this->flowLayoutPanel2->Size = System::Drawing::Size(440, 94);
			this->flowLayoutPanel2->TabIndex = 13;
			// 
			// labelQuestion
			// 
			this->labelQuestion->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom));
			this->labelQuestion->AutoSize = true;
			this->labelQuestion->Font = (gcnew System::Drawing::Font(L"Arial", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelQuestion->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->labelQuestion->Location = System::Drawing::Point(0, 20);
			this->labelQuestion->Margin = System::Windows::Forms::Padding(0, 20, 0, 20);
			this->labelQuestion->Name = L"labelQuestion";
			this->labelQuestion->Size = System::Drawing::Size(286, 27);
			this->labelQuestion->TabIndex = 0;
			this->labelQuestion->Text = L"Назовите столицу Китая";
			// 
			// groupBox
			// 
			this->groupBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->groupBox->Controls->Add(this->radioButtonThree);
			this->groupBox->Controls->Add(this->radioButtonSecond);
			this->groupBox->Controls->Add(this->radioButtonFirst);
			this->groupBox->Location = System::Drawing::Point(451, 490);
			this->groupBox->Name = L"groupBox";
			this->groupBox->Size = System::Drawing::Size(440, 156);
			this->groupBox->TabIndex = 14;
			this->groupBox->TabStop = false;
			// 
			// radioButtonThree
			// 
			this->radioButtonThree->AutoSize = true;
			this->radioButtonThree->Cursor = System::Windows::Forms::Cursors::Hand;
			this->radioButtonThree->Font = (gcnew System::Drawing::Font(L"Arial", 10.8F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->radioButtonThree->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(57)), static_cast<System::Int32>(static_cast<System::Byte>(53)),
				static_cast<System::Int32>(static_cast<System::Byte>(53)));
			this->radioButtonThree->Location = System::Drawing::Point(21, 108);
			this->radioButtonThree->Name = L"radioButtonThree";
			this->radioButtonThree->Size = System::Drawing::Size(143, 25);
			this->radioButtonThree->TabIndex = 2;
			this->radioButtonThree->TabStop = true;
			this->radioButtonThree->Text = L"radioButton3";
			this->radioButtonThree->UseVisualStyleBackColor = true;
			// 
			// radioButtonSecond
			// 
			this->radioButtonSecond->AutoSize = true;
			this->radioButtonSecond->Cursor = System::Windows::Forms::Cursors::Hand;
			this->radioButtonSecond->Font = (gcnew System::Drawing::Font(L"Arial", 10.8F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->radioButtonSecond->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(57)),
				static_cast<System::Int32>(static_cast<System::Byte>(53)), static_cast<System::Int32>(static_cast<System::Byte>(53)));
			this->radioButtonSecond->Location = System::Drawing::Point(21, 63);
			this->radioButtonSecond->Name = L"radioButtonSecond";
			this->radioButtonSecond->Size = System::Drawing::Size(143, 25);
			this->radioButtonSecond->TabIndex = 1;
			this->radioButtonSecond->TabStop = true;
			this->radioButtonSecond->Text = L"radioButton2";
			this->radioButtonSecond->UseVisualStyleBackColor = true;
			// 
			// radioButtonFirst
			// 
			this->radioButtonFirst->AutoSize = true;
			this->radioButtonFirst->Cursor = System::Windows::Forms::Cursors::Hand;
			this->radioButtonFirst->Font = (gcnew System::Drawing::Font(L"Arial", 10.8F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->radioButtonFirst->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(57)), static_cast<System::Int32>(static_cast<System::Byte>(53)),
				static_cast<System::Int32>(static_cast<System::Byte>(53)));
			this->radioButtonFirst->Location = System::Drawing::Point(21, 22);
			this->radioButtonFirst->Name = L"radioButtonFirst";
			this->radioButtonFirst->Size = System::Drawing::Size(143, 25);
			this->radioButtonFirst->TabIndex = 0;
			this->radioButtonFirst->TabStop = true;
			this->radioButtonFirst->Text = L"radioButton1";
			this->radioButtonFirst->UseVisualStyleBackColor = true;
			// 
			// buttonContinue
			// 
			this->buttonContinue->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->buttonContinue->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(97)), static_cast<System::Int32>(static_cast<System::Byte>(129)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->buttonContinue->Cursor = System::Windows::Forms::Cursors::Hand;
			this->buttonContinue->Font = (gcnew System::Drawing::Font(L"Arial", 9, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->buttonContinue->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->buttonContinue->Location = System::Drawing::Point(456, 678);
			this->buttonContinue->Name = L"buttonContinue";
			this->buttonContinue->Size = System::Drawing::Size(435, 51);
			this->buttonContinue->TabIndex = 15;
			this->buttonContinue->Text = L"Проверить";
			this->buttonContinue->UseVisualStyleBackColor = false;
			this->buttonContinue->Click += gcnew System::EventHandler(this, &TestForm::buttonNext_Click_Check);
			// 
			// buttonPreviousQuestion
			// 
			this->buttonPreviousQuestion->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->buttonPreviousQuestion->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(140)), static_cast<System::Int32>(static_cast<System::Byte>(128)));
			this->buttonPreviousQuestion->Cursor = System::Windows::Forms::Cursors::Hand;
			this->buttonPreviousQuestion->Font = (gcnew System::Drawing::Font(L"Arial", 9, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->buttonPreviousQuestion->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->buttonPreviousQuestion->Location = System::Drawing::Point(456, 744);
			this->buttonPreviousQuestion->Name = L"buttonPreviousQuestion";
			this->buttonPreviousQuestion->Size = System::Drawing::Size(435, 38);
			this->buttonPreviousQuestion->TabIndex = 16;
			this->buttonPreviousQuestion->Text = L"Предыдущий";
			this->buttonPreviousQuestion->UseVisualStyleBackColor = false;
			this->buttonPreviousQuestion->Click += gcnew System::EventHandler(this, &TestForm::buttonPreviousQuestion_Click);
			// 
			// TestForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::Control;
			this->ClientSize = System::Drawing::Size(1319, 855);
			this->Controls->Add(this->buttonPreviousQuestion);
			this->Controls->Add(this->buttonContinue);
			this->Controls->Add(this->groupBox);
			this->Controls->Add(this->flowLayoutPanel2);
			this->Controls->Add(this->flowLayoutPanel1);
			this->Controls->Add(this->labelTitle);
			this->Controls->Add(this->buttonBack);
			this->Controls->Add(this->pictureBox2);
			this->Controls->Add(this->pictureBox1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"TestForm";
			this->Text = L"DUKCountries";
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &TestForm::TestForm_FormClosed);
			this->Load += gcnew System::EventHandler(this, &TestForm::TestForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->EndInit();
			this->flowLayoutPanel1->ResumeLayout(false);
			this->flowLayoutPanel2->ResumeLayout(false);
			this->flowLayoutPanel2->PerformLayout();
			this->groupBox->ResumeLayout(false);
			this->groupBox->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

private: System::Void buttonBack_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Hide();
	previousForm->Show();
}
private: System::Void buttonNext_Click_Check(System::Object^ sender, System::EventArgs^ e) {
	RadioButton^ selectedRadioButton = getSelectedRadioButtonInGroupBox();
	if (selectedRadioButton == nullptr) {
		System::Windows::Forms::MessageBox::Show(
			L"Выберете вариант ответа",
			"Error",
			System::Windows::Forms::MessageBoxButtons::OK,
			System::Windows::Forms::MessageBoxIcon::Error);

		return;
	}
		
	Question^ question = questions[currentQuestionIndex];
	cli::array<CountryData^>^ answers = question->answers;
	CountryData^ correctAnswer = answers[question->correctAnswer];

	int correctAnswerIndex = getRadioButtonIndexInGroupBoxByText(correctAnswer->capital);
	int selectedAnswer = getSelectedRadioButtonIndexInGroupBox();

	question->setSelectedAnswer(selectedAnswer);

	if (correctAnswer->capital->Equals(selectedRadioButton->Text)) 
		correctAnswers++;

	markRightAnswer(correctAnswerIndex);

	this->buttonContinue->Text = L"Далее";

	clearButtonClickEvents(buttonContinue);
	this->buttonContinue->Click += gcnew System::EventHandler(this, &TestForm::buttonNext_Click_Next);
}

private: System::Void buttonNext_Click_Next(System::Object^ sender, System::EventArgs^ e) {
	gotoNextQuestion(1);
}

private: System::Void buttonPreviousQuestion_Click(System::Object^ sender, System::EventArgs^ e) {
	gotoNextQuestion(-1);
}

private: System::Void TestForm_Load(System::Object^ sender, System::EventArgs^ e) {
	prepareQuestions();
}

private: System::Void prepareQuestions() {
	if (questions && !questions->empty())
		questions->clear();

	const char* filename = "data.json";
	questionsManager = gcnew QuestionsManager();

	questions = gcnew cliext::vector<Question^>(questionsManager->getQuestionsList(20, filename));
	currentQuestionIndex = 0;

	displayQuestion(currentQuestionIndex);
}

private: System::Void gotoNextQuestion(int step) {
	if ((!isAnyRadioButtonInGroupBoxSelected()) && (questions[currentQuestionIndex]->selectedAnswer == -1) && (step > 0)) {
		cerr << "No radio button selected" << endl;
		return;
	}
		

	currentQuestionIndex += step;

	if (currentQuestionIndex >= questions->size()) {
		displayResult();
		return;
	}
		
	if (currentQuestionIndex < 0)
		currentQuestionIndex = questions->size() - 1;

	Question^ question = questions[currentQuestionIndex];

	if (question->selectedAnswer != -1) {
		this->buttonContinue->Text = L"Далее";

		clearButtonClickEvents(buttonContinue);
		this->buttonContinue->Click += gcnew System::EventHandler(this, &TestForm::buttonNext_Click_Next);
	}
	else {
		this->buttonContinue->Text = L"Проверить";

		clearButtonClickEvents(buttonContinue);
		this->buttonContinue->Click += gcnew System::EventHandler(this, &TestForm::buttonNext_Click_Check);
	}

	displayQuestion(currentQuestionIndex);
}

private: System::Void displayQuestion(int index) {
	Question^ question = questions[index];

	CountryData^ countryInfo1 = question->answers[0];
	CountryData^ countryInfo2 = question->answers[1];
	CountryData^ countryInfo3 = question->answers[2];

	this->labelQuestion->Text = L"Выберете столицу страны: " + question->answers[question->correctAnswer]->country;

	this->radioButtonFirst->Text = countryInfo1->capital;
	this->radioButtonSecond->Text = countryInfo2->capital;
	this->radioButtonThree->Text = countryInfo3->capital;

	this->radioButtonFirst->Checked = false;
	this->radioButtonSecond->Checked = false;
	this->radioButtonThree->Checked = false;

	labelQuestionNumber->Text = (currentQuestionIndex + 1) + " / " + questions->size();

	if (question->selectedAnswer == -1)
		markAllAnswersDefault();
	else {
		cli::array<CountryData^>^ answers = question->answers;
		CountryData^ correctAnswer = answers[question->correctAnswer];

		int correctAnswerIndex = getRadioButtonIndexInGroupBoxByText(correctAnswer->capital);
		
		if (correctAnswerIndex == -1)
			throw std::runtime_error(StringUtils::convertSystemStringToChars("Failed to find radio button by text: " + correctAnswer->capital));

		markRightAnswer(correctAnswerIndex);

		clearButtonClickEvents(buttonContinue);
		this->buttonContinue->Click += gcnew System::EventHandler(this, &TestForm::buttonNext_Click_Next);
	}
}

private: System::Void displayResult() {
	groupBox->Controls->Clear();
	buttonPreviousQuestion->Hide();

	int mark = (correctAnswers * 5) / questions->size();
	if (mark < 2)
		mark = 2;
	else if (mark > 5)
		mark = 5;

	this->labelMark = (gcnew System::Windows::Forms::Label());
	this->labelMark->AutoSize = true;
	this->labelMark->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
		static_cast<System::Byte>(0)));
	this->labelMark->Location = System::Drawing::Point(-1, 20);
	this->labelMark->Name = L"labelMark";
	this->labelMark->Size = System::Drawing::Size(153, 23);
	this->labelMark->TabIndex = 17;
	this->labelMark->Text = L"Ваша оценка: " + mark;

	groupBox->Controls->Add(this->labelMark);

	labelQuestion->Text = L"Вы ответили правильно на " + correctAnswers + L" из " + questions->size();
	buttonContinue->Text = L"Попробовать заново";

	clearButtonClickEvents(buttonContinue);
	this->buttonContinue->Click += gcnew System::EventHandler(this, &TestForm::tryAgain);

	time_t timestamp = time(NULL);
	struct tm datetime = *localtime(&timestamp);

	char output[16];
	strftime(output, sizeof(output), "%m/%d/%Y", &datetime);

	statisticWriter.addNewResultsData(output, mark, "statistic.json");
}

private: System::Void tryAgain(System::Object^ sender, System::EventArgs^ e) {
	groupBox->Controls->Clear();
	buttonPreviousQuestion->Show();

	this->groupBox->Controls->Add(this->radioButtonThree);
	this->groupBox->Controls->Add(this->radioButtonSecond);
	this->groupBox->Controls->Add(this->radioButtonFirst);

	clearButtonClickEvents(buttonContinue);
	this->buttonContinue->Click += gcnew System::EventHandler(this, &TestForm::buttonNext_Click_Check);

	prepareQuestions();
}

private: System::Void markRightAnswer(int index) {
	for (int i = 0; i < groupBox->Controls->Count; i++) {
		Control^ currentControl = groupBox->Controls[i];
		RadioButton^ radioButton = dynamic_cast<RadioButton^>(currentControl);

		radioButton->ForeColor = i == index ? System::Drawing::Color::Green : System::Drawing::Color::Red;
	}
}

private: System::Void markAllAnswersDefault() {
	for (int i = 0; i < groupBox->Controls->Count; i++) {
		Control^ currentControl = groupBox->Controls[i];
		RadioButton^ radioButton = dynamic_cast<RadioButton^>(currentControl);

		radioButton->ForeColor = System::Drawing::Color::Black;
		radioButton->Checked = false;
	}
}

private: System::Void clearButtonClickEvents(Button^ button) {
	FieldInfo^ eventClickField = Control::typeid->GetField("EventClick",
		static_cast<BindingFlags>(BindingFlags::Static |
			BindingFlags::NonPublic));

	Object^ fieldValue = eventClickField->GetValue(button);
	PropertyInfo^ propertyInfo = button->GetType()->GetProperty("Events",
		BindingFlags::NonPublic | BindingFlags::Instance);

	EventHandlerList^ handlers = dynamic_cast<EventHandlerList^>(propertyInfo->GetValue(button, nullptr));
	handlers->RemoveHandler(fieldValue, handlers[fieldValue]);
}

private: RadioButton^ getSelectedRadioButtonInGroupBox() {
	for (int i = 0; i < groupBox->Controls->Count; i++) {
		Control^ currentControl = groupBox->Controls[i];
		RadioButton^ radioButton = dynamic_cast<RadioButton^>(currentControl);

		if (radioButton->Checked) {
			return radioButton;
		}
	}

	return nullptr;
}

private: int getRadioButtonIndexInGroupBoxByText(System::String^ text) {
	for (int i = 0; i < groupBox->Controls->Count; i++) {
		Control^ currentControl = groupBox->Controls[i];
		RadioButton^ radioButton = dynamic_cast<RadioButton^>(currentControl);

		if (radioButton->Text->Equals(text)) {
			return i;
		}
	}

	return -1;
}

private: int getSelectedRadioButtonIndexInGroupBox() {
	for (int i = 0; i < groupBox->Controls->Count; i++) {
		Control^ currentControl = groupBox->Controls[i];
		RadioButton^ radioButton = dynamic_cast<RadioButton^>(currentControl);

		if (radioButton->Checked) {
			return i;
		}
	}

	return -1;
}

private: bool isAnyRadioButtonInGroupBoxSelected() {
	return getSelectedRadioButtonInGroupBox() != nullptr;
}
private: System::Void TestForm_FormClosed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e) {
	exit(0);
}
};
}
