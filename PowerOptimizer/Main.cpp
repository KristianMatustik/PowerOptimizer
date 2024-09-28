#include "Window.h"
#include <iostream>
#include "Functions.h"
#include "Track.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
int main(array<String^>^ args)
{
	Track t;
	t.test();

	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	PowerOptimizer::Window w;
	Application::Run(%w);
}