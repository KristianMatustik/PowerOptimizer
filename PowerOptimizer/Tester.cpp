#include "Tester.h"
#include <iostream>
#include <iomanip>

template<typename T> void printColumn(T t, int w)
{
	std::cout << std::left << std::setw(w) << std::setfill(' ') << t;
}

void Tester::print()
{
	printColumn("i", 6);
	printColumn("h", 6);
	printColumn("P", 6);
	printColumn("v", 6);
	printColumn("t", 6);
	std::cout << std::endl;
	for (int i = 0; i < track.route.size(); i++)
	{
		printColumn(i, 6);
		printColumn(track.route[i].altitude, 6);
		printColumn(track.route[i].power, 6);
		printColumn(track.route[i].speed * 3.6, 6);
		printColumn(track.route[i].time, 6);
		std::cout << std::endl;
	}
}

void Tester::setFlat(int length)
{
	for (int i = 0; i < length; i++)
	{
		Track::Point p;
		p.next_distance = 1;
		p.next_bearing = 90;
		p.x = i;
		p.y = 0;
		p.altitude = 0;
		track.route.push_back(p);
	}
}

void Tester::setHill(int length, double slope, int start)
{
	for (int i = 0; i < start; i++)
	{
		Track::Point p;
		p.next_distance = step;
		p.next_bearing = 90;
		p.x = i;
		p.y = 0;
		p.altitude = 0;
		track.route.push_back(p);
	}
	for (int i = start; i < length; i++)
	{
		Track::Point p;
		p.next_distance = step;
		p.next_bearing = 90;
		p.x = i*step;
		p.y = 0;
		p.altitude = slope*(i-start+1)*step;
		track.route.push_back(p);
	}
}

void Tester::loadTrack(std::string filename)
{
	track.loadGPX("test.gpx");
}

void Tester::testSteady(double power)
{
	track.set_rho();
	track.set_wind(0,0);
	track.set_crr(0.003);
	track.initial_solution(c, power);
}