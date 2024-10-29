#pragma once
#include "Track.h"
#include "Optimizer.h"

#define step 1

class Tester
{
	Track& _track;
	Cyclist& _cyclist;
	Optimizer optimizer;

public:
	Tester(Track& track, Cyclist& cyclist);

	Track& track();
	Cyclist& cyclist();

	void print();

	void setFlat(int length);
	void setSquare(int sideLength);
	void setHill(int length, double slope, int start=0);
	void setCorner(int length, double radius);
};

