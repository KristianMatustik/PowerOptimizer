#include "Cyclist.h"

#include <string>
#include <fstream>
#include <iostream>


Cyclist::Cyclist(double mass, double CdA_TT, double CdA_oos, double CdA_oos_power, double efficiency, double brakingForce, double turnBankAngle)
{
    set_mass(mass);
    set_CdA(CdA_TT, CdA_oos, CdA_oos_power);
    set_efficiency(efficiency);
    set_brakingForce(brakingForce);
    set_turnBankAngle(turnBankAngle);
}

Cyclist::~Cyclist() = default;


double Cyclist::get_mass() const
{
	return mass;
}

void Cyclist::set_mass(double mass)
{
    if (mass <= 0)
        throw std::invalid_argument("Negative or zero mass");
	this->mass = mass;
}

double Cyclist::get_mass_wheelInertia() const
{
    return mass_wheelInertia;
}

void Cyclist::set_mass_wheelInertia(double inertia_mass)
{
    if (inertia_mass < 0)
        throw std::invalid_argument("Negative inertia mass");
    mass_wheelInertia = inertia_mass;
}

double Cyclist::get_CdA(double yaw, double power) const
{
    if (power > CdA_oos_power)
        return CdA_oos;
    else
    {
        for (int i = 0; i < CdA_TT_yaw.size(); i++)
        {
            if (yaw < CdA_TT_yaw[i])
                return CdA_TT[i];
        }
        return CdA_TT[CdA_TT.size() - 1];
    }
}

void Cyclist::set_CdA(const std::vector<double>& CdA_TT, const std::vector<double>& CdA_TT_limit, double CdA_oos, double CdA_oos_power)
{
    if (CdA_TT.size() - 1 != CdA_TT_limit.size())
    {
        throw std::invalid_argument("CdA and yaw vectors do not match");
    }
    double prev = 0;
    for (int i = 0; i < CdA_TT_limit.size(); i++)
    {
        if (CdA_TT_limit[i] < prev ||
            CdA_TT_limit[i] <= 0 || CdA_TT_limit[i] >= 180)
        {
            throw std::invalid_argument("Incorrect CdA yaw values");
        }
        prev = CdA_TT_limit[i];
    }
    for (int i = 0; i < CdA_TT.size(); i++)
    {
        if (CdA_TT[i] < 0)
        {
            throw std::invalid_argument("Negative CdA values");
        }
    }

    if (CdA_oos < 0)
    {
        throw std::exception("Negative CdA value (oos)");
    }
    if (CdA_oos_power <= 0)
    {
        this->CdA_oos_power = std::numeric_limits<double>::infinity();
    }
    else
    {
        this->CdA_oos_power = CdA_oos_power;
    }
    this->CdA_TT = CdA_TT;
    this->CdA_TT_yaw = CdA_TT_limit;
    this->CdA_oos = CdA_oos;   
}

void Cyclist::set_CdA(double CdA_TT, double CdA_oos, double CdA_oos_limit)
{
    set_CdA(std::vector<double>{ CdA_TT },
        std::vector<double>{}, CdA_oos, CdA_oos_limit);
}

double Cyclist::get_efficiency() const
{
	return efficiency;
}

void Cyclist::set_efficiency(double efficiency)
{
    if (efficiency<0 || efficiency>1)
        throw std::invalid_argument("Efficiency not between 0 and 1");
	this->efficiency = efficiency;
}

double Cyclist::get_brakingForce() const
{
	return brakingForce;
}

void Cyclist::set_brakingForce(double brakingForce)
{
    if (brakingForce<=0)
        throw std::invalid_argument("Braking force not positive");
	this->brakingForce = brakingForce;
}

double Cyclist::get_turnBankAngle() const
{
	return turnBankAngle;
}

void Cyclist::set_turnBankAngle(double turnBankAngle)
{
    if (turnBankAngle<=0 || turnBankAngle>=90)
        throw std::invalid_argument("Turn angle not between 0 and 90");
	this->turnBankAngle = turnBankAngle;
}

void Cyclist::save(std::string filePath) const
{
    std::ofstream outFile(filePath, std::ios::binary);
    if (!outFile)
    {
        std::cerr << "Error opening file for saving: " << filePath << std::endl;
        return;
    }

    outFile.write(reinterpret_cast<const char*>(&mass), sizeof(mass));
    outFile.write(reinterpret_cast<const char*>(&mass_wheelInertia), sizeof(mass_wheelInertia));
    outFile.write(reinterpret_cast<const char*>(&CdA_oos), sizeof(CdA_oos));
    outFile.write(reinterpret_cast<const char*>(&CdA_oos_power), sizeof(CdA_oos_power));
    outFile.write(reinterpret_cast<const char*>(&efficiency), sizeof(efficiency));
    outFile.write(reinterpret_cast<const char*>(&brakingForce), sizeof(brakingForce));
    outFile.write(reinterpret_cast<const char*>(&turnBankAngle), sizeof(turnBankAngle));

    size_t size_TT = CdA_TT.size();
    size_t size_TT_yaw = CdA_TT_yaw.size();
    outFile.write(reinterpret_cast<const char*>(&size_TT), sizeof(size_TT));
    outFile.write(reinterpret_cast<const char*>(&size_TT_yaw), sizeof(size_TT_yaw));
    outFile.write(reinterpret_cast<const char*>(CdA_TT.data()), size_TT * sizeof(double));
    outFile.write(reinterpret_cast<const char*>(CdA_TT_yaw.data()), size_TT_yaw * sizeof(double));

    outFile.close();
}

void Cyclist::load(std::string filePath)
{
    std::ifstream inFile(filePath, std::ios::binary);
    if (!inFile)
    {
        std::cerr << "Error opening file for loading: " << filePath << std::endl;
        return;
    }

    double tempMass, tempMassWheelInertia, tempCdA_oos, tempCdA_oos_power,
            tempEfficiency, tempBrakingForce, tempTurnBankAngle;
    size_t size_TT, size_TT_yaw;

    inFile.read(reinterpret_cast<char*>(&tempMass), sizeof(tempMass));
    inFile.read(reinterpret_cast<char*>(&tempMassWheelInertia), sizeof(tempMassWheelInertia));
    inFile.read(reinterpret_cast<char*>(&tempCdA_oos), sizeof(tempCdA_oos));
    inFile.read(reinterpret_cast<char*>(&tempCdA_oos_power), sizeof(tempCdA_oos_power));
    inFile.read(reinterpret_cast<char*>(&tempEfficiency), sizeof(tempEfficiency));
    inFile.read(reinterpret_cast<char*>(&tempBrakingForce), sizeof(tempBrakingForce));
    inFile.read(reinterpret_cast<char*>(&tempTurnBankAngle), sizeof(tempTurnBankAngle));
    inFile.read(reinterpret_cast<char*>(&size_TT), sizeof(size_TT));
    inFile.read(reinterpret_cast<char*>(&size_TT_yaw), sizeof(size_TT_yaw));

    std::vector<double> tempCdA_TT(size_TT);
    std::vector<double> tempCdA_TT_yaw(size_TT_yaw);

    inFile.read(reinterpret_cast<char*>(tempCdA_TT.data()), size_TT * sizeof(double));
    inFile.read(reinterpret_cast<char*>(tempCdA_TT_yaw.data()), size_TT_yaw * sizeof(double));

    inFile.close();

    try
    {
        set_mass(tempMass);
        set_mass_wheelInertia(tempMassWheelInertia);
        set_CdA(tempCdA_TT, tempCdA_TT_yaw, tempCdA_oos, tempCdA_oos_power);
        set_efficiency(tempEfficiency);
        set_brakingForce(tempBrakingForce);
        set_turnBankAngle(tempTurnBankAngle);
    }
    catch (const std::exception& e)
    {
        std::cerr << "Error loading data: " << e.what() << std::endl;
    }
}
