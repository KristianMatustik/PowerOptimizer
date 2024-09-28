#pragma once
#define _USE_MATH_DEFINES
#include "Setup.h"
#include <cmath>
#include <utility>


namespace Functions
{
	double energy_kinetic(double mass, double velocity);
	double energy_potential(double mass, double height);
	double force_aero(double rho, double CdA, double velocity);
	double force_roll(double weight, double crr);
	double speed_fromKE(double mass, double kineticEnergy, double inertia = 0);  //inertia mass = I/r^2, wheels
	double bearing(double lat1, double lon1, double lat2, double lon2);
	double distance(double lat1, double lon1, double lat2, double lon2);
	double yaw(double bearing1, double bearing2);
	std::pair<double, double> addVectors(double bearing1, double magnitude1, double bearing2, double magnitude2);
	double circleRadius(double x1, double y1, double x2, double y2, double x3, double y3);

	double degToRad(double degrees);
	double radToDeg(double radians);
	double normalizeAngle(double angle);
}
