#include "Functions.h"
#include "Tester.h"
#include <iostream>
#include <iomanip>

template<typename T> void printColumn(T t, int w)
{
	std::cout << std::left << std::setw(w) << std::setfill(' ') << t;
}

Tester::Tester()
{
	_track = nullptr;
}

Tester::Tester(Track* track)
{
	_track=track;
}

Track*& Tester::track()
{
	return this->_track;
}

void Tester::print()
{
	printColumn("i", 6);
	printColumn("h", 6);
	printColumn("P", 6);
	printColumn("v", 6);
	printColumn("t", 6);
	std::cout << std::endl;
	for (int i = 0; i < _track->size(); i++)
	{
		printColumn(i, 6);
		printColumn((*_track)[i].get_altitude(), 6);
		printColumn((*_track)[i].get_power(), 6);
		printColumn((*_track)[i].get_speed()*3.6, 6);
		printColumn((*_track)[i].get_time(), 6);
		std::cout << std::endl;
	}
}


void Tester::setFlat(int length)
{
	_track->clear();
	for (int i = 0; i < length; i++)
	{
		_track->push_xy(i * step, 0);
	}
	_track->set_connections();
}

void Tester::setSquare(int sideLength)
{
	_track->clear();
	for (int x = 0; x < sideLength; x++)
	{
		_track->push_xy(x * step, 0);
	}
	for (int y = 1; y < sideLength; y++)
	{
		_track->push_xy((sideLength - 1) * step, (y)*step);
	}
	for (int x = sideLength - 2; x >= 0; x--)
	{
		_track->push_xy(x * step, (sideLength - 1) * step);
	}
	for (int y = sideLength - 2; y >= 0; y--)
	{
		_track->push_xy(0, y * step);
	}
	_track->set_connections();
}

void Tester::setHill(int length, double slope, int start)
{
	_track->clear();
	for (int i = 0; i < start; i++)
	{
		_track->push_xy(i*step, 0);
	}

	for (int i = start; i < length; i++)
	{
		_track->push_xy(i * step, 0, slope * (i - start + 1) * step);
	}

	_track->set_connections();
}

void Tester::setCorner(int length, double radius)
{
	for (int i = 0; i < length; i++)
	{
		_track->push_xy(i * step, 0);
	}

	double angleStep = step / radius;
	int numSteps = static_cast<int>(M_PI/ 2 / angleStep);
	for (int i = 1; i <= numSteps; i++)
	{
		double angle = i * angleStep;
		double x = (length - 1 + radius * std::sin(angle)) * step;
		double y = (radius - radius * std::cos(angle)) * step;
		_track->push_xy(x, y);
	}

	for (int i = 0; i < length; i++)
	{
		double x = (length - 1 + radius) * step;
		double y = (radius + i) * step;
		_track->push_xy(x, y);
	}

	_track->set_connections();
}