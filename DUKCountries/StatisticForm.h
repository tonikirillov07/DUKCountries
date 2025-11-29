#pragma once
#include "StatisticReader.h"
#include "StatisticWriter.h"

namespace DUKCountries {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for StatisticForm
	/// </summary>
	public ref class StatisticForm : public System::Windows::Forms::Form
	{

	public:
		StatisticForm(System::Windows::Forms::Form^ previousForm)
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
		~StatisticForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: StatisticReader statisticReader;
	private: StatisticWriter statisticWriter;
	private: System::Windows::Forms::Form^ previousForm;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^ chart;
	private: System::Windows::Forms::Button^ buttonContinue;
	private: System::Windows::Forms::Button^ buttonClearStatistic;

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
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea1 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^ legend1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^ series1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(StatisticForm::typeid));
			this->chart = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->buttonContinue = (gcnew System::Windows::Forms::Button());
			this->buttonClearStatistic = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart))->BeginInit();
			this->SuspendLayout();
			// 
			// chart
			// 
			this->chart->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			chartArea1->AxisY->Maximum = 5;
			chartArea1->AxisY->Minimum = 2;
			chartArea1->Name = L"ChartArea1";
			this->chart->ChartAreas->Add(chartArea1);
			legend1->Name = L"Legend1";
			this->chart->Legends->Add(legend1);
			this->chart->Location = System::Drawing::Point(135, 58);
			this->chart->Name = L"chart";
			series1->ChartArea = L"ChartArea1";
			series1->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Line;
			series1->Font = (gcnew System::Drawing::Font(L"Arial", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			series1->Legend = L"Legend1";
			series1->Name = L"Правильные ответы";
			series1->XValueType = System::Windows::Forms::DataVisualization::Charting::ChartValueType::Date;
			series1->YValueType = System::Windows::Forms::DataVisualization::Charting::ChartValueType::UInt64;
			this->chart->Series->Add(series1);
			this->chart->Size = System::Drawing::Size(1076, 633);
			this->chart->TabIndex = 0;
			this->chart->Text = L"chart";
			// 
			// buttonContinue
			// 
			this->buttonContinue->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->buttonContinue->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(97)), static_cast<System::Int32>(static_cast<System::Byte>(129)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->buttonContinue->Cursor = System::Windows::Forms::Cursors::Hand;
			this->buttonContinue->Font = (gcnew System::Drawing::Font(L"Arial", 9, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->buttonContinue->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->buttonContinue->Location = System::Drawing::Point(438, 783);
			this->buttonContinue->Name = L"buttonContinue";
			this->buttonContinue->Size = System::Drawing::Size(435, 51);
			this->buttonContinue->TabIndex = 16;
			this->buttonContinue->Text = L"Назад";
			this->buttonContinue->UseVisualStyleBackColor = false;
			this->buttonContinue->Click += gcnew System::EventHandler(this, &StatisticForm::buttonContinue_Click);
			// 
			// buttonClearStatistic
			// 
			this->buttonClearStatistic->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->buttonClearStatistic->BackColor = System::Drawing::Color::Red;
			this->buttonClearStatistic->Cursor = System::Windows::Forms::Cursors::Hand;
			this->buttonClearStatistic->Font = (gcnew System::Drawing::Font(L"Arial", 9, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->buttonClearStatistic->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->buttonClearStatistic->Location = System::Drawing::Point(438, 713);
			this->buttonClearStatistic->Name = L"buttonClearStatistic";
			this->buttonClearStatistic->Size = System::Drawing::Size(435, 51);
			this->buttonClearStatistic->TabIndex = 17;
			this->buttonClearStatistic->Text = L"Очистить статистику";
			this->buttonClearStatistic->UseVisualStyleBackColor = false;
			this->buttonClearStatistic->Click += gcnew System::EventHandler(this, &StatisticForm::buttonClearStatistic_Click);
			// 
			// StatisticForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1319, 855);
			this->Controls->Add(this->buttonClearStatistic);
			this->Controls->Add(this->chart);
			this->Controls->Add(this->buttonContinue);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"StatisticForm";
			this->Text = L"DUKCountries";
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &StatisticForm::StatisticForm_FormClosed);
			this->Load += gcnew System::EventHandler(this, &StatisticForm::StatisticForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void StatisticForm_Load(System::Object^ sender, System::EventArgs^ e) {
		System::Windows::Forms::DataVisualization::Charting::Series^ series = this->chart->Series[0];

		cliext::vector<MarkInfo^>^ marks = statisticReader.readAllMarksInfosFromFile("statistic.json");
		for (int i = 0; i < marks->size(); i++) {
			MarkInfo^ markInfo = marks[i];

			series->Points->AddXY(markInfo->getDate(), markInfo->getMark());
		}
	}
private: System::Void buttonClearStatistic_Click(System::Object^ sender, System::EventArgs^ e) {
	System::Windows::Forms::DialogResult result = System::Windows::Forms::MessageBox::Show(
		L"Вы действительно хотите очистить вашу статистику?",
		L"Подтверждение",                               
		System::Windows::Forms::MessageBoxButtons::YesNo,
		System::Windows::Forms::MessageBoxIcon::Question 
	);

	if (result == System::Windows::Forms::DialogResult::Yes) {
		System::Windows::Forms::DataVisualization::Charting::Series^ series = this->chart->Series[0];
		series->Points->Clear();

		statisticWriter.clearStatistics("statistic.json");
	}
}
private: System::Void buttonContinue_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Hide();
	previousForm->Show();
}
private: System::Void StatisticForm_FormClosed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e) {
	exit(0);
}
};
}
