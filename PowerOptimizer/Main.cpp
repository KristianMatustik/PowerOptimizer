#include "Window.h"
#include "CyclistSettingsDialog.h"
#include "Tester.h"
#include <iostream>
#include "Functions.h"

using namespace System;
using namespace System::Windows::Forms;


[STAThread]
void Main(array<String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	PowerOptimizer::Window w;
	Application::Run(%w);
}