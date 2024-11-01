#pragma once

namespace PowerOptimizer
{

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;


	public ref class CyclistSettingsDialog : public System::Windows::Forms::Form
	{
	public:
		CyclistSettingsDialog(void)
		{
			InitializeComponent();
		}

	protected:
		~CyclistSettingsDialog()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel_Setup;
	private: System::Windows::Forms::Label^ label_Mass;
	private: System::Windows::Forms::Label^ label_WheelInertiaMass;
	private: System::Windows::Forms::Label^ label_CdaInTTPosition;
	private: System::Windows::Forms::Label^ label_CdAOutOfSaddle;
	private: System::Windows::Forms::Label^ label_TransitionPower;
	private: System::Windows::Forms::Label^ label_Efficiency;
	private: System::Windows::Forms::Label^ label_BrakingDeceleration;
	private: System::Windows::Forms::Label^ label_TurningBankAngle;

	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel_CdA_yaw;
	private: System::Windows::Forms::Label^ label_YawRange;
	private: System::Windows::Forms::Label^ label_CdA;
	private: System::Windows::Forms::Label^ label_Yaw_0to5;
	private: System::Windows::Forms::Label^ label_Yaw_5to10;
	private: System::Windows::Forms::Label^ label_Yaw_10to15;
	private: System::Windows::Forms::Label^ label_Yaw_15to20;
	private: System::Windows::Forms::Label^ label_Yaw_20up;

	/// 

	public: System::Windows::Forms::NumericUpDown^ numericUpDown_Mass;
	public: System::Windows::Forms::NumericUpDown^ numericUpDown_WheelInertia;

	public: System::Windows::Forms::NumericUpDown^ numericUpDown_Yaw_0to5;
	public: System::Windows::Forms::NumericUpDown^ numericUpDown_Yaw_5to10;
	public: System::Windows::Forms::NumericUpDown^ numericUpDown_Yaw_10to15;
	public: System::Windows::Forms::NumericUpDown^ numericUpDown_Yaw_15to20;
	public: System::Windows::Forms::NumericUpDown^ numericUpDown_Yaw_20up;

	public: System::Windows::Forms::NumericUpDown^ numericUpDown_CdAoos;
	public: System::Windows::Forms::NumericUpDown^ numericUpDown_TransitionPower;
	public: System::Windows::Forms::NumericUpDown^ numericUpDown_Efficiency;
	public: System::Windows::Forms::NumericUpDown^ numericUpDown_BrakingDeceleration;
	public: System::Windows::Forms::NumericUpDown^ numericUpDown_TurningBankAngle;

	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel_Buttons;
	private: System::Windows::Forms::Button^ button_OK;
	private: System::Windows::Forms::Button^ button_Cancel;

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
			this->tableLayoutPanel_Setup = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->numericUpDown_TransitionPower = (gcnew System::Windows::Forms::NumericUpDown());
			this->numericUpDown_CdAoos = (gcnew System::Windows::Forms::NumericUpDown());
			this->numericUpDown_WheelInertia = (gcnew System::Windows::Forms::NumericUpDown());
			this->label_Mass = (gcnew System::Windows::Forms::Label());
			this->label_WheelInertiaMass = (gcnew System::Windows::Forms::Label());
			this->label_TransitionPower = (gcnew System::Windows::Forms::Label());
			this->label_Efficiency = (gcnew System::Windows::Forms::Label());
			this->label_BrakingDeceleration = (gcnew System::Windows::Forms::Label());
			this->label_TurningBankAngle = (gcnew System::Windows::Forms::Label());
			this->label_CdAOutOfSaddle = (gcnew System::Windows::Forms::Label());
			this->numericUpDown_Mass = (gcnew System::Windows::Forms::NumericUpDown());
			this->numericUpDown_Efficiency = (gcnew System::Windows::Forms::NumericUpDown());
			this->numericUpDown_BrakingDeceleration = (gcnew System::Windows::Forms::NumericUpDown());
			this->numericUpDown_TurningBankAngle = (gcnew System::Windows::Forms::NumericUpDown());
			this->label_CdaInTTPosition = (gcnew System::Windows::Forms::Label());
			this->tableLayoutPanel_CdA_yaw = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->numericUpDown_Yaw_20up = (gcnew System::Windows::Forms::NumericUpDown());
			this->numericUpDown_Yaw_15to20 = (gcnew System::Windows::Forms::NumericUpDown());
			this->label_Yaw_15to20 = (gcnew System::Windows::Forms::Label());
			this->label_Yaw_20up = (gcnew System::Windows::Forms::Label());
			this->label_Yaw_0to5 = (gcnew System::Windows::Forms::Label());
			this->label_YawRange = (gcnew System::Windows::Forms::Label());
			this->label_CdA = (gcnew System::Windows::Forms::Label());
			this->label_Yaw_10to15 = (gcnew System::Windows::Forms::Label());
			this->label_Yaw_5to10 = (gcnew System::Windows::Forms::Label());
			this->numericUpDown_Yaw_0to5 = (gcnew System::Windows::Forms::NumericUpDown());
			this->numericUpDown_Yaw_5to10 = (gcnew System::Windows::Forms::NumericUpDown());
			this->numericUpDown_Yaw_10to15 = (gcnew System::Windows::Forms::NumericUpDown());
			this->tableLayoutPanel_Buttons = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->button_Cancel = (gcnew System::Windows::Forms::Button());
			this->button_OK = (gcnew System::Windows::Forms::Button());
			this->tableLayoutPanel_Setup->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown_TransitionPower))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown_CdAoos))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown_WheelInertia))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown_Mass))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown_Efficiency))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown_BrakingDeceleration))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown_TurningBankAngle))->BeginInit();
			this->tableLayoutPanel_CdA_yaw->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown_Yaw_20up))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown_Yaw_15to20))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown_Yaw_0to5))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown_Yaw_5to10))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown_Yaw_10to15))->BeginInit();
			this->tableLayoutPanel_Buttons->SuspendLayout();
			this->SuspendLayout();
			// 
			// tableLayoutPanel_Setup
			// 
			this->tableLayoutPanel_Setup->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->tableLayoutPanel_Setup->CellBorderStyle = System::Windows::Forms::TableLayoutPanelCellBorderStyle::Single;
			this->tableLayoutPanel_Setup->ColumnCount = 2;
			this->tableLayoutPanel_Setup->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle()));
			this->tableLayoutPanel_Setup->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle()));
			this->tableLayoutPanel_Setup->Controls->Add(this->numericUpDown_TransitionPower, 1, 4);
			this->tableLayoutPanel_Setup->Controls->Add(this->numericUpDown_CdAoos, 1, 3);
			this->tableLayoutPanel_Setup->Controls->Add(this->numericUpDown_WheelInertia, 1, 1);
			this->tableLayoutPanel_Setup->Controls->Add(this->label_Mass, 0, 0);
			this->tableLayoutPanel_Setup->Controls->Add(this->label_WheelInertiaMass, 0, 1);
			this->tableLayoutPanel_Setup->Controls->Add(this->label_TransitionPower, 0, 4);
			this->tableLayoutPanel_Setup->Controls->Add(this->label_Efficiency, 0, 5);
			this->tableLayoutPanel_Setup->Controls->Add(this->label_BrakingDeceleration, 0, 6);
			this->tableLayoutPanel_Setup->Controls->Add(this->label_TurningBankAngle, 0, 7);
			this->tableLayoutPanel_Setup->Controls->Add(this->label_CdAOutOfSaddle, 0, 3);
			this->tableLayoutPanel_Setup->Controls->Add(this->numericUpDown_Mass, 1, 0);
			this->tableLayoutPanel_Setup->Controls->Add(this->numericUpDown_Efficiency, 1, 5);
			this->tableLayoutPanel_Setup->Controls->Add(this->numericUpDown_BrakingDeceleration, 1, 6);
			this->tableLayoutPanel_Setup->Controls->Add(this->numericUpDown_TurningBankAngle, 1, 7);
			this->tableLayoutPanel_Setup->Controls->Add(this->label_CdaInTTPosition, 0, 2);
			this->tableLayoutPanel_Setup->Controls->Add(this->tableLayoutPanel_CdA_yaw, 1, 2);
			this->tableLayoutPanel_Setup->Location = System::Drawing::Point(12, 12);
			this->tableLayoutPanel_Setup->Name = L"tableLayoutPanel_Setup";
			this->tableLayoutPanel_Setup->RowCount = 8;
			this->tableLayoutPanel_Setup->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent,
				12.5F)));
			this->tableLayoutPanel_Setup->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent,
				12.5F)));
			this->tableLayoutPanel_Setup->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent,
				12.5F)));
			this->tableLayoutPanel_Setup->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent,
				12.5F)));
			this->tableLayoutPanel_Setup->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent,
				12.5F)));
			this->tableLayoutPanel_Setup->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent,
				12.5F)));
			this->tableLayoutPanel_Setup->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent,
				12.5F)));
			this->tableLayoutPanel_Setup->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent,
				12.5F)));
			this->tableLayoutPanel_Setup->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute,
				20)));
			this->tableLayoutPanel_Setup->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute,
				20)));
			this->tableLayoutPanel_Setup->Size = System::Drawing::Size(660, 490);
			this->tableLayoutPanel_Setup->TabIndex = 3;
			// 
			// numericUpDown_TransitionPower
			// 
			this->numericUpDown_TransitionPower->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
			this->numericUpDown_TransitionPower->AutoSize = true;
			this->numericUpDown_TransitionPower->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) { 50, 0, 0, 0 });
			this->numericUpDown_TransitionPower->Location = System::Drawing::Point(158, 265);
			this->numericUpDown_TransitionPower->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
			this->numericUpDown_TransitionPower->Name = L"numericUpDown_TransitionPower";
			this->numericUpDown_TransitionPower->Size = System::Drawing::Size(498, 20);
			this->numericUpDown_TransitionPower->TabIndex = 15;
			this->numericUpDown_TransitionPower->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 500, 0, 0, 0 });
			// 
			// numericUpDown_CdAoos
			// 
			this->numericUpDown_CdAoos->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
			this->numericUpDown_CdAoos->AutoSize = true;
			this->numericUpDown_CdAoos->DecimalPlaces = 3;
			this->numericUpDown_CdAoos->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 196608 });
			this->numericUpDown_CdAoos->Location = System::Drawing::Point(158, 204);
			this->numericUpDown_CdAoos->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->numericUpDown_CdAoos->Name = L"numericUpDown_CdAoos";
			this->numericUpDown_CdAoos->Size = System::Drawing::Size(498, 20);
			this->numericUpDown_CdAoos->TabIndex = 14;
			this->numericUpDown_CdAoos->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 4, 0, 0, 65536 });
			// 
			// numericUpDown_WheelInertia
			// 
			this->numericUpDown_WheelInertia->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
			this->numericUpDown_WheelInertia->AutoSize = true;
			this->numericUpDown_WheelInertia->DecimalPlaces = 1;
			this->numericUpDown_WheelInertia->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 65536 });
			this->numericUpDown_WheelInertia->Location = System::Drawing::Point(158, 82);
			this->numericUpDown_WheelInertia->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10, 0, 0, 0 });
			this->numericUpDown_WheelInertia->Name = L"numericUpDown_WheelInertia";
			this->numericUpDown_WheelInertia->Size = System::Drawing::Size(498, 20);
			this->numericUpDown_WheelInertia->TabIndex = 13;
			// 
			// label_Mass
			// 
			this->label_Mass->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left));
			this->label_Mass->AutoSize = true;
			this->label_Mass->Location = System::Drawing::Point(4, 1);
			this->label_Mass->Name = L"label_Mass";
			this->label_Mass->Size = System::Drawing::Size(32, 60);
			this->label_Mass->TabIndex = 1;
			this->label_Mass->Text = L"Mass";
			this->label_Mass->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label_WheelInertiaMass
			// 
			this->label_WheelInertiaMass->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left));
			this->label_WheelInertiaMass->AutoSize = true;
			this->label_WheelInertiaMass->Location = System::Drawing::Point(4, 62);
			this->label_WheelInertiaMass->Name = L"label_WheelInertiaMass";
			this->label_WheelInertiaMass->Size = System::Drawing::Size(96, 60);
			this->label_WheelInertiaMass->TabIndex = 2;
			this->label_WheelInertiaMass->Text = L"Wheel inertia mass";
			this->label_WheelInertiaMass->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label_TransitionPower
			// 
			this->label_TransitionPower->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left));
			this->label_TransitionPower->AutoSize = true;
			this->label_TransitionPower->Location = System::Drawing::Point(4, 245);
			this->label_TransitionPower->Name = L"label_TransitionPower";
			this->label_TransitionPower->Size = System::Drawing::Size(147, 60);
			this->label_TransitionPower->TabIndex = 5;
			this->label_TransitionPower->Text = L"Out of saddle transition power";
			this->label_TransitionPower->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label_Efficiency
			// 
			this->label_Efficiency->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left));
			this->label_Efficiency->AutoSize = true;
			this->label_Efficiency->Location = System::Drawing::Point(4, 306);
			this->label_Efficiency->Name = L"label_Efficiency";
			this->label_Efficiency->Size = System::Drawing::Size(53, 60);
			this->label_Efficiency->TabIndex = 6;
			this->label_Efficiency->Text = L"Efficiency";
			this->label_Efficiency->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label_BrakingDeceleration
			// 
			this->label_BrakingDeceleration->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left));
			this->label_BrakingDeceleration->AutoSize = true;
			this->label_BrakingDeceleration->Location = System::Drawing::Point(4, 367);
			this->label_BrakingDeceleration->Name = L"label_BrakingDeceleration";
			this->label_BrakingDeceleration->Size = System::Drawing::Size(104, 60);
			this->label_BrakingDeceleration->TabIndex = 7;
			this->label_BrakingDeceleration->Text = L"Braking deceleration";
			this->label_BrakingDeceleration->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label_TurningBankAngle
			// 
			this->label_TurningBankAngle->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left));
			this->label_TurningBankAngle->AutoSize = true;
			this->label_TurningBankAngle->Location = System::Drawing::Point(4, 428);
			this->label_TurningBankAngle->Name = L"label_TurningBankAngle";
			this->label_TurningBankAngle->Size = System::Drawing::Size(99, 61);
			this->label_TurningBankAngle->TabIndex = 8;
			this->label_TurningBankAngle->Text = L"Turning bank angle";
			this->label_TurningBankAngle->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label_CdAOutOfSaddle
			// 
			this->label_CdAOutOfSaddle->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left));
			this->label_CdAOutOfSaddle->AutoSize = true;
			this->label_CdAOutOfSaddle->Location = System::Drawing::Point(4, 184);
			this->label_CdAOutOfSaddle->Name = L"label_CdAOutOfSaddle";
			this->label_CdAOutOfSaddle->Size = System::Drawing::Size(91, 60);
			this->label_CdAOutOfSaddle->TabIndex = 4;
			this->label_CdAOutOfSaddle->Text = L"CdA out of saddle";
			this->label_CdAOutOfSaddle->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// numericUpDown_Mass
			// 
			this->numericUpDown_Mass->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
			this->numericUpDown_Mass->AutoSize = true;
			this->numericUpDown_Mass->DecimalPlaces = 1;
			this->numericUpDown_Mass->Location = System::Drawing::Point(158, 21);
			this->numericUpDown_Mass->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 200, 0, 0, 0 });
			this->numericUpDown_Mass->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->numericUpDown_Mass->Name = L"numericUpDown_Mass";
			this->numericUpDown_Mass->Size = System::Drawing::Size(498, 20);
			this->numericUpDown_Mass->TabIndex = 12;
			this->numericUpDown_Mass->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 90, 0, 0, 0 });
			// 
			// numericUpDown_Efficiency
			// 
			this->numericUpDown_Efficiency->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
			this->numericUpDown_Efficiency->AutoSize = true;
			this->numericUpDown_Efficiency->DecimalPlaces = 3;
			this->numericUpDown_Efficiency->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) { 5, 0, 0, 196608 });
			this->numericUpDown_Efficiency->Location = System::Drawing::Point(158, 326);
			this->numericUpDown_Efficiency->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->numericUpDown_Efficiency->Name = L"numericUpDown_Efficiency";
			this->numericUpDown_Efficiency->Size = System::Drawing::Size(498, 20);
			this->numericUpDown_Efficiency->TabIndex = 16;
			this->numericUpDown_Efficiency->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 97, 0, 0, 131072 });
			// 
			// numericUpDown_BrakingDeceleration
			// 
			this->numericUpDown_BrakingDeceleration->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
			this->numericUpDown_BrakingDeceleration->AutoSize = true;
			this->numericUpDown_BrakingDeceleration->DecimalPlaces = 1;
			this->numericUpDown_BrakingDeceleration->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 65536 });
			this->numericUpDown_BrakingDeceleration->Location = System::Drawing::Point(158, 387);
			this->numericUpDown_BrakingDeceleration->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->numericUpDown_BrakingDeceleration->Name = L"numericUpDown_BrakingDeceleration";
			this->numericUpDown_BrakingDeceleration->Size = System::Drawing::Size(498, 20);
			this->numericUpDown_BrakingDeceleration->TabIndex = 17;
			this->numericUpDown_BrakingDeceleration->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 2, 0, 0, 0 });
			// 
			// numericUpDown_TurningBankAngle
			// 
			this->numericUpDown_TurningBankAngle->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
			this->numericUpDown_TurningBankAngle->AutoSize = true;
			this->numericUpDown_TurningBankAngle->Location = System::Drawing::Point(158, 448);
			this->numericUpDown_TurningBankAngle->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 90, 0, 0, 0 });
			this->numericUpDown_TurningBankAngle->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->numericUpDown_TurningBankAngle->Name = L"numericUpDown_TurningBankAngle";
			this->numericUpDown_TurningBankAngle->Size = System::Drawing::Size(498, 20);
			this->numericUpDown_TurningBankAngle->TabIndex = 18;
			this->numericUpDown_TurningBankAngle->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 30, 0, 0, 0 });
			// 
			// label_CdaInTTPosition
			// 
			this->label_CdaInTTPosition->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left));
			this->label_CdaInTTPosition->AutoSize = true;
			this->label_CdaInTTPosition->Location = System::Drawing::Point(4, 123);
			this->label_CdaInTTPosition->Name = L"label_CdaInTTPosition";
			this->label_CdaInTTPosition->Size = System::Drawing::Size(94, 60);
			this->label_CdaInTTPosition->TabIndex = 3;
			this->label_CdaInTTPosition->Text = L"CdA in TT position";
			this->label_CdaInTTPosition->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// tableLayoutPanel_CdA_yaw
			// 
			this->tableLayoutPanel_CdA_yaw->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->tableLayoutPanel_CdA_yaw->CellBorderStyle = System::Windows::Forms::TableLayoutPanelCellBorderStyle::Single;
			this->tableLayoutPanel_CdA_yaw->ColumnCount = 6;
			this->tableLayoutPanel_CdA_yaw->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				25)));
			this->tableLayoutPanel_CdA_yaw->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				15)));
			this->tableLayoutPanel_CdA_yaw->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				15)));
			this->tableLayoutPanel_CdA_yaw->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				15)));
			this->tableLayoutPanel_CdA_yaw->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				15)));
			this->tableLayoutPanel_CdA_yaw->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				15)));
			this->tableLayoutPanel_CdA_yaw->Controls->Add(this->numericUpDown_Yaw_20up, 5, 1);
			this->tableLayoutPanel_CdA_yaw->Controls->Add(this->numericUpDown_Yaw_15to20, 4, 1);
			this->tableLayoutPanel_CdA_yaw->Controls->Add(this->label_Yaw_15to20, 4, 0);
			this->tableLayoutPanel_CdA_yaw->Controls->Add(this->label_Yaw_20up, 5, 0);
			this->tableLayoutPanel_CdA_yaw->Controls->Add(this->label_Yaw_0to5, 1, 0);
			this->tableLayoutPanel_CdA_yaw->Controls->Add(this->label_YawRange, 0, 0);
			this->tableLayoutPanel_CdA_yaw->Controls->Add(this->label_CdA, 0, 1);
			this->tableLayoutPanel_CdA_yaw->Controls->Add(this->label_Yaw_10to15, 3, 0);
			this->tableLayoutPanel_CdA_yaw->Controls->Add(this->label_Yaw_5to10, 2, 0);
			this->tableLayoutPanel_CdA_yaw->Controls->Add(this->numericUpDown_Yaw_0to5, 1, 1);
			this->tableLayoutPanel_CdA_yaw->Controls->Add(this->numericUpDown_Yaw_5to10, 2, 1);
			this->tableLayoutPanel_CdA_yaw->Controls->Add(this->numericUpDown_Yaw_10to15, 3, 1);
			this->tableLayoutPanel_CdA_yaw->Location = System::Drawing::Point(158, 126);
			this->tableLayoutPanel_CdA_yaw->Name = L"tableLayoutPanel_CdA_yaw";
			this->tableLayoutPanel_CdA_yaw->RowCount = 2;
			this->tableLayoutPanel_CdA_yaw->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel_CdA_yaw->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel_CdA_yaw->Size = System::Drawing::Size(498, 54);
			this->tableLayoutPanel_CdA_yaw->TabIndex = 11;
			// 
			// numericUpDown_Yaw_20up
			// 
			this->numericUpDown_Yaw_20up->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->numericUpDown_Yaw_20up->DecimalPlaces = 3;
			this->numericUpDown_Yaw_20up->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 196608 });
			this->numericUpDown_Yaw_20up->Location = System::Drawing::Point(426, 30);
			this->numericUpDown_Yaw_20up->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->numericUpDown_Yaw_20up->Name = L"numericUpDown_Yaw_20up";
			this->numericUpDown_Yaw_20up->Size = System::Drawing::Size(64, 20);
			this->numericUpDown_Yaw_20up->TabIndex = 13;
			this->numericUpDown_Yaw_20up->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 2, 0, 0, 65536 });
			// 
			// numericUpDown__Yaw_15to20
			// 
			this->numericUpDown_Yaw_15to20->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->numericUpDown_Yaw_15to20->DecimalPlaces = 3;
			this->numericUpDown_Yaw_15to20->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 196608 });
			this->numericUpDown_Yaw_15to20->Location = System::Drawing::Point(351, 30);
			this->numericUpDown_Yaw_15to20->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->numericUpDown_Yaw_15to20->Name = L"numericUpDown__Yaw_15to20";
			this->numericUpDown_Yaw_15to20->Size = System::Drawing::Size(63, 20);
			this->numericUpDown_Yaw_15to20->TabIndex = 12;
			this->numericUpDown_Yaw_15to20->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 2, 0, 0, 65536 });
			// 
			// label_Yaw_15to20
			// 
			this->label_Yaw_15to20->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->label_Yaw_15to20->AutoSize = true;
			this->label_Yaw_15to20->Location = System::Drawing::Point(349, 1);
			this->label_Yaw_15to20->Name = L"label_Yaw_15to20";
			this->label_Yaw_15to20->Size = System::Drawing::Size(67, 25);
			this->label_Yaw_15to20->TabIndex = 3;
			this->label_Yaw_15to20->Text = L"15-20";
			this->label_Yaw_15to20->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label_Yaw_20up
			// 
			this->label_Yaw_20up->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->label_Yaw_20up->AutoSize = true;
			this->label_Yaw_20up->Location = System::Drawing::Point(423, 1);
			this->label_Yaw_20up->Name = L"label_Yaw_20up";
			this->label_Yaw_20up->Size = System::Drawing::Size(71, 25);
			this->label_Yaw_20up->TabIndex = 4;
			this->label_Yaw_20up->Text = L"20+";
			this->label_Yaw_20up->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label_Yaw_0to5
			// 
			this->label_Yaw_0to5->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->label_Yaw_0to5->AutoSize = true;
			this->label_Yaw_0to5->Location = System::Drawing::Point(127, 1);
			this->label_Yaw_0to5->Name = L"label_Yaw_0to5";
			this->label_Yaw_0to5->Size = System::Drawing::Size(67, 25);
			this->label_Yaw_0to5->TabIndex = 0;
			this->label_Yaw_0to5->Text = L"0-5";
			this->label_Yaw_0to5->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label_YawRange
			// 
			this->label_YawRange->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left));
			this->label_YawRange->AutoSize = true;
			this->label_YawRange->Location = System::Drawing::Point(4, 1);
			this->label_YawRange->Name = L"label_YawRange";
			this->label_YawRange->Size = System::Drawing::Size(58, 25);
			this->label_YawRange->TabIndex = 5;
			this->label_YawRange->Text = L"Yaw range";
			this->label_YawRange->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// label_CdA
			// 
			this->label_CdA->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left));
			this->label_CdA->AutoSize = true;
			this->label_CdA->Location = System::Drawing::Point(4, 27);
			this->label_CdA->Name = L"label_CdA";
			this->label_CdA->Size = System::Drawing::Size(27, 26);
			this->label_CdA->TabIndex = 6;
			this->label_CdA->Text = L"CdA";
			this->label_CdA->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// label_Yaw_10to15
			// 
			this->label_Yaw_10to15->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->label_Yaw_10to15->AutoSize = true;
			this->label_Yaw_10to15->Location = System::Drawing::Point(275, 1);
			this->label_Yaw_10to15->Name = L"label_Yaw_10to15";
			this->label_Yaw_10to15->Size = System::Drawing::Size(67, 25);
			this->label_Yaw_10to15->TabIndex = 2;
			this->label_Yaw_10to15->Text = L"10-15";
			this->label_Yaw_10to15->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label_Yaw_5to10
			// 
			this->label_Yaw_5to10->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->label_Yaw_5to10->AutoSize = true;
			this->label_Yaw_5to10->Location = System::Drawing::Point(201, 1);
			this->label_Yaw_5to10->Name = L"label_Yaw_5to10";
			this->label_Yaw_5to10->Size = System::Drawing::Size(67, 25);
			this->label_Yaw_5to10->TabIndex = 1;
			this->label_Yaw_5to10->Text = L"5-10";
			this->label_Yaw_5to10->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// numericUpDown_Yaw_0to5
			// 
			this->numericUpDown_Yaw_0to5->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->numericUpDown_Yaw_0to5->DecimalPlaces = 3;
			this->numericUpDown_Yaw_0to5->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 196608 });
			this->numericUpDown_Yaw_0to5->Location = System::Drawing::Point(129, 30);
			this->numericUpDown_Yaw_0to5->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->numericUpDown_Yaw_0to5->Name = L"numericUpDown_Yaw_0to5";
			this->numericUpDown_Yaw_0to5->Size = System::Drawing::Size(63, 20);
			this->numericUpDown_Yaw_0to5->TabIndex = 7;
			this->numericUpDown_Yaw_0to5->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 2, 0, 0, 65536 });
			// 
			// numericUpDown_Yaw_5to10
			// 
			this->numericUpDown_Yaw_5to10->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->numericUpDown_Yaw_5to10->DecimalPlaces = 3;
			this->numericUpDown_Yaw_5to10->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 196608 });
			this->numericUpDown_Yaw_5to10->Location = System::Drawing::Point(203, 30);
			this->numericUpDown_Yaw_5to10->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->numericUpDown_Yaw_5to10->Name = L"numericUpDown_Yaw_5to10";
			this->numericUpDown_Yaw_5to10->Size = System::Drawing::Size(63, 20);
			this->numericUpDown_Yaw_5to10->TabIndex = 8;
			this->numericUpDown_Yaw_5to10->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 2, 0, 0, 65536 });
			// 
			// numericUpDown_Yaw_10to15
			// 
			this->numericUpDown_Yaw_10to15->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->numericUpDown_Yaw_10to15->DecimalPlaces = 3;
			this->numericUpDown_Yaw_10to15->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 196608 });
			this->numericUpDown_Yaw_10to15->Location = System::Drawing::Point(277, 30);
			this->numericUpDown_Yaw_10to15->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->numericUpDown_Yaw_10to15->Name = L"numericUpDown_Yaw_10to15";
			this->numericUpDown_Yaw_10to15->Size = System::Drawing::Size(63, 20);
			this->numericUpDown_Yaw_10to15->TabIndex = 9;
			this->numericUpDown_Yaw_10to15->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 2, 0, 0, 65536 });
			// 
			// tableLayoutPanel_Buttons
			// 
			this->tableLayoutPanel_Buttons->ColumnCount = 2;
			this->tableLayoutPanel_Buttons->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel_Buttons->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel_Buttons->Controls->Add(this->button_Cancel, 1, 0);
			this->tableLayoutPanel_Buttons->Controls->Add(this->button_OK, 0, 0);
			this->tableLayoutPanel_Buttons->Location = System::Drawing::Point(12, 508);
			this->tableLayoutPanel_Buttons->Name = L"tableLayoutPanel_Buttons";
			this->tableLayoutPanel_Buttons->RowCount = 1;
			this->tableLayoutPanel_Buttons->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent,
				100)));
			this->tableLayoutPanel_Buttons->Size = System::Drawing::Size(660, 41);
			this->tableLayoutPanel_Buttons->TabIndex = 4;
			// 
			// button_Cancel
			// 
			this->button_Cancel->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->button_Cancel->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			this->button_Cancel->Location = System::Drawing::Point(333, 3);
			this->button_Cancel->Name = L"button_Cancel";
			this->button_Cancel->Size = System::Drawing::Size(324, 35);
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
			this->button_OK->Size = System::Drawing::Size(324, 35);
			this->button_OK->TabIndex = 0;
			this->button_OK->Text = L"OK";
			this->button_OK->UseVisualStyleBackColor = true;
			// 
			// CyclistSettingsDialog
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(684, 561);
			this->Controls->Add(this->tableLayoutPanel_Buttons);
			this->Controls->Add(this->tableLayoutPanel_Setup);
			this->Name = L"CyclistSettingsDialog";
			this->Text = L"CyclistSettingsDialog";
			this->tableLayoutPanel_Setup->ResumeLayout(false);
			this->tableLayoutPanel_Setup->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown_TransitionPower))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown_CdAoos))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown_WheelInertia))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown_Mass))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown_Efficiency))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown_BrakingDeceleration))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown_TurningBankAngle))->EndInit();
			this->tableLayoutPanel_CdA_yaw->ResumeLayout(false);
			this->tableLayoutPanel_CdA_yaw->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown_Yaw_20up))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown_Yaw_15to20))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown_Yaw_0to5))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown_Yaw_5to10))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown_Yaw_10to15))->EndInit();
			this->tableLayoutPanel_Buttons->ResumeLayout(false);
			this->ResumeLayout(false);

		}
	};
}
