#pragma once

namespace PowerOptimizer {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for ModelSettingsDialog
	/// </summary>
	public ref class ModelSettingsDialog : public System::Windows::Forms::Form
	{
	public:
		ModelSettingsDialog(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~ModelSettingsDialog()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button_Cancel;
	private: System::Windows::Forms::Button^ button_OK;
	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel1;
	public: System::Windows::Forms::RadioButton^ radioButton1;
	public: System::Windows::Forms::RadioButton^ radioButton2;
	public: System::Windows::Forms::RadioButton^ radioButton3;
	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel2;
	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel4;
	public: System::Windows::Forms::NumericUpDown^ numericUpDown_W;


	public: System::Windows::Forms::NumericUpDown^ numericUpDown_CP;

	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel3;
	public: System::Windows::Forms::NumericUpDown^ numericUpDown_NP_max;

	public: System::Windows::Forms::NumericUpDown^ numericUpDown_NP;

	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	public: System::Windows::Forms::NumericUpDown^ numericUpDown_AP_max;


	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	public: System::Windows::Forms::NumericUpDown^ numericUpDown_AP;
	public: System::Windows::Forms::NumericUpDown^ numericUpDown_CP_max;




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
			this->button_Cancel = (gcnew System::Windows::Forms::Button());
			this->button_OK = (gcnew System::Windows::Forms::Button());
			this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->tableLayoutPanel4 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->numericUpDown_CP_max = (gcnew System::Windows::Forms::NumericUpDown());
			this->numericUpDown_W = (gcnew System::Windows::Forms::NumericUpDown());
			this->numericUpDown_CP = (gcnew System::Windows::Forms::NumericUpDown());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->tableLayoutPanel3 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->numericUpDown_NP_max = (gcnew System::Windows::Forms::NumericUpDown());
			this->numericUpDown_NP = (gcnew System::Windows::Forms::NumericUpDown());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->radioButton1 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton2 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton3 = (gcnew System::Windows::Forms::RadioButton());
			this->tableLayoutPanel2 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->numericUpDown_AP_max = (gcnew System::Windows::Forms::NumericUpDown());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->numericUpDown_AP = (gcnew System::Windows::Forms::NumericUpDown());
			this->tableLayoutPanel1->SuspendLayout();
			this->tableLayoutPanel4->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown_CP_max))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown_W))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown_CP))->BeginInit();
			this->tableLayoutPanel3->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown_NP_max))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown_NP))->BeginInit();
			this->tableLayoutPanel2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown_AP_max))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown_AP))->BeginInit();
			this->SuspendLayout();
			// 
			// button_Cancel
			// 
			this->button_Cancel->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->button_Cancel->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			this->button_Cancel->Location = System::Drawing::Point(236, 312);
			this->button_Cancel->Name = L"button_Cancel";
			this->button_Cancel->Size = System::Drawing::Size(219, 43);
			this->button_Cancel->TabIndex = 3;
			this->button_Cancel->Text = L"Cancel";
			this->button_Cancel->UseVisualStyleBackColor = true;
			// 
			// button_OK
			// 
			this->button_OK->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->button_OK->DialogResult = System::Windows::Forms::DialogResult::OK;
			this->button_OK->Location = System::Drawing::Point(12, 312);
			this->button_OK->Name = L"button_OK";
			this->button_OK->Size = System::Drawing::Size(219, 43);
			this->button_OK->TabIndex = 2;
			this->button_OK->Text = L"Solve";
			this->button_OK->UseVisualStyleBackColor = true;
			// 
			// tableLayoutPanel1
			// 
			this->tableLayoutPanel1->CellBorderStyle = System::Windows::Forms::TableLayoutPanelCellBorderStyle::Single;
			this->tableLayoutPanel1->ColumnCount = 2;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				35.82888F)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				64.17112F)));
			this->tableLayoutPanel1->Controls->Add(this->tableLayoutPanel4, 1, 2);
			this->tableLayoutPanel1->Controls->Add(this->tableLayoutPanel3, 1, 1);
			this->tableLayoutPanel1->Controls->Add(this->radioButton1, 0, 0);
			this->tableLayoutPanel1->Controls->Add(this->radioButton2, 0, 1);
			this->tableLayoutPanel1->Controls->Add(this->radioButton3, 0, 2);
			this->tableLayoutPanel1->Controls->Add(this->tableLayoutPanel2, 1, 0);
			this->tableLayoutPanel1->Location = System::Drawing::Point(12, 12);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 3;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 33.34F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 33.33F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 33.33F)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(443, 294);
			this->tableLayoutPanel1->TabIndex = 4;
			// 
			// tableLayoutPanel4
			// 
			this->tableLayoutPanel4->ColumnCount = 2;
			this->tableLayoutPanel4->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel4->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel4->Controls->Add(this->numericUpDown_CP_max, 1, 2);
			this->tableLayoutPanel4->Controls->Add(this->numericUpDown_W, 1, 1);
			this->tableLayoutPanel4->Controls->Add(this->numericUpDown_CP, 1, 0);
			this->tableLayoutPanel4->Controls->Add(this->label5, 0, 0);
			this->tableLayoutPanel4->Controls->Add(this->label6, 0, 1);
			this->tableLayoutPanel4->Controls->Add(this->label7, 0, 2);
			this->tableLayoutPanel4->Location = System::Drawing::Point(162, 198);
			this->tableLayoutPanel4->Name = L"tableLayoutPanel4";
			this->tableLayoutPanel4->RowCount = 3;
			this->tableLayoutPanel4->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 33.34F)));
			this->tableLayoutPanel4->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 33.33F)));
			this->tableLayoutPanel4->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 33.33F)));
			this->tableLayoutPanel4->Size = System::Drawing::Size(277, 92);
			this->tableLayoutPanel4->TabIndex = 4;
			// 
			// numericUpDown_CP_max
			// 
			this->numericUpDown_CP_max->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->numericUpDown_CP_max->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) { 50, 0, 0, 0 });
			this->numericUpDown_CP_max->Location = System::Drawing::Point(141, 66);
			this->numericUpDown_CP_max->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 3000, 0, 0, 0 });
			this->numericUpDown_CP_max->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 200, 0, 0, 0 });
			this->numericUpDown_CP_max->Name = L"numericUpDown_CP_max";
			this->numericUpDown_CP_max->Size = System::Drawing::Size(120, 20);
			this->numericUpDown_CP_max->TabIndex = 9;
			this->numericUpDown_CP_max->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 600, 0, 0, 0 });
			// 
			// numericUpDown_W
			// 
			this->numericUpDown_W->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->numericUpDown_W->DecimalPlaces = 1;
			this->numericUpDown_W->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) { 5, 0, 0, 65536 });
			this->numericUpDown_W->Location = System::Drawing::Point(141, 35);
			this->numericUpDown_W->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 60, 0, 0, 0 });
			this->numericUpDown_W->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->numericUpDown_W->Name = L"numericUpDown_W";
			this->numericUpDown_W->Size = System::Drawing::Size(120, 20);
			this->numericUpDown_W->TabIndex = 8;
			this->numericUpDown_W->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 20, 0, 0, 0 });
			// 
			// numericUpDown_CP
			// 
			this->numericUpDown_CP->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->numericUpDown_CP->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10, 0, 0, 0 });
			this->numericUpDown_CP->Location = System::Drawing::Point(141, 5);
			this->numericUpDown_CP->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 500, 0, 0, 0 });
			this->numericUpDown_CP->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 100, 0, 0, 0 });
			this->numericUpDown_CP->Name = L"numericUpDown_CP";
			this->numericUpDown_CP->Size = System::Drawing::Size(120, 20);
			this->numericUpDown_CP->TabIndex = 7;
			this->numericUpDown_CP->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 300, 0, 0, 0 });
			// 
			// label5
			// 
			this->label5->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left));
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(3, 0);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(90, 30);
			this->label5->TabIndex = 4;
			this->label5->Text = L"Critical power (W)";
			this->label5->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// label6
			// 
			this->label6->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left));
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(3, 30);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(83, 30);
			this->label6->TabIndex = 5;
			this->label6->Text = L"W\' capacity (kJ)";
			this->label6->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// label7
			// 
			this->label7->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left));
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(3, 60);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(97, 32);
			this->label7->TabIndex = 6;
			this->label7->Text = L"Maximal power (W)";
			this->label7->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// tableLayoutPanel3
			// 
			this->tableLayoutPanel3->ColumnCount = 2;
			this->tableLayoutPanel3->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel3->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel3->Controls->Add(this->numericUpDown_NP_max, 1, 1);
			this->tableLayoutPanel3->Controls->Add(this->numericUpDown_NP, 1, 0);
			this->tableLayoutPanel3->Controls->Add(this->label3, 0, 0);
			this->tableLayoutPanel3->Controls->Add(this->label4, 0, 1);
			this->tableLayoutPanel3->Location = System::Drawing::Point(162, 101);
			this->tableLayoutPanel3->Name = L"tableLayoutPanel3";
			this->tableLayoutPanel3->RowCount = 2;
			this->tableLayoutPanel3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel3->Size = System::Drawing::Size(277, 90);
			this->tableLayoutPanel3->TabIndex = 4;
			// 
			// numericUpDown_NP_max
			// 
			this->numericUpDown_NP_max->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->numericUpDown_NP_max->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) { 50, 0, 0, 0 });
			this->numericUpDown_NP_max->Location = System::Drawing::Point(141, 57);
			this->numericUpDown_NP_max->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 3000, 0, 0, 0 });
			this->numericUpDown_NP_max->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 200, 0, 0, 0 });
			this->numericUpDown_NP_max->Name = L"numericUpDown_NP_max";
			this->numericUpDown_NP_max->Size = System::Drawing::Size(120, 20);
			this->numericUpDown_NP_max->TabIndex = 5;
			this->numericUpDown_NP_max->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 600, 0, 0, 0 });
			// 
			// numericUpDown_NP
			// 
			this->numericUpDown_NP->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->numericUpDown_NP->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10, 0, 0, 0 });
			this->numericUpDown_NP->Location = System::Drawing::Point(141, 12);
			this->numericUpDown_NP->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 2000, 0, 0, 0 });
			this->numericUpDown_NP->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 100, 0, 0, 0 });
			this->numericUpDown_NP->Name = L"numericUpDown_NP";
			this->numericUpDown_NP->Size = System::Drawing::Size(120, 20);
			this->numericUpDown_NP->TabIndex = 4;
			this->numericUpDown_NP->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 300, 0, 0, 0 });
			// 
			// label3
			// 
			this->label3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left));
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(3, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(111, 45);
			this->label3->TabIndex = 2;
			this->label3->Text = L"Normalized power (W)";
			this->label3->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// label4
			// 
			this->label4->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left));
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(3, 45);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(97, 45);
			this->label4->TabIndex = 3;
			this->label4->Text = L"Maximal power (W)";
			this->label4->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// radioButton1
			// 
			this->radioButton1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left));
			this->radioButton1->AutoSize = true;
			this->radioButton1->Checked = true;
			this->radioButton1->Location = System::Drawing::Point(4, 4);
			this->radioButton1->Name = L"radioButton1";
			this->radioButton1->Size = System::Drawing::Size(97, 90);
			this->radioButton1->TabIndex = 0;
			this->radioButton1->TabStop = true;
			this->radioButton1->Text = L"Average power";
			this->radioButton1->UseVisualStyleBackColor = true;
			// 
			// radioButton2
			// 
			this->radioButton2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left));
			this->radioButton2->AutoSize = true;
			this->radioButton2->Location = System::Drawing::Point(4, 101);
			this->radioButton2->Name = L"radioButton2";
			this->radioButton2->Size = System::Drawing::Size(109, 90);
			this->radioButton2->TabIndex = 1;
			this->radioButton2->Text = L"Normalized power";
			this->radioButton2->UseVisualStyleBackColor = true;
			// 
			// radioButton3
			// 
			this->radioButton3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left));
			this->radioButton3->AutoSize = true;
			this->radioButton3->Location = System::Drawing::Point(4, 198);
			this->radioButton3->Name = L"radioButton3";
			this->radioButton3->Size = System::Drawing::Size(88, 92);
			this->radioButton3->TabIndex = 2;
			this->radioButton3->Text = L"Critical power";
			this->radioButton3->UseVisualStyleBackColor = true;
			// 
			// tableLayoutPanel2
			// 
			this->tableLayoutPanel2->ColumnCount = 2;
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel2->Controls->Add(this->numericUpDown_AP_max, 1, 1);
			this->tableLayoutPanel2->Controls->Add(this->label1, 0, 0);
			this->tableLayoutPanel2->Controls->Add(this->label2, 0, 1);
			this->tableLayoutPanel2->Controls->Add(this->numericUpDown_AP, 1, 0);
			this->tableLayoutPanel2->Location = System::Drawing::Point(162, 4);
			this->tableLayoutPanel2->Name = L"tableLayoutPanel2";
			this->tableLayoutPanel2->RowCount = 2;
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel2->Size = System::Drawing::Size(277, 90);
			this->tableLayoutPanel2->TabIndex = 3;
			// 
			// numericUpDown_AP_max
			// 
			this->numericUpDown_AP_max->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->numericUpDown_AP_max->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) { 50, 0, 0, 0 });
			this->numericUpDown_AP_max->Location = System::Drawing::Point(141, 57);
			this->numericUpDown_AP_max->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 3000, 0, 0, 0 });
			this->numericUpDown_AP_max->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 200, 0, 0, 0 });
			this->numericUpDown_AP_max->Name = L"numericUpDown_AP_max";
			this->numericUpDown_AP_max->Size = System::Drawing::Size(120, 20);
			this->numericUpDown_AP_max->TabIndex = 3;
			this->numericUpDown_AP_max->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 600, 0, 0, 0 });
			// 
			// label1
			// 
			this->label1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left));
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(3, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(99, 45);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Average power (W)";
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// label2
			// 
			this->label2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left));
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(3, 45);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(97, 45);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Maximal power (W)";
			this->label2->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// numericUpDown_AP
			// 
			this->numericUpDown_AP->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->numericUpDown_AP->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10, 0, 0, 0 });
			this->numericUpDown_AP->Location = System::Drawing::Point(141, 12);
			this->numericUpDown_AP->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 2000, 0, 0, 0 });
			this->numericUpDown_AP->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 100, 0, 0, 0 });
			this->numericUpDown_AP->Name = L"numericUpDown_AP";
			this->numericUpDown_AP->Size = System::Drawing::Size(120, 20);
			this->numericUpDown_AP->TabIndex = 2;
			this->numericUpDown_AP->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 300, 0, 0, 0 });
			// 
			// ModelSettingsDialog
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(467, 367);
			this->Controls->Add(this->tableLayoutPanel1);
			this->Controls->Add(this->button_Cancel);
			this->Controls->Add(this->button_OK);
			this->Name = L"ModelSettingsDialog";
			this->Text = L"ModelSettingsDialog";
			this->tableLayoutPanel1->ResumeLayout(false);
			this->tableLayoutPanel1->PerformLayout();
			this->tableLayoutPanel4->ResumeLayout(false);
			this->tableLayoutPanel4->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown_CP_max))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown_W))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown_CP))->EndInit();
			this->tableLayoutPanel3->ResumeLayout(false);
			this->tableLayoutPanel3->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown_NP_max))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown_NP))->EndInit();
			this->tableLayoutPanel2->ResumeLayout(false);
			this->tableLayoutPanel2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown_AP_max))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown_AP))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	};
}
