#include "Window.h"
#include "Tester.h"
#include <iostream>
#include "Functions.h"

using namespace System;
using namespace System::Windows::Forms;


[STAThreadAttribute]
int main(array<String^>^ args)
{
	Track t;
	Cyclist c(90, 0.25);
	Optimizer o;

	o.track() = &t;
	o.cyclist() = &c;
	c.save("cyclist_test");

	t.load_GPX("test.gpx");
	t.initial_solution(c, 300);

	Tester tst(t,c);

	//tst.print();
	//o.solve_NP(300);
	//tst.print();

	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	PowerOptimizer::Window w;
	Application::Run(%w);
}