#pragma once
#include "Setup.h"
#include <vector>
#include <string>

class Cyclist
{
private:
	double mass;					//mass of the system=rider+bike+equipment
	double mass_wheelInertia;		//inertia of wheels, as artifical mass for rolling, no slip (= I/R^2 ~= bit less than weight of the wheels (mass mostly in the rim))
	std::vector<double> CdA_TT;		//size n, CdA at different yaw angles, e.g. [0.2,0.21,0.22] (at 0-5°/5-10°/10°-180° respectively)
	std::vector<double> CdA_TT_yaw; //size n-1, the dividing points of CdA_TT, eg. [5°,10°] for prev example (0 and 180 are always considered 1st/last)
	double CdA_oos;					//CdA when riding out of saddle
	double CdA_oos_power;			//power transition point, when cyclist rides out of saddle (e.g. 500 W)
	double efficiency;				//power train efficiency, how much power turn into actual work done (e.g. 0.97 = 97 %)
	double brakingDeceleration;			//force at which can rider decelerate when braking, 5000N
	double turnBankAngle;			//angle at which rider can lean the bike going through corner

public:
	Cyclist(double mass = DEFAULT_MASS, double CdA_TT = DEFAULT_CDA_TT, double CdA_oos = DEFAULT_CDA_OOS, double CdA_oos_power = DEFAULT_POWER_OOS,
		double efficiency = DEFAULT_EFFICIENCY, double brakingForce = DEFAULT_BRAKING_DECELERATION, double turnBankAngle = DEFAULT_BANKANGLE, double wheelMassInertia = DEFAULT_WHEEL_INERTIA);
	~Cyclist();

	double get_mass() const;
	void set_mass(double mass);

	double get_mass_wheelInertia() const;
	void set_mass_wheelInertia(double inertia_mass);

	double get_CdA(double yaw, double power) const;
	void set_CdA(const std::vector<double>& CdA_TT, const std::vector<double>& CdA_TT_limit, double CdA_oos=0, double CdA_oos_limit=INF);
	void set_CdA(double CdA_TT, double CdA_oos=0, double CdA_oos_limit=0);

	double get_efficiency() const;
	void set_efficiency(double efficieny);

	double get_brakingDeceleration() const;
	void set_brakingDeceleration(double brakingForce);

	double get_turnBankAngle() const;
	void set_turnBankAngle(double turnBankAngle);

	const std::vector<double>& get_CdA_TT() const;
	const std::vector<double>& get_CdA_TT_yaw() const;
	const double get_CdAoos() const;
	const double get_CdAoosPower() const;

	void save(std::string filePath) const;
	void load(std::string filePath);
};