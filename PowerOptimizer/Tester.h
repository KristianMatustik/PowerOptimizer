#pragma once
#include "Track.h"
#include "Optimizer.h"

#define step 1

class Tester	//used for model tracks
{
	Track& _track;
	Cyclist& _cyclist;
	Optimizer optimizer;
	double m = 0.000008993216059; //m in degrees on equator

public:
	Tester(Track& track, Cyclist& cyclist);

	Track& track();
	Cyclist& cyclist();

	void print();

	void setFlat(int length);
	void setWind(int length, double v);
	void setSquare(int sideLength);
	void setHill(int length, double slope, int start=0);
	void setA(int length, double slope);
	void setCorner(int length, double radius);
};

