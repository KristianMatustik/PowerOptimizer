#include "Window.h"
#include <iostream>
#include "Functions.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
int main(array<String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	PowerOptimizer::Window w;
	Application::Run(%w);
}