#pragma once
#include "Track.h"

#define step 1

class Tester
{
	Track track;

	Cyclist c = Cyclist(90, 0.2);

public:
	void print();

	void setFlat(int length);
	void setHill(int length, double slope, int start=0);

	void loadTrack(std::string filename);
	void testSteady(double power);
};

