#include "Window.h"
#include "Tester.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
int main(array<String^>^ args)
{
	Track t;
	t.loadGPX("test.gpx");

	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	PowerOptimizer::Window w;
	Application::Run(%w);
}