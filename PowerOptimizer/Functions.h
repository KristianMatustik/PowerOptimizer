#pragma once
#include "Setup.h"
#include <cmath>
#ifndef M_PI
	#define M_PI 3.14159265358979323846
#endif


namespace PowerOptimizer
{
	namespace Functions
	{
		double energy_kinetic(double mass, double velocity);
		double energy_potential(double mass, double height);
		double force_aero(double rho, double CdA, double velocity);
		double force_roll(double weight, double crr);
		double velocity(double mass, double kineticEnergy, double inertia = 0);  //inertia mass = I/r^2, wheels
		double bearing(double lat1, double lon1, double lat2, double lon2);
		double yaw(double bearing1, double bearing2);
		double circle_radius(double x1, double y1, double x2, double y2, double x3, double y3);
	}
}