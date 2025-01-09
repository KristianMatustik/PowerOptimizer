#pragma once
#define _USE_MATH_DEFINES
#include "Setup.h"
#include <cmath>
#include <utility>
#include <string>


namespace Functions
{
	double energy_kinetic(double mass, double velocity);
	double energy_potential(double mass, double height);
	double force_aero(double rho, double CdA, double velocity);
	double force_roll(double weight, double crr);
	double speed_fromKE(double mass, double kineticEnergy, double inertiaMass = 0);  //inertia mass = I/r^2, wheels
	double bearing(double lat1, double lon1, double lat2, double lon2); // bearing from point lat1 lon1 to lat2 lon2, 0°=N, 90°=E, 180°=S, 270°=W
	double distance(double lat1, double lon1, double lat2, double lon2);
	double yaw(double bearing1, double bearing2); // difference between 2 bearings, -180° to 180°
	std::pair<double, double> addVectors(double bearing1, double magnitude1, double bearing2, double magnitude2); //adds vector with result still in bearing and magnitude
	double circleRadius(double x1, double y1, double x2, double y2, double x3, double y3);  //circumscribed circle of 3 points radius 

	double degToRad(double degrees);
	double radToDeg(double radians);
	double normalizeAngle(double angle);	//any angle in deg norm. to 0-360

	double power_average(double P);			//P
	double power_average_inv(double P);		//P
	double power_normalized(double P);		//P^4
	double power_normalized_inv(double P);	//P^0.25
	std::string time_to_string(double t, const std::string& timeStrBase = "2025-01-01T10:00:00"); //time in double to gpx string format
	double string_to_time(const std::string& timeStr, const std::string& timeStrBase); //time from gpx string format to double seconds
}
