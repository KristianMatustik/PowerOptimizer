#pragma once
#include "Cyclist.h"
#include "Track.h"

class Optimizer
{
	enum class model
	{
		AP, NP, CP
	};

	void optimize_simple_f(Cyclist rider, double (*f)(double), double (*f_inv)(double), double P, double maxP=-1);
	void optimize_simple_CP(Cyclist rider, double CP, double W, double maxP=-1);
	void optimize_f(Cyclist rider, double (*f)(double), double (*f_inv)(double), double P, double maxP=-1);
	void optimize_CP(Cyclist rider, double CP, double W, double maxP = -1);
	void adjust_f(double (*f)(double), double (*f_inv)(double), double P, double maxP = -1);
	void adjust_CP(double CP, double W, double maxP = -1);

public:

	Cyclist rider;
	Track track;

	Optimizer();
	~Optimizer();

	std::vector<double> calculate_gradient(double (*f)(double), double (*f_inv)(double), double t = -1, double dp = 1);


	void optimize(model m, double CP=0, double W=0);
};