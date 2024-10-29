#pragma once
#include "Cyclist.h"
#include "Track.h"
#include <functional>
#include <cmath>



class Optimizer
{
	static const std::function<double(double)> AP;
	static const std::function<double(double)> AP_inv;
	static const std::function<double(double)> NP;
	static const std::function<double(double)> NP_inv;

	void adjust_power_f(std::function<double(double)>, std::function<double(double)>, double P_lim, double P_max = INF);
	void adjust_power_CP(double CP, double W, double P_max = INF);

	void optimize_simple_f(std::function<double(double)>, std::function<double(double)>, double P_lim, double P_max = INF, double iters = 30, double r = 0.9, double dp = 20);
	void optimize_simple_CP(double CP, double W, double P_max = INF);

	void optimize_f(std::function<double(double)>, std::function<double(double)>, double P_lim, double P_max = INF, double iters = 30, double r = 0.9, double dp = 20);
	void optimize_CP(double CP, double W, double P_max = INF);
	void adjust_f(std::function<double(double)>, std::function<double(double)>, double P_lim, double P_max = INF);
	void adjust_CP(double CP, double W, double P_max = INF);


	std::vector<double> calculate_gradient(std::function<double(double)> f,
		std::function<double(double)> f_inv, double t = -1, double dp = 1);
	std::vector<int> gradient_to_adjustment(const std::vector<double>&);

	double progress = 0;
	Cyclist* _cyclist;
	Track* _track;
public:

	Optimizer();
	Optimizer(Track* track, Cyclist* cyclist);
	~Optimizer();

	Cyclist*& cyclist();
	Track*& track();
									
	std::vector<double> calculate_gradient_AP(double t = -1, double dp = 1);
	std::vector<double> calculate_gradient_NP(double t = -1, double dp = 1);

	void solve_AP(double P_lim, double P_max = INF, double iters = 30, double r = 0.9, double dp = 20);
	void solve_NP(double P_lim, double iters = 30, double r = 0.9, double dp = 20);
	void solve_CP();
};