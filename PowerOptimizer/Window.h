#pragma once
#include "Optimizer.h"
#include "CyclistSettingsDialog.h"
#include "TrackSettingsDialog.h"
#include <msclr/marshal_cppstd.h>
#include <iostream>
#include "ModelSettingsDialog.h"
#include <cliext/vector>

namespace PowerOptimizer
{
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace msclr::interop;
	using namespace System::Threading::Tasks;
	using namespace System::Collections::Generic;
	using namespace System;
	using namespace System::Windows::Forms;
	using namespace System::Windows::Forms::DataVisualization::Charting;
	using namespace System::Collections::Generic;


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
	private: int view = 1; //0=map, 1=graph

	private: System::Windows::Forms::ToolStrip^ toolStrip;

	private: System::Windows::Forms::ToolStripDropDownButton^ toolStripDropDownTrack;
	private: System::Windows::Forms::ToolStripDropDownButton^ toolStripDropDownCyclist;

	private: System::Windows::Forms::ToolStripSeparator^ toolStripSeparator1;

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
	private: System::Windows::Forms::ToolStripButton^ toolStripButtonSolve;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^ chart;
	private: System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea1;
	private: System::Windows::Forms::DataVisualization::Charting::Legend^ legend1;
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
			this->toolStripSeparator1 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->toolStripButtonSolve = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripButtonCancel = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripSeparator2 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->toolStripProgressBarSolvingState = (gcnew System::Windows::Forms::ToolStripProgressBar());
			this->toolStripDropDownView = (gcnew System::Windows::Forms::ToolStripDropDownButton());
			this->toolStripMenuViewMap = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripMenuViewGraph = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->chart = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->chartArea1 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			this->legend1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			this->toolStrip->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart))->BeginInit();
			this->SuspendLayout();
			// 
			// toolStrip
			// 
			this->toolStrip->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12));
			this->toolStrip->GripStyle = System::Windows::Forms::ToolStripGripStyle::Hidden;
			this->toolStrip->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(8) {
				this->toolStripDropDownTrack,
					this->toolStripDropDownCyclist, this->toolStripSeparator1, this->toolStripButtonSolve, this->toolStripButtonCancel, this->toolStripSeparator2,
					this->toolStripProgressBarSolvingState, this->toolStripDropDownView
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
			this->toolStripMenuViewMap->Size = System::Drawing::Size(123, 26);
			this->toolStripMenuViewMap->Text = L"Map";
			this->toolStripMenuViewMap->Click += gcnew System::EventHandler(this, &Window::toolStripMenuViewMap_Click);
			// 
			// toolStripMenuViewGraph
			// 
			this->toolStripMenuViewGraph->Name = L"toolStripMenuViewGraph";
			this->toolStripMenuViewGraph->Size = System::Drawing::Size(123, 26);
			this->toolStripMenuViewGraph->Text = L"Graph";
			this->toolStripMenuViewGraph->Click += gcnew System::EventHandler(this, &Window::toolStripMenuViewGraph_Click);
			// 
			// chart
			// 
			this->chart->Dock = System::Windows::Forms::DockStyle::Fill;
			this->chart->Location = System::Drawing::Point(0, 31);
			this->chart->Name = L"chart";
			this->chart->Size = System::Drawing::Size(784, 530);
			this->chart->TabIndex = 1;
			this->chart->Text = L"chart1";
			this->chart->ChartAreas->Add(chartArea1);
			legend1->Font = gcnew System::Drawing::Font("Arial", 12);
			legend1->Docking = Docking::Top;
			legend1->Alignment = StringAlignment::Center;
			this->chart->Legends->Add(legend1);
			// 
			// Window
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(7, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(784, 561);
			this->Controls->Add(this->chart);
			this->Controls->Add(this->toolStrip);
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9));
			this->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->Name = L"Window";
			this->ShowIcon = false;
			this->Text = L"PowerOptimizer";
			this->toolStrip->ResumeLayout(false);
			this->toolStrip->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart))->EndInit();
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
		private: System::Void toolStripButtonSolve_Click(System::Object^ sender, System::EventArgs^ e)
		{
			PowerOptimizer::ModelSettingsDialog^ dialog = gcnew PowerOptimizer::ModelSettingsDialog();
			try
			{
				if (dialog->ShowDialog() == System::Windows::Forms::DialogResult::OK)
				{
					if (dialog->radioButton1->Checked)
					{
						double AP = (double)dialog->numericUpDown_AP->Value;
						double MP = (double)dialog->numericUpDown_AP_max->Value;
						if (MP <= AP)
						{
							MessageBox::Show("Max power can not be lower than average", "Info", MessageBoxButtons::OK, MessageBoxIcon::Information);
							return;
						}
						else
						{
							MessageBox::Show("Please wait while program is looking for solution.", "Info", MessageBoxButtons::OK, MessageBoxIcon::Information);
							optimizer->solve_AP(AP, MP);
						}
					}
					else if (dialog->radioButton2->Checked)
					{
						double NP = (double)dialog->numericUpDown_NP->Value;
						double MP = (double)dialog->numericUpDown_NP_max->Value;
						if (MP <= NP)
						{
							MessageBox::Show("Max power can not be lower than normalized", "Info", MessageBoxButtons::OK, MessageBoxIcon::Information);
							return;
						}
						else
						{
							MessageBox::Show("Please wait while program is looking for solution.", "Info", MessageBoxButtons::OK, MessageBoxIcon::Information);
							optimizer->solve_NP(NP, MP);
						}
					}
					else if (dialog->radioButton3->Checked)
					{
						double CP = (double)dialog->numericUpDown_CP->Value;
						double MP = (double)dialog->numericUpDown_CP_max->Value;
						double W = (double)dialog->numericUpDown_W->Value;
						if (MP <= CP)
						{
							MessageBox::Show("Max power can not be lower than critical", "Info", MessageBoxButtons::OK, MessageBoxIcon::Information);
							return;
						}
						else
						{
							MessageBox::Show("Please wait while program is looking for solution.", "Info", MessageBoxButtons::OK, MessageBoxIcon::Information);
							optimizer->solve_CP(CP, W*1000, MP);
						}
					}
					MessageBox::Show("Solution found, save the track as gpx file.", "Info", MessageBoxButtons::OK, MessageBoxIcon::Information);
				}
			}
			finally
			{
				delete dialog;
			}

			updateMenuItems();
		}
		private: System::Void toolStripButtonCancel_Click(System::Object^ sender, System::EventArgs^ e)
		{
			toolStripProgressBarSolvingState->Value = 0;
			updateMenuItems();
		}
		private: void updateMenuItems()
		{
			toolStripProgressBarSolvingState->Value = optimizer->progress;
			bool solving = toolStripProgressBarSolvingState->Value > 0;

			toolStripDropDownTrack->Enabled = !solving;
			toolStripDropDownCyclist->Enabled = !solving;
			toolStripButtonSolve->Enabled = !solving && optimizer->track() && optimizer->cyclist();
			toolStripButtonCancel->Enabled = solving;
			
			toolStripMenuTrackSaveGPX->Enabled = optimizer->track();
			toolStripMenuTrackSaveFile->Enabled = optimizer->track();
			toolStripMenuTrackSetup->Enabled = optimizer->track();
			toolStripMenuCyclistSaveFile->Enabled = optimizer->cyclist();

			draw();
		}

		private: System::Void toolStripMenuViewMap_Click(System::Object^ sender, System::EventArgs^ e)
		{
			view = 0;
			updateMenuItems();
		}
		private: System::Void toolStripMenuViewGraph_Click(System::Object^ sender, System::EventArgs^ e)
		{
			view = 1;
			updateMenuItems();
		}

		private: void draw()
		{
			switch (view)
			{
			case 0:
				break;
			case 1:
				DisplayChart();
				break;
			default:
				break;
			}
		}

		void DisplayChart()
		{
			if (optimizer->track() == nullptr)
				return;

			chart->Series->Clear();


			List<double>^ xDistance = gcnew List<double>();
			List<double>^ yPower = gcnew List<double>();
			List<double>^ yAltitude = gcnew List<double>();
			List<double>^ ySpeed = gcnew List<double>();

			double maxA = 0;
			double minA = INF;
			double maxP = 0;


			xDistance->Add(0);
			for (int i = 0; i < optimizer->track()->size(); i++)
			{
				double power = optimizer->track()->get_power(i);
				double altitude = optimizer->track()->get_altitude(i);
				double speed = optimizer->track()->get_speed(i);

				if (i != 0)
					xDistance->Add(xDistance[i - 1] + optimizer->track()->get_nextDistance(i - 1));
				yPower->Add(power);
				yAltitude->Add(altitude);
				ySpeed->Add(speed * 3.6);

				maxA = maxA > altitude ? maxA : altitude;
				minA = minA < altitude ? minA : altitude;
				maxP = maxP > power ? maxP : power;
				maxP = maxP > speed ? maxP : speed;
			}

			Series^ series1 = gcnew Series();
			series1->Name = "Power (W)";
			series1->ChartType = SeriesChartType::Line;
			series1->Points->DataBindXY(xDistance, yPower);

			Series^ series2 = gcnew Series();
			series2->Name = "Altitude (m)";
			series2->ChartType = SeriesChartType::Line;
			series2->Points->DataBindXY(xDistance, yAltitude);
			series2->YAxisType = AxisType::Secondary;

			Series^ series3 = gcnew Series();
			series3->Name = "Speed (km/h)";
			series3->ChartType = SeriesChartType::Line;
			series3->Points->DataBindXY(xDistance, ySpeed);

			chart->Series->Add(series1);
			chart->Series->Add(series2);
			chart->Series->Add(series3);

			chart->ChartAreas[0]->AxisX->IsStartedFromZero = true;
			chart->ChartAreas[0]->AxisX->LabelStyle->Format = "{0:0}";
			chart->ChartAreas[0]->AxisX->Title = "Distance (m)";
			chart->ChartAreas[0]->AxisX->Minimum = 0;

			chart->ChartAreas[0]->AxisY->LabelStyle->Format = "{0:0}";
			chart->ChartAreas[0]->AxisY->Title = "Power/Speed";
			chart->ChartAreas[0]->AxisY->Minimum = 0;
			chart->ChartAreas[0]->AxisY->Maximum = 1.05 * maxP;
			chart->ChartAreas[0]->AxisY->Interval = 50;

			chart->ChartAreas[0]->AxisY2->LabelStyle->Format = "{0:0}";
			chart->ChartAreas[0]->AxisY2->Title = "Altitude";
			chart->ChartAreas[0]->AxisY2->Minimum = 50 * std::floor(0.95 * minA / 50);
			chart->ChartAreas[0]->AxisY2->Maximum = 1.05 * maxA;
			chart->ChartAreas[0]->AxisY2->Interval = 50;
			chart->ChartAreas[0]->AxisY2->MajorGrid->LineColor = System::Drawing::Color::LightGray;

			chart->ChartAreas[0]->AxisX->TitleFont = gcnew System::Drawing::Font("Arial", 14, System::Drawing::FontStyle::Bold);
			chart->ChartAreas[0]->AxisY->TitleFont = gcnew System::Drawing::Font("Arial", 14, System::Drawing::FontStyle::Bold);
			chart->ChartAreas[0]->AxisY2->TitleFont = gcnew System::Drawing::Font("Arial", 14, System::Drawing::FontStyle::Bold);

			chart->ChartAreas[0]->AxisX->LabelStyle->Font = gcnew System::Drawing::Font("Arial", 12);
			chart->ChartAreas[0]->AxisY->LabelStyle->Font = gcnew System::Drawing::Font("Arial", 12);
			chart->ChartAreas[0]->AxisY2->LabelStyle->Font = gcnew System::Drawing::Font("Arial", 12);

			series1->BorderWidth = 2;
			series2->BorderWidth = 2;
			series3->BorderWidth = 2;
		}

	};
}
