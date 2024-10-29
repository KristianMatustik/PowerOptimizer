#pragma once

#include "Cyclist.h"
#include <functional>


class Track
{
private:
	class Point
	{
		double lat, lon;
		double x, y;
		double altitude;
		double rho;			//air density for aero drag
		double crr;			//rolling resistance coefficient
		double maxSpeed;	//max speed in corners, should not be exceeded

		double wind_bearing;
		double wind_speed;
		double wind_speed_travel;	//wind speed component in direction of the route

		Point* next;
		double next_bearing;
		double next_distance;

		double power;
		double kineticEnergy;
		double speed;
		double time;

	public:
		Point();
		~Point();

		void initialize_GPS(double lat, double lon, double alt=0, double crr=DEFAULT_CRR, double seaRho=DEFAULT_SEA_RHO);
		void initialize_xy(double x, double y, double alt=0, double crr=DEFAULT_CRR, double seaRho=DEFAULT_SEA_RHO);

		double get_lat() const;
		double get_lon() const;
		void set_gps(double lat, double lon);

		double get_x() const;
		double get_y() const;
		void set_xy(double x, double y);

		double get_altitude() const;
		void set_altitude(double alt, double seaRho = DEFAULT_SEA_RHO);

		double get_rho() const;
		void set_rho(double rho);
		void calculate_rho(double seaRho = DEFAULT_SEA_RHO);

		double get_crr() const;
		void set_crr(double crr = DEFAULT_CRR);

		double get_maxSpeed() const;
		void set_maxSpeed(double maxSpeed);

		double get_wind_speed() const;
		double get_wind_bearing() const;
		double get_wind_speed_travel() const;
		void set_wind(double bearing, double speed);

		double get_next_bearing() const;
		double get_next_distance() const;
		double get_next_time() const;
		void set_next(Point* next);

		double get_power() const;
		void set_power(double power);

		double get_time() const;
		double get_speed() const;

		void set_starting_speed(const Cyclist& cyclist, double v0);

		double update_next(const Cyclist& cyclist);
	};

	std::vector<Point> route;

public:
	Track();
	~Track();
	void load_GPX(const std::string& filePath);
	void save_GPX(const std::string& filePath);

	void clear();

	void push_GPS(double lat, double lon, double alt = 0, double crr = DEFAULT_CRR, double seaRho = DEFAULT_SEA_RHO);
	void push_xy(double x, double y, double alt = 0, double crr = DEFAULT_CRR, double seaRho = DEFAULT_SEA_RHO);
	const Point& operator [](int idx);

	void set_connections();
	void set_crr(double crr);
	void set_wind(double bearing, double speed);
	void set_rho(double seaRho = DEFAULT_SEA_RHO);
	void set_corners(const Cyclist& rider);

	void set_power(double P, int i);
	double update_time(const Cyclist& rider, int start=0, int end=-1);
	void initial_solution(const Cyclist& rider, double power, double v0 = 5);

	double averagePower_weighted(std::function<double(double)> f, std::function<double(double)> f_inv) const;
	int size() const;

	void save(std::string filePath) const;
	void load(std::string filePath);
};