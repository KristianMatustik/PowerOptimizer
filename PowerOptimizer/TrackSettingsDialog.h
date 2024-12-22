#pragma once

namespace PowerOptimizer {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for TrackSettingsDialog
	/// </summary>
	public ref class TrackSettingsDialog : public System::Windows::Forms::Form
	{
	public:
		TrackSettingsDialog(void)
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
		~TrackSettingsDialog()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel1;
	private: System::Windows::Forms::Label^ label_Crr;
	private: System::Windows::Forms::Label^ label_Density;
	private: System::Windows::Forms::Label^ label_WindSpeed;
	private: System::Windows::Forms::Label^ label_WindBearing;

	public: System::Windows::Forms::NumericUpDown^ numericUpDown_Crr;
	public: System::Windows::Forms::NumericUpDown^ numericUpDown_WindBearing;
	public: System::Windows::Forms::NumericUpDown^ numericUpDown_WindSpeed;
	public: System::Windows::Forms::NumericUpDown^ numericUpDown_Density;

	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel2;
	private: System::Windows::Forms::Button^ button_Cancel;
	private: System::Windows::Forms::Button^ button_OK;


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
			this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->numericUpDown_WindBearing = (gcnew System::Windows::Forms::NumericUpDown());
			this->numericUpDown_WindSpeed = (gcnew System::Windows::Forms::NumericUpDown());
			this->numericUpDown_Density = (gcnew System::Windows::Forms::NumericUpDown());
			this->label_Crr = (gcnew System::Windows::Forms::Label());
			this->label_Density = (gcnew System::Windows::Forms::Label());
			this->numericUpDown_Crr = (gcnew System::Windows::Forms::NumericUpDown());
			this->label_WindBearing = (gcnew System::Windows::Forms::Label());
			this->label_WindSpeed = (gcnew System::Windows::Forms::Label());
			this->button_Cancel = (gcnew System::Windows::Forms::Button());
			this->button_OK = (gcnew System::Windows::Forms::Button());
			this->tableLayoutPanel2 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->tableLayoutPanel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown_WindBearing))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown_WindSpeed))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown_Density))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown_Crr))->BeginInit();
			this->tableLayoutPanel2->SuspendLayout();
			this->SuspendLayout();
			// 
			// tableLayoutPanel1
			// 
			this->tableLayoutPanel1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->tableLayoutPanel1->CellBorderStyle = System::Windows::Forms::TableLayoutPanelCellBorderStyle::Single;
			this->tableLayoutPanel1->ColumnCount = 2;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle()));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle()));
			this->tableLayoutPanel1->Controls->Add(this->numericUpDown_WindBearing, 1, 3);
			this->tableLayoutPanel1->Controls->Add(this->numericUpDown_WindSpeed, 1, 2);
			this->tableLayoutPanel1->Controls->Add(this->numericUpDown_Density, 1, 1);
			this->tableLayoutPanel1->Controls->Add(this->label_Crr, 0, 0);
			this->tableLayoutPanel1->Controls->Add(this->label_Density, 0, 1);
			this->tableLayoutPanel1->Controls->Add(this->numericUpDown_Crr, 1, 0);
			this->tableLayoutPanel1->Controls->Add(this->label_WindBearing, 0, 3);
			this->tableLayoutPanel1->Controls->Add(this->label_WindSpeed, 0, 2);
			this->tableLayoutPanel1->Location = System::Drawing::Point(12, 12);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 4;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 25)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 25)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 25)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 25)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(496, 442);
			this->tableLayoutPanel1->TabIndex = 0;
			// 
			// numericUpDown_WindBearing
			// 
			this->numericUpDown_WindBearing->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
			this->numericUpDown_WindBearing->Location = System::Drawing::Point(128, 376);
			this->numericUpDown_WindBearing->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 359, 0, 0, 0 });
			this->numericUpDown_WindBearing->Name = L"numericUpDown_WindBearing";
			this->numericUpDown_WindBearing->Size = System::Drawing::Size(364, 20);
			this->numericUpDown_WindBearing->TabIndex = 7;
			// 
			// numericUpDown_WindSpeed
			// 
			this->numericUpDown_WindSpeed->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
			this->numericUpDown_WindSpeed->DecimalPlaces = 1;
			this->numericUpDown_WindSpeed->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) { 5, 0, 0, 65536 });
			this->numericUpDown_WindSpeed->Location = System::Drawing::Point(128, 265);
			this->numericUpDown_WindSpeed->Name = L"numericUpDown_WindSpeed";
			this->numericUpDown_WindSpeed->Size = System::Drawing::Size(364, 20);
			this->numericUpDown_WindSpeed->TabIndex = 6;
			// 
			// numericUpDown_Density
			// 
			this->numericUpDown_Density->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
			this->numericUpDown_Density->DecimalPlaces = 3;
			this->numericUpDown_Density->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 196608 });
			this->numericUpDown_Density->Location = System::Drawing::Point(128, 155);
			this->numericUpDown_Density->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 15, 0, 0, 65536 });
			this->numericUpDown_Density->Name = L"numericUpDown_Density";
			this->numericUpDown_Density->Size = System::Drawing::Size(364, 20);
			this->numericUpDown_Density->TabIndex = 5;
			this->numericUpDown_Density->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1225, 0, 0, 196608 });
			// 
			// label_Crr
			// 
			this->label_Crr->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left));
			this->label_Crr->AutoSize = true;
			this->label_Crr->Location = System::Drawing::Point(4, 1);
			this->label_Crr->Name = L"label_Crr";
			this->label_Crr->Size = System::Drawing::Size(20, 109);
			this->label_Crr->TabIndex = 0;
			this->label_Crr->Text = L"Crr";
			this->label_Crr->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label_Density
			// 
			this->label_Density->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left));
			this->label_Density->AutoSize = true;
			this->label_Density->Location = System::Drawing::Point(4, 111);
			this->label_Density->Name = L"label_Density";
			this->label_Density->Size = System::Drawing::Size(101, 109);
			this->label_Density->TabIndex = 1;
			this->label_Density->Text = L"Sea level air density";
			this->label_Density->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// numericUpDown_Crr
			// 
			this->numericUpDown_Crr->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
			this->numericUpDown_Crr->DecimalPlaces = 4;
			this->numericUpDown_Crr->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 262144 });
			this->numericUpDown_Crr->Location = System::Drawing::Point(128, 45);
			this->numericUpDown_Crr->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->numericUpDown_Crr->Name = L"numericUpDown_Crr";
			this->numericUpDown_Crr->Size = System::Drawing::Size(364, 20);
			this->numericUpDown_Crr->TabIndex = 4;
			this->numericUpDown_Crr->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 4, 0, 0, 196608 });
			// 
			// label_WindBearing
			// 
			this->label_WindBearing->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left));
			this->label_WindBearing->AutoSize = true;
			this->label_WindBearing->Location = System::Drawing::Point(4, 331);
			this->label_WindBearing->Name = L"label_WindBearing";
			this->label_WindBearing->Size = System::Drawing::Size(117, 110);
			this->label_WindBearing->TabIndex = 3;
			this->label_WindBearing->Text = L"Wind bearing (° from N)";
			this->label_WindBearing->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label_WindSpeed
			// 
			this->label_WindSpeed->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left));
			this->label_WindSpeed->AutoSize = true;
			this->label_WindSpeed->Location = System::Drawing::Point(4, 221);
			this->label_WindSpeed->Name = L"label_WindSpeed";
			this->label_WindSpeed->Size = System::Drawing::Size(91, 109);
			this->label_WindSpeed->TabIndex = 2;
			this->label_WindSpeed->Text = L"Wind speed (m/s)";
			this->label_WindSpeed->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// button_Cancel
			// 
			this->button_Cancel->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->button_Cancel->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			this->button_Cancel->Location = System::Drawing::Point(251, 3);
			this->button_Cancel->Name = L"button_Cancel";
			this->button_Cancel->Size = System::Drawing::Size(242, 34);
			this->button_Cancel->TabIndex = 1;
			this->button_Cancel->Text = L"Cancel";
			this->button_Cancel->UseVisualStyleBackColor = true;
			// 
			// button_OK
			// 
			this->button_OK->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->button_OK->DialogResult = System::Windows::Forms::DialogResult::OK;
			this->button_OK->Location = System::Drawing::Point(3, 3);
			this->button_OK->Name = L"button_OK";
			this->button_OK->Size = System::Drawing::Size(242, 34);
			this->button_OK->TabIndex = 0;
			this->button_OK->Text = L"OK";
			this->button_OK->UseVisualStyleBackColor = true;
			// 
			// tableLayoutPanel2
			// 
			this->tableLayoutPanel2->ColumnCount = 2;
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel2->Controls->Add(this->button_OK, 0, 0);
			this->tableLayoutPanel2->Controls->Add(this->button_Cancel, 1, 0);
			this->tableLayoutPanel2->Location = System::Drawing::Point(12, 460);
			this->tableLayoutPanel2->Name = L"tableLayoutPanel2";
			this->tableLayoutPanel2->RowCount = 1;
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel2->Size = System::Drawing::Size(496, 40);
			this->tableLayoutPanel2->TabIndex = 2;
			// 
			// TrackSettingsDialog
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(520, 513);
			this->Controls->Add(this->tableLayoutPanel2);
			this->Controls->Add(this->tableLayoutPanel1);
			this->Name = L"TrackSettingsDialog";
			this->Text = L"TrackSettingsDialog";
			this->tableLayoutPanel1->ResumeLayout(false);
			this->tableLayoutPanel1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown_WindBearing))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown_WindSpeed))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown_Density))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown_Crr))->EndInit();
			this->tableLayoutPanel2->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
	};
}
