#pragma once

#include "Cyclist.h"
#include <functional>
#include <list>


class Track
{
private:
	class Point
	{
		double lat, lon;	//geo coords
		double x, y;		//artifical coords (m), used for triangulation for corner speed
		double altitude;	//alt (m) above sea
		double rho;			//air density for aero drag
		double crr;			//rolling resistance coefficient
		double maxSpeed;	//max speed in corners (m/s), should not be exceeded 

		double wind_bearing;		//overall wind bearing
		double wind_speed;			//overall wind speed
		double wind_speed_travel;	//wind speed component in direction of the route

		Point* next;
		double next_bearing;
		double next_distance;

		double power;			//power until the next point
		double kineticEnergy;
		double speed;			//in m/s
		double time;			//time from start

		double Wbal;	//used only in debugging for CP model to save and display Wbal

	public:
		Point();
		~Point();

		void initialize_GPS(double lat, double lon, double alt=0, double crr=CRR, double seaRho=SEA_RHO);
		void initialize_xy(double x, double y, double alt=0, double crr=CRR, double seaRho=SEA_RHO);

		double get_lat() const;
		double get_lon() const;
		void set_gps(double lat, double lon);

		double get_x() const;
		double get_y() const;
		void set_xy(double x, double y);

		double get_altitude() const;
		void set_altitude(double alt, double seaRho = SEA_RHO);

		double get_rho() const;
		void set_rho(double rho);
		void calculate_rho(double seaRho = SEA_RHO); //estimated rho by exponential formula

		double get_crr() const;
		void set_crr(double crr = CRR);

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
		void set_time(double time);

		double get_speed() const;
		void set_speed(double speed);

		double get_slope() const;

		void set_starting_speed(const Cyclist& cyclist, double v0);

		double update_next(const Cyclist& cyclist); //main method, updates speed in next point based on the power and cyclists parameters

		double get_wbal() const;
		void set_wbal(double w);
	};
public:
	std::vector<Point> route;
	double seaRho_global = SEA_RHO;

public:
	Track();
	~Track();
	void load_GPX(const std::string& filePath);
	void save_GPX(const std::string& filePath);

	void clear();

	void push_gps(double lat, double lon, double alt = 0, double crr = CRR, double seaRho = SEA_RHO);
	void push_xy(double x, double y, double alt = 0, double crr = CRR, double seaRho = SEA_RHO);
	const Point& operator [](int idx);

	void set_connections_gps();	 //sets the distances etc. between points
	void set_connections_xy();

	void set_crr(double crr);	//these methods set parameters for the whole track
	void set_wind(double bearing, double speed);
	void set_rho(double seaRho = SEA_RHO);
	void set_corners(const Cyclist& rider); //calculates max speed of all points based on corners
	std::list<double> find_corners();			//one method gets indexes, the other speed limits - simplify later
	std::list<double> find_corners_speed();
	void set_final_speed(Cyclist* c, double v);
	void update_times_only();

	double get_power(int i) const;
	void set_power(double P, int i);

	double get_next_time(int i);	//time from point i to i+1
	double get_total_time(int i=-1) const;	//time from start to point i

	double update_time(const Cyclist& rider, int start=0, int end=-1);	//calculates speeds and times during the whole ride
	void initial_solution(const Cyclist& rider, double power, double v0 = 5);

	double averagePower_weighted(std::function<double(double)> f, std::function<double(double)> f_inv) const;
	int size() const;
	double get_seaRho() const;

	void set_wbal(double w, int i);
	double get_wbal(int i) const;

	void new_copy(Track* t, int start=0, int end=-1);
	void copy(Track* t, int start=0, int end=-1);

	void save(std::string filePath) const;
	void load(std::string filePath);
};