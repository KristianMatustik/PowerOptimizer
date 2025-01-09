#include "Window.h"
#include "CyclistSettingsDialog.h"
#include "Tester.h"
#include <iostream>
#include "Functions.h"

using namespace System;
using namespace System::Windows::Forms;


[STAThreadAttribute]
int main(array<String^>^ args)
{
	Track t;
	Cyclist c(92, 0.28, 0.4, 500, 0.97, 2, 30, 2.5);
	//Cyclist c(90, 0.22, 0.22, 5000, 0.97, 2, 30, 2.5);
	Tester tst(t, c);
	Optimizer o(&t, &c);

	//t.load_GPX("gpx/test.gpx");
	//t.set_corners(c);

	
	tst.setHill(1000, 0.1, 500);
	//tst.setA(1000, 0.1);
	//tst.setFlat(500);
	//tst.setWind(1000, -5);

	o.solve_AP(360, 600,5);
	//t.save_GPX("gpx/0.gpx");

	//o.solve_CP(300,10000,600,-1,3);
	t.save_GPX("gpx/0.gpx");
	//t.save_GPX("gpx/CP_real.gpx");

	//Track t2;
	//t2.new_copy(&t);
	//o.solve_CP(300,10000,600,5);
	//t.save_GPX("gpx/0-t.gpx");

	//double tim = t.get_total_time();

	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	PowerOptimizer::Window w;
	Application::Run(%w);
}