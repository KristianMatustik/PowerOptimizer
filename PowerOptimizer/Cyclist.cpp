#include "Cyclist.h"

double Cyclist::CdA(double yaw, double power)
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
		return CdA_TT[CdA_TT_yaw.size()];
	}
}

void Cyclist::set_CdA(std::vector<double> CdA_TT, std::vector<double> CdA_TT_limit, double CdA_oos, double CdA_oos_power)
{
	this->CdA_TT = CdA_TT;
	this->CdA_TT_yaw = CdA_TT_limit;
	this->CdA_oos = CdA_oos;
	this->CdA_oos_power = CdA_oos_power;
}

double Cyclist::get_mass()
{
	return mass;
}

void Cyclist::set_mass(double mass)
{
	this->mass = mass;
}

double Cyclist::get_efficiency()
{
	return efficiency;
}

void Cyclist::set_efficiency(double efficieny)
{
	this->efficiency = efficieny;
}

double Cyclist::get_brakingForce()
{
	return brakingForce;
}

void Cyclist::set_brakingForce(double brakingForce)
{
	this->brakingForce = brakingForce;
}

double Cyclist::get_turnBankAngle()
{
	return turnBankAngle;
}

void Cyclist::set_turnBankAngle(double turnBankAngle)
{
	this->turnBankAngle = turnBankAngle;
}

void Cyclist::save(std::string filePath)
{
    std::ofstream outFile(filePath, std::ios::binary);
    if (!outFile)
    {
        std::cerr << "Error opening file for saving: " << filePath << std::endl;
        return;
    }

    outFile.write(reinterpret_cast<char*>(&mass), sizeof(mass));
    outFile.write(reinterpret_cast<char*>(&CdA_oos), sizeof(CdA_oos));
    outFile.write(reinterpret_cast<char*>(&CdA_oos_power), sizeof(CdA_oos_power));
    outFile.write(reinterpret_cast<char*>(&efficiency), sizeof(efficiency));
    outFile.write(reinterpret_cast<char*>(&brakingForce), sizeof(brakingForce));
    outFile.write(reinterpret_cast<char*>(&turnBankAngle), sizeof(turnBankAngle));

    size_t size_TT = CdA_TT.size();
    size_t size_TT_yaw = CdA_TT_yaw.size();
    outFile.write(reinterpret_cast<char*>(&size_TT), sizeof(size_TT));
    outFile.write(reinterpret_cast<char*>(&size_TT_yaw), sizeof(size_TT_yaw));
    outFile.write(reinterpret_cast<char*>(CdA_TT.data()), size_TT * sizeof(double));
    outFile.write(reinterpret_cast<char*>(CdA_TT_yaw.data()), size_TT_yaw * sizeof(double));

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

    inFile.read(reinterpret_cast<char*>(&mass), sizeof(mass));
    inFile.read(reinterpret_cast<char*>(&CdA_oos), sizeof(CdA_oos));
    inFile.read(reinterpret_cast<char*>(&CdA_oos_power), sizeof(CdA_oos_power));
    inFile.read(reinterpret_cast<char*>(&efficiency), sizeof(efficiency));
    inFile.read(reinterpret_cast<char*>(&brakingForce), sizeof(brakingForce));
    inFile.read(reinterpret_cast<char*>(&turnBankAngle), sizeof(turnBankAngle));

    size_t size_TT, size_TT_yaw;
    inFile.read(reinterpret_cast<char*>(&size_TT), sizeof(size_TT));
    inFile.read(reinterpret_cast<char*>(&size_TT_yaw), sizeof(size_TT_yaw));
    CdA_TT.resize(size_TT);
    CdA_TT_yaw.resize(size_TT_yaw);
    inFile.read(reinterpret_cast<char*>(CdA_TT.data()), size_TT * sizeof(double));
    inFile.read(reinterpret_cast<char*>(CdA_TT_yaw.data()), size_TT_yaw * sizeof(double));

    inFile.close();
}