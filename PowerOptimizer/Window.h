#pragma once
#include "Optimizer.h"
#include "CyclistSettingsDialog.h"
#include "TrackSettingsDialog.h"
#include <msclr/marshal_cppstd.h>
#include <iostream>

namespace PowerOptimizer
{
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace msclr::interop;

	/// <summary>
	/// Summary for Window
	/// </summary>
	public ref class Window : public System::Windows::Forms::Form
	{
	public:
		Window(void)
		{
			InitializeComponent();
			optimizer = new Optimizer();
			optimizer->cyclist() = new Cyclist();
			optimizer->cyclist()->set_CdA(	std::vector<double>{0.2, 0.2, 0.2, 0.2, 0.2},
											std::vector<double>{5, 10, 15, 20},
											0.4,
											500);
			updateMenuItems();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Window()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

	private: Optimizer* optimizer = nullptr;
	private: int view = 0; //0=map, 1=graph

	private: System::Windows::Forms::ToolStrip^ toolStrip;

	private: System::Windows::Forms::ToolStripDropDownButton^ toolStripDropDownTrack;
	private: System::Windows::Forms::ToolStripDropDownButton^ toolStripDropDownCyclist;
	private: System::Windows::Forms::ToolStripButton^ toolStripButtonModelSetup;
	private: System::Windows::Forms::ToolStripSeparator^ toolStripSeparator1;
	private: System::Windows::Forms::ToolStripButton^ toolStripButtonSolve;
	private: System::Windows::Forms::ToolStripButton^ toolStripButtonCancel;
	private: System::Windows::Forms::ToolStripSeparator^ toolStripSeparator2;
	private: System::Windows::Forms::ToolStripProgressBar^ toolStripProgressBarSolvingState;
	private: System::Windows::Forms::ToolStripDropDownButton^ toolStripDropDownView;

	private: System::Windows::Forms::ToolStripMenuItem^ toolStripMenuTrackLoadGPX;
	private: System::Windows::Forms::ToolStripMenuItem^ toolStripMenuTrackLoadFile;
	private: System::Windows::Forms::ToolStripSeparator^ toolStripSeparator3;
	private: System::Windows::Forms::ToolStripMenuItem^ toolStripMenuTrackSetup;
	private: System::Windows::Forms::ToolStripSeparator^ toolStripSeparator4;
	private: System::Windows::Forms::ToolStripMenuItem^ toolStripMenuTrackSaveGPX;
	private: System::Windows::Forms::ToolStripMenuItem^ toolStripMenuTrackSaveFile;

	private: System::Windows::Forms::ToolStripMenuItem^ toolStripMenuCyclistLoadFile;
	private: System::Windows::Forms::ToolStripSeparator^ toolStripSeparator5;
	private: System::Windows::Forms::ToolStripMenuItem^ toolStripMenuCyclistSetup;
	private: System::Windows::Forms::ToolStripSeparator^ toolStripSeparator6;
	private: System::Windows::Forms::ToolStripMenuItem^ toolStripMenuCyclistSaveFile;

	private: System::Windows::Forms::ToolStripMenuItem^ toolStripMenuViewMap;
	private: System::Windows::Forms::ToolStripMenuItem^ toolStripMenuViewGraph;



	#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Window::typeid));
			this->toolStrip = (gcnew System::Windows::Forms::ToolStrip());
			this->toolStripDropDownTrack = (gcnew System::Windows::Forms::ToolStripDropDownButton());
			this->toolStripMenuTrackLoadGPX = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuTrackLoadFile = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripSeparator3 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->toolStripMenuTrackSetup = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripSeparator4 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->toolStripMenuTrackSaveGPX = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuTrackSaveFile = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripDropDownCyclist = (gcnew System::Windows::Forms::ToolStripDropDownButton());
			this->toolStripMenuCyclistLoadFile = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripSeparator5 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->toolStripMenuCyclistSetup = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripSeparator6 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->toolStripMenuCyclistSaveFile = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripButtonModelSetup = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripSeparator1 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->toolStripButtonSolve = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripButtonCancel = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripSeparator2 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->toolStripProgressBarSolvingState = (gcnew System::Windows::Forms::ToolStripProgressBar());
			this->toolStripDropDownView = (gcnew System::Windows::Forms::ToolStripDropDownButton());
			this->toolStripMenuViewMap = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuViewGraph = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStrip->SuspendLayout();
			this->SuspendLayout();
			// 
			// toolStrip
			// 
			this->toolStrip->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12));
			this->toolStrip->GripStyle = System::Windows::Forms::ToolStripGripStyle::Hidden;
			this->toolStrip->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(9) {
				this->toolStripDropDownTrack,
					this->toolStripDropDownCyclist, this->toolStripButtonModelSetup, this->toolStripSeparator1, this->toolStripButtonSolve, this->toolStripButtonCancel,
					this->toolStripSeparator2, this->toolStripProgressBarSolvingState, this->toolStripDropDownView
			});
			this->toolStrip->Location = System::Drawing::Point(0, 0);
			this->toolStrip->Name = L"toolStrip";
			this->toolStrip->Padding = System::Windows::Forms::Padding(0, 0, 2, 0);
			this->toolStrip->Size = System::Drawing::Size(784, 31);
			this->toolStrip->TabIndex = 0;
			this->toolStrip->Text = L"toolStrip";
			// 
			// toolStripDropDownTrack
			// 
			this->toolStripDropDownTrack->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
			this->toolStripDropDownTrack->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(7) {
				this->toolStripMenuTrackLoadGPX,
					this->toolStripMenuTrackLoadFile, this->toolStripSeparator3, this->toolStripMenuTrackSetup, this->toolStripSeparator4, this->toolStripMenuTrackSaveGPX,
					this->toolStripMenuTrackSaveFile
			});
			this->toolStripDropDownTrack->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripDropDownTrack.Image")));
			this->toolStripDropDownTrack->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripDropDownTrack->Name = L"toolStripDropDownTrack";
			this->toolStripDropDownTrack->Size = System::Drawing::Size(59, 28);
			this->toolStripDropDownTrack->Text = L"Track";
			// 
			// toolStripMenuTrackLoadGPX
			// 
			this->toolStripMenuTrackLoadGPX->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
			this->toolStripMenuTrackLoadGPX->Name = L"toolStripMenuTrackLoadGPX";
			this->toolStripMenuTrackLoadGPX->Size = System::Drawing::Size(147, 26);
			this->toolStripMenuTrackLoadGPX->Text = L"Load GPX";
			this->toolStripMenuTrackLoadGPX->Click += gcnew System::EventHandler(this, &Window::toolStripMenuTrackLoadGPX_Click);
			// 
			// toolStripMenuTrackLoadFile
			// 
			this->toolStripMenuTrackLoadFile->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
			this->toolStripMenuTrackLoadFile->Name = L"toolStripMenuTrackLoadFile";
			this->toolStripMenuTrackLoadFile->Size = System::Drawing::Size(147, 26);
			this->toolStripMenuTrackLoadFile->Text = L"Load file";
			this->toolStripMenuTrackLoadFile->Click += gcnew System::EventHandler(this, &Window::toolStripMenuTrackLoadFile_Click);
			// 
			// toolStripSeparator3
			// 
			this->toolStripSeparator3->Name = L"toolStripSeparator3";
			this->toolStripSeparator3->Size = System::Drawing::Size(144, 6);
			// 
			// toolStripMenuTrackSetup
			// 
			this->toolStripMenuTrackSetup->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
			this->toolStripMenuTrackSetup->Name = L"toolStripMenuTrackSetup";
			this->toolStripMenuTrackSetup->Size = System::Drawing::Size(147, 26);
			this->toolStripMenuTrackSetup->Text = L"Setup";
			this->toolStripMenuTrackSetup->Click += gcnew System::EventHandler(this, &Window::toolStripMenuTrackSetup_Click);
			// 
			// toolStripSeparator4
			// 
			this->toolStripSeparator4->Name = L"toolStripSeparator4";
			this->toolStripSeparator4->Size = System::Drawing::Size(144, 6);
			// 
			// toolStripMenuTrackSaveGPX
			// 
			this->toolStripMenuTrackSaveGPX->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
			this->toolStripMenuTrackSaveGPX->Name = L"toolStripMenuTrackSaveGPX";
			this->toolStripMenuTrackSaveGPX->Size = System::Drawing::Size(147, 26);
			this->toolStripMenuTrackSaveGPX->Text = L"Save GPX";
			this->toolStripMenuTrackSaveGPX->Click += gcnew System::EventHandler(this, &Window::toolStripMenuTrackSaveGPX_Click);
			// 
			// toolStripMenuTrackSaveFile
			// 
			this->toolStripMenuTrackSaveFile->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
			this->toolStripMenuTrackSaveFile->Name = L"toolStripMenuTrackSaveFile";
			this->toolStripMenuTrackSaveFile->Size = System::Drawing::Size(147, 26);
			this->toolStripMenuTrackSaveFile->Text = L"Save file";
			this->toolStripMenuTrackSaveFile->Click += gcnew System::EventHandler(this, &Window::toolStripMenuTrackSaveFile_Click);
			// 
			// toolStripDropDownCyclist
			// 
			this->toolStripDropDownCyclist->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
			this->toolStripDropDownCyclist->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(5) {
				this->toolStripMenuCyclistLoadFile,
					this->toolStripSeparator5, this->toolStripMenuCyclistSetup, this->toolStripSeparator6, this->toolStripMenuCyclistSaveFile
			});
			this->toolStripDropDownCyclist->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripDropDownCyclist.Image")));
			this->toolStripDropDownCyclist->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripDropDownCyclist->Name = L"toolStripDropDownCyclist";
			this->toolStripDropDownCyclist->Size = System::Drawing::Size(68, 28);
			this->toolStripDropDownCyclist->Text = L"Cyclist";
			// 
			// toolStripMenuCyclistLoadFile
			// 
			this->toolStripMenuCyclistLoadFile->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
			this->toolStripMenuCyclistLoadFile->Name = L"toolStripMenuCyclistLoadFile";
			this->toolStripMenuCyclistLoadFile->Size = System::Drawing::Size(139, 26);
			this->toolStripMenuCyclistLoadFile->Text = L"Load file";
			this->toolStripMenuCyclistLoadFile->Click += gcnew System::EventHandler(this, &Window::toolStripMenuCyclistLoadFile_Click);
			// 
			// toolStripSeparator5
			// 
			this->toolStripSeparator5->Name = L"toolStripSeparator5";
			this->toolStripSeparator5->Size = System::Drawing::Size(136, 6);
			// 
			// toolStripMenuCyclistSetup
			// 
			this->toolStripMenuCyclistSetup->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
			this->toolStripMenuCyclistSetup->Name = L"toolStripMenuCyclistSetup";
			this->toolStripMenuCyclistSetup->Size = System::Drawing::Size(139, 26);
			this->toolStripMenuCyclistSetup->Text = L"Setup";
			this->toolStripMenuCyclistSetup->Click += gcnew System::EventHandler(this, &Window::toolStripMenuCyclistSetup_Click);
			// 
			// toolStripSeparator6
			// 
			this->toolStripSeparator6->Name = L"toolStripSeparator6";
			this->toolStripSeparator6->Size = System::Drawing::Size(136, 6);
			// 
			// toolStripMenuCyclistSaveFile
			// 
			this->toolStripMenuCyclistSaveFile->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
			this->toolStripMenuCyclistSaveFile->Name = L"toolStripMenuCyclistSaveFile";
			this->toolStripMenuCyclistSaveFile->Size = System::Drawing::Size(139, 26);
			this->toolStripMenuCyclistSaveFile->Text = L"Save file";
			this->toolStripMenuCyclistSaveFile->Click += gcnew System::EventHandler(this, &Window::toolStripMenuCyclistSaveFile_Click);
			// 
			// toolStripButtonModelSetup
			// 
			this->toolStripButtonModelSetup->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
			this->toolStripButtonModelSetup->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripButtonModelSetup.Image")));
			this->toolStripButtonModelSetup->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripButtonModelSetup->Name = L"toolStripButtonModelSetup";
			this->toolStripButtonModelSetup->Size = System::Drawing::Size(100, 28);
			this->toolStripButtonModelSetup->Text = L"Model setup";
			this->toolStripButtonModelSetup->ToolTipText = L"Model setup";
			this->toolStripButtonModelSetup->Click += gcnew System::EventHandler(this, &Window::toolStripButtonModelSetup_Click);
			// 
			// toolStripSeparator1
			// 
			this->toolStripSeparator1->Name = L"toolStripSeparator1";
			this->toolStripSeparator1->Size = System::Drawing::Size(6, 31);
			// 
			// toolStripButtonSolve
			// 
			this->toolStripButtonSolve->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
			this->toolStripButtonSolve->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripButtonSolve.Image")));
			this->toolStripButtonSolve->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripButtonSolve->Name = L"toolStripButtonSolve";
			this->toolStripButtonSolve->Size = System::Drawing::Size(52, 28);
			this->toolStripButtonSolve->Text = L"Solve";
			this->toolStripButtonSolve->Click += gcnew System::EventHandler(this, &Window::toolStripButtonSolve_Click);
			// 
			// toolStripButtonCancel
			// 
			this->toolStripButtonCancel->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
			this->toolStripButtonCancel->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripButtonCancel.Image")));
			this->toolStripButtonCancel->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripButtonCancel->Name = L"toolStripButtonCancel";
			this->toolStripButtonCancel->Size = System::Drawing::Size(60, 28);
			this->toolStripButtonCancel->Text = L"Cancel";
			this->toolStripButtonCancel->Click += gcnew System::EventHandler(this, &Window::toolStripButtonCancel_Click);
			// 
			// toolStripSeparator2
			// 
			this->toolStripSeparator2->Name = L"toolStripSeparator2";
			this->toolStripSeparator2->Size = System::Drawing::Size(6, 31);
			// 
			// toolStripProgressBarSolvingState
			// 
			this->toolStripProgressBarSolvingState->Name = L"toolStripProgressBarSolvingState";
			this->toolStripProgressBarSolvingState->Size = System::Drawing::Size(117, 28);
			// 
			// toolStripDropDownView
			// 
			this->toolStripDropDownView->Alignment = System::Windows::Forms::ToolStripItemAlignment::Right;
			this->toolStripDropDownView->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->toolStripDropDownView->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
			this->toolStripDropDownView->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->toolStripMenuViewMap,
					this->toolStripMenuViewGraph
			});
			this->toolStripDropDownView->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripDropDownView.Image")));
			this->toolStripDropDownView->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripDropDownView->Name = L"toolStripDropDownView";
			this->toolStripDropDownView->Size = System::Drawing::Size(57, 28);
			this->toolStripDropDownView->Text = L"View";
			// 
			// toolStripMenuViewMap
			// 
			this->toolStripMenuViewMap->Name = L"toolStripMenuViewMap";
			this->toolStripMenuViewMap->Size = System::Drawing::Size(180, 26);
			this->toolStripMenuViewMap->Text = L"Map";
			this->toolStripMenuViewMap->Click += gcnew System::EventHandler(this, &Window::toolStripMenuViewMap_Click);
			// 
			// toolStripMenuViewGraph
			// 
			this->toolStripMenuViewGraph->Name = L"toolStripMenuViewGraph";
			this->toolStripMenuViewGraph->Size = System::Drawing::Size(180, 26);
			this->toolStripMenuViewGraph->Text = L"Graph";
			this->toolStripMenuViewGraph->Click += gcnew System::EventHandler(this, &Window::toolStripMenuViewGraph_Click);
			// 
			// Window
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(7, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(784, 561);
			this->Controls->Add(this->toolStrip);
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9));
			this->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->Name = L"Window";
			this->ShowIcon = false;
			this->Text = L"PowerOptimizer";
			this->toolStrip->ResumeLayout(false);
			this->toolStrip->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
	#pragma endregion

		private: System::Void toolStripMenuTrackLoadGPX_Click(System::Object^ sender, System::EventArgs^ e)
		{
			OpenFileDialog^ openFileDialog = gcnew OpenFileDialog();
			openFileDialog->DefaultExt = "gpx";
			openFileDialog->Filter = "Gpx Files (*.gpx)|*.gpx|All Files (*.*)|*.*";
			openFileDialog->Title = "Open a File";

			if (openFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK)
			{
				String^ filePath = openFileDialog->FileName;
				Track* t = new Track();
				try
				{
					t->load_GPX(marshal_as<std::string>(filePath));
					delete optimizer->track();
					optimizer->track() = t;
					MessageBox::Show("File loaded succesfully", "Info", MessageBoxButtons::OK, MessageBoxIcon::Information);
				}
				catch (const std::exception& e)
				{
					delete t;
					MessageBox::Show("File could not be loaded", "Info", MessageBoxButtons::OK, MessageBoxIcon::Information);
				}
			}
			updateMenuItems();
		}
		private: System::Void toolStripMenuTrackLoadFile_Click(System::Object^ sender, System::EventArgs^ e)
		{
			OpenFileDialog^ openFileDialog = gcnew OpenFileDialog();
			openFileDialog->Filter = "All Files (*.*)|*.*";
			openFileDialog->Title = "Open a File";

			if (openFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK)
			{
				String^ filePath = openFileDialog->FileName;
				Track* t = new Track();
				try
				{
					t->load(marshal_as<std::string>(filePath));
					delete optimizer->track();
					optimizer->track() = t;
					MessageBox::Show("File loaded succesfully", "Info", MessageBoxButtons::OK, MessageBoxIcon::Information);
				}
				catch (const std::exception& e)
				{
					delete t;
					MessageBox::Show("File could not be loaded", "Info", MessageBoxButtons::OK, MessageBoxIcon::Information);
				}
			}
			updateMenuItems();
		}
		private: System::Void toolStripMenuTrackSetup_Click(System::Object^ sender, System::EventArgs^ e)
		{
			PowerOptimizer::TrackSettingsDialog^ dialog = gcnew PowerOptimizer::TrackSettingsDialog();
			try
			{
				dialog->numericUpDown_Crr->Value = (Decimal)(*optimizer->track())[0].get_crr();
				dialog->numericUpDown_Density->Value = (Decimal)optimizer->track()->get_seaRho();
				dialog->numericUpDown_WindSpeed->Value = (Decimal)(*optimizer->track())[0].get_wind_speed();
				dialog->numericUpDown_WindBearing->Value = (Decimal)(*optimizer->track())[0].get_wind_bearing();

				if (dialog->ShowDialog() == System::Windows::Forms::DialogResult::OK)
				{
					optimizer->track()->set_crr((double)dialog->numericUpDown_Crr->Value);
					optimizer->track()->set_wind((double)dialog->numericUpDown_WindBearing->Value, (double)dialog->numericUpDown_WindSpeed->Value);
					optimizer->track()->set_rho((double)dialog->numericUpDown_Density->Value);
				}
			}
			finally
			{
				delete dialog;
			}

			updateMenuItems();
		}
		private: System::Void toolStripMenuTrackSaveGPX_Click(System::Object^ sender, System::EventArgs^ e)
		{
			SaveFileDialog^ saveFileDialog = gcnew SaveFileDialog();
			saveFileDialog->DefaultExt = "gpx";
			saveFileDialog->Filter = "Gpx Files (*.gpx)|*.gpx";
			saveFileDialog->Title = "Save a File";

			if (saveFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK)
			{
				String^ filePath = saveFileDialog->FileName;
				try
				{
					optimizer->track()->save_GPX(marshal_as<std::string>(filePath));
					MessageBox::Show("File saved succesfully", "Info", MessageBoxButtons::OK, MessageBoxIcon::Information);
				}
				catch (const std::exception&)
				{
					MessageBox::Show("File could not be saved", "Info", MessageBoxButtons::OK, MessageBoxIcon::Information);
				}
			}
		}
		private: System::Void toolStripMenuTrackSaveFile_Click(System::Object^ sender, System::EventArgs^ e)
		{
			SaveFileDialog^ saveFileDialog = gcnew SaveFileDialog();
			saveFileDialog->Filter = "All Files (*.*)|*.*";
			saveFileDialog->Title = "Save a File";

			if (saveFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK)
			{
				String^ filePath = saveFileDialog->FileName;
				try
				{
					optimizer->track()->save(marshal_as<std::string>(filePath));
					MessageBox::Show("File saved succesfully", "Info", MessageBoxButtons::OK, MessageBoxIcon::Information);
				}
				catch (const std::exception&)
				{
					MessageBox::Show("File could not be saved", "Info", MessageBoxButtons::OK, MessageBoxIcon::Information);
				}
			}
		}
		private: System::Void toolStripMenuCyclistLoadFile_Click(System::Object^ sender, System::EventArgs^ e)
		{
			OpenFileDialog^ openFileDialog = gcnew OpenFileDialog();
			openFileDialog->Filter = "All Files (*.*)|*.*";
			openFileDialog->Title = "Open a File";

			if (openFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK)
			{
				String^ filePath = openFileDialog->FileName;
				Cyclist* c = new Cyclist();
				try
				{
					c->load(marshal_as<std::string>(filePath));
					delete optimizer->cyclist();
					optimizer->cyclist() = c;
					MessageBox::Show("File loaded succesfully", "Info", MessageBoxButtons::OK, MessageBoxIcon::Information);
				}
				catch (const std::exception& e)
				{
					delete c;
					MessageBox::Show("File could not be loaded", "Info", MessageBoxButtons::OK, MessageBoxIcon::Information);
				}
			}
			updateMenuItems();
		}

		private: System::Void toolStripMenuCyclistSetup_Click(System::Object^ sender, System::EventArgs^ e)
		{
			PowerOptimizer::CyclistSettingsDialog^ dialog = gcnew PowerOptimizer::CyclistSettingsDialog();
			try
			{
				dialog->numericUpDown_Mass->Value = (Decimal)optimizer->cyclist()->get_mass();
				dialog->numericUpDown_WheelInertia->Value = (Decimal)optimizer->cyclist()->get_mass_wheelInertia();
				dialog->numericUpDown_Yaw_0to5->Value = (Decimal)optimizer->cyclist()->get_CdA_TT()[0];
				dialog->numericUpDown_Yaw_5to10->Value = (Decimal)optimizer->cyclist()->get_CdA_TT()[1];
				dialog->numericUpDown_Yaw_10to15->Value = (Decimal)optimizer->cyclist()->get_CdA_TT()[2];
				dialog->numericUpDown_Yaw_15to20->Value = (Decimal)optimizer->cyclist()->get_CdA_TT()[3];
				dialog->numericUpDown_Yaw_20up->Value = (Decimal)optimizer->cyclist()->get_CdA_TT()[4];
				dialog->numericUpDown_CdAoos->Value = (Decimal)optimizer->cyclist()->get_CdAoos();
				dialog->numericUpDown_TransitionPower->Value = (Decimal)optimizer->cyclist()->get_CdAoosPower();
				dialog->numericUpDown_Efficiency->Value = (Decimal)optimizer->cyclist()->get_efficiency();
				dialog->numericUpDown_BrakingDeceleration->Value = (Decimal)optimizer->cyclist()->get_brakingDeceleration();
				dialog->numericUpDown_TurningBankAngle->Value = (Decimal)optimizer->cyclist()->get_turnBankAngle();

				if (dialog->ShowDialog() == System::Windows::Forms::DialogResult::OK)
				{
					optimizer->cyclist()->set_mass((double)dialog->numericUpDown_Mass->Value);
					optimizer->cyclist()->set_mass_wheelInertia((double)dialog->numericUpDown_WheelInertia->Value);
					optimizer->cyclist()->set_CdA(	std::vector<double>		{(double)dialog->numericUpDown_Yaw_0to5->Value,
																			(double)dialog->numericUpDown_Yaw_5to10->Value,
																			(double)dialog->numericUpDown_Yaw_10to15->Value,
																			(double)dialog->numericUpDown_Yaw_15to20->Value,
																			(double)dialog->numericUpDown_Yaw_20up->Value	},
													std::vector<double>{5,10,15,20},
													(double)dialog->numericUpDown_CdAoos->Value,
													(double)dialog->numericUpDown_TransitionPower->Value);
					optimizer->cyclist()->set_efficiency((double)dialog->numericUpDown_Efficiency->Value);
					optimizer->cyclist()->set_brakingDeceleration((double)dialog->numericUpDown_BrakingDeceleration->Value);
					optimizer->cyclist()->set_turnBankAngle((double)dialog->numericUpDown_TurningBankAngle->Value);
				}
			}
			finally
			{
				delete dialog;
			}

			updateMenuItems();
		}

		private: System::Void toolStripMenuCyclistSaveFile_Click(System::Object^ sender, System::EventArgs^ e)
		{
			SaveFileDialog^ saveFileDialog = gcnew SaveFileDialog();
			saveFileDialog->Filter = "All Files (*.*)|*.*";
			saveFileDialog->Title = "Save a File";

			if (saveFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK)
			{
				String^ filePath = saveFileDialog->FileName;
				try
				{
					optimizer->cyclist()->save(marshal_as<std::string>(filePath));
					MessageBox::Show("File saved succesfully", "Info", MessageBoxButtons::OK, MessageBoxIcon::Information);
				}
				catch (const std::exception&)
				{
					MessageBox::Show("File could not be saved", "Info", MessageBoxButtons::OK, MessageBoxIcon::Information);
				}
			}
		}
		private: System::Void toolStripButtonModelSetup_Click(System::Object^ sender, System::EventArgs^ e)
		{

			updateMenuItems();
		}
		private: System::Void toolStripButtonSolve_Click(System::Object^ sender, System::EventArgs^ e)
		{
			//optimizer->solve_AP(500,1000);
			updateMenuItems();
		}
		private: System::Void toolStripButtonCancel_Click(System::Object^ sender, System::EventArgs^ e)
		{

			toolStripProgressBarSolvingState->Value = 0;
			updateMenuItems();
		}
		private: void updateMenuItems()
		{
			bool solving = toolStripProgressBarSolvingState->Value > 0;

			toolStripDropDownTrack->Enabled = !solving;
			toolStripDropDownCyclist->Enabled = !solving;
			toolStripButtonModelSetup->Enabled = !solving;
			toolStripButtonSolve->Enabled = !solving && optimizer->track() && optimizer->cyclist();
			toolStripButtonCancel->Enabled = solving;
			
			toolStripMenuTrackSaveGPX->Enabled = optimizer->track();
			toolStripMenuTrackSaveFile->Enabled = optimizer->track();
			toolStripMenuTrackSetup->Enabled = optimizer->track();
			toolStripMenuCyclistSaveFile->Enabled = optimizer->cyclist();
		}

		private: System::Void toolStripMenuViewMap_Click(System::Object^ sender, System::EventArgs^ e)
		{
			view = 0;
		}
		private: System::Void toolStripMenuViewGraph_Click(System::Object^ sender, System::EventArgs^ e)
		{
			view = 1;
		}

		private: void draw()
		{
			switch (view)
			{
			case 0:
				break;
			case 1:
				break;
			default:
				break;
			}
		}
	};
}
