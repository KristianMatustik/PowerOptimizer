#pragma once
#include "Cyclist.h"
#include "Track.h"
#include <functional>
#include <cmath>
#include "Setup.h"



class Optimizer
{
public:
	static const std::function<double(double)> AP;
	static const std::function<double(double)> AP_inv;
	static const std::function<double(double)> NP;
	static const std::function<double(double)> NP_inv;

	void improve(const std::function<double(double)>&, const std::function<double(double)>&, const std::vector<double>& adj_gradient, double dW, double k);
	void improve_NP(const std::vector<double>& adj_gradient, double dP); //temporary till fixed some bugs with common method

	void adjust_power_f(const std::function<double(double)>&, const std::function<double(double)>&, double P_lim, double P_max = INF, double P_eps = P_EPS);
	void adjust_power_CP(double CP, double W_max, double W_start, double W_end, const std::vector<double>& dP, const std::vector<double>& adj_gradient, double P_max = INF, double W_eps = W_EPS);
	std::vector<double> W_balance(double CP, double W_max, double W_start);

	void optimize_simple_f(const std::function<double(double)>&, const std::function<double(double)>&, double v0, double P_lim, double P_max = INF, double dt = DT, double steps = STEPS, double firstStepDP = FIRST_STEP, double dW = DW_AP, double P_eps = P_EPS, double t_eps = T_EPS);
	void optimize_simple_CP(double v0, double CP, double W_max, double P_max = INF, double W_start=-1, double W_end=0, double dt = DT, double steps = STEPS, double firstStepDP = FIRST_STEP, double dW = DW_AP, double W_eps = W_EPS);

	void optimize_f(const std::function<double(double)>&, const std::function<double(double)>&, double P_lim, double P_max = INF, double dt = DT, double steps = STEPS, double firstStepDP = FIRST_STEP, double dW = DW_AP, double P_eps = P_EPS, double t_eps = T_EPS);
	void optimize_CP(double CP, double W_max, double P_max = INF, double dt = DT, double steps = STEPS, double firstStepDP = FIRST_STEP, double dW = DW_AP, double W_eps = W_EPS);

	std::vector<double> calculate_dP(const std::function<double(double)>& f,
		const std::function<double(double)>& f_inv, double dW = DW_AP);
	std::vector<double> calculate_gradient(const std::function<double(double)>& f,
		const std::function<double(double)>& f_inv, double dt = -1, double dW = DW_AP, std::vector<double> dP = {});
	std::vector<double> adjusted_gradient(const std::vector<double>&);


	Cyclist* _cyclist;
	Track* _track;
public:
	double progress = 0; // to be implemented progressbar

	Optimizer();
	Optimizer(Track* track, Cyclist* cyclist);
	~Optimizer();

	Cyclist*& cyclist();
	Track*& track();

	void solve_AP(double P_lim, double P_max = INF, double dt = DT, double steps = STEPS, double firstStepDP = FIRST_STEP, double dW = DW_AP, double P_eps = P_EPS, double t_eps = T_EPS);
	void solve_NP(double P_lim, double P_max = INF, double dt = DT, double steps = STEPS, double firstStepDP = FIRST_STEP, double dW = DW_NP, double P_eps = P_EPS, double t_eps = T_EPS);
	void solve_CP(double CP, double W, double P_max = INF, double dt = DT, double steps = STEPS, double firstStepDP = FIRST_STEP, double dW = DW_AP, double W_eps = W_EPS);
};