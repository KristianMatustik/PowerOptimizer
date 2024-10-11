#pragma once
#include "Track.h"

#define step 1

class Tester
{
	Track* _track;
public:
	Tester();
	Tester(Track* track);

	Track*& track();

	void print();

	void setFlat(int length);
	void setSquare(int sideLength);
	void setHill(int length, double slope, int start=0);
	void setCorner(int length, double radius);
};

