#pragma once
#include "Setup.h"
#include <vector>
#include <string>
#include <fstream>
#include <iostream>

class Cyclist
{
private:
	double mass;
	std::vector<double> CdA_TT;
	std::vector<double> CdA_TT_yaw;
	double CdA_oos;
	double CdA_oos_power;
	double efficiency;
	double brakingForce;
	double turnBankAngle;

public:
	double CdA(double yaw, double power);
	void set_CdA(std::vector<double> CdA_TT, std::vector<double> CdA_TT_limit, double CdA_oos, double CdA_oos_limit);
	double get_mass();
	void set_mass(double mass);
	double get_efficiency();
	void set_efficiency(double efficieny);
	double get_brakingForce();
	void set_brakingForce(double brakingForce);
	double get_turnBankAngle();
	void set_turnBankAngle(double turnBankAngle);

	void save(std::string filePath);
	void load(std::string filePath);
};