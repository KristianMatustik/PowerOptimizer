#pragma once

#include "Cyclist.h"
#include <vector>
#include <string>
#include "tinyxml2.h"


class Track
{
	friend class Tester;

private:
	class Point
	{
		friend class Tester;
		friend class Track;
	private:
		double lat, lon;
		double x, y;
		double altitude;
		double rho;
		double crr;
		double maxSpeed;

		double wind_speed;
		double wind_bearing;
		double wind_speed_travel;

		double next_distance;
		double next_bearing;
		double next_slope;

		double power;
		double kineticEnergy;
		double speed;
		double time;
	public:
		Point();
		~Point();
		double update(Point& next, Cyclist rider);
		double time_to_next();
	};

	std::vector<Point> route;


	void calculate_distances();
	void calculate_coordinates();


public:
	Track();
	~Track();
	void loadGPX(std::string filePath);

	void set_crr(double crr);
	void set_wind(double bearing, double speed);
	void set_rho(double seaRho = 1.225);

	void update_time(Cyclist rider, int start=0);

	void initial_solution(Cyclist rider, double power, double v0 = 5);

	void load(std::string filePath);
	void save(std::string filePath);
};