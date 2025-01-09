#include "Functions.h"
#include <stdexcept>
#include <ctime>
#include <iomanip>
#include <sstream>

double Functions::energy_kinetic(double mass, double velocity)
{
    return 0.5 * mass * velocity * velocity;
}


double Functions::energy_potential(double mass, double height)
{
    return mass * G * height;
}


double Functions::force_aero(double rho, double CdA, double velocity)
{
    return 0.5 * rho * CdA * velocity * velocity;
}


double Functions::force_roll(double weight, double crr)
{
    return weight * crr;
}


double Functions::speed_fromKE(double mass, double kineticEnergy, double inertiaMass)
{
    return std::sqrt(2 * kineticEnergy / (mass + inertiaMass));
}


double Functions::bearing(double lat1, double lon1, double lat2, double lon2)
{
    double phi1 = degToRad(lat1);
    double phi2 = degToRad(lat2);
    double dPhi = degToRad(lon2 - lon1);

    double y = std::sin(dPhi) * std::cos(phi2);
    double x = std::cos(phi1) * std::sin(phi2)
        - std::sin(phi1) * std::cos(phi2) * std::cos(dPhi);

    double bearing = std::atan2(y, x);
    bearing = radToDeg(bearing);
    bearing = normalizeAngle(bearing);

    return bearing;
}

double Functions::distance(double lat1, double lon1, double lat2, double lon2)
{
    //maybe change for some more precise method, use library, ...
    const double R = 6371000;

    lat1 = degToRad(lat1);
    lon1 = degToRad(lon1);
    lat2 = degToRad(lat2);
    lon2 = degToRad(lon2);

    double dLat = lat2 - lat1;
    double dLon = lon2 - lon1;

    double a =  std::sin(dLat / 2) * std::sin(dLat / 2) +
                std::cos(lat1) * std::cos(lat2) *
                std::sin(dLon / 2) * std::sin(dLon / 2);
    double c = 2 * std::atan2(std::sqrt(a), std::sqrt(1 - a));

    return R * c;
}


double Functions::yaw(double bearing1, double bearing2)
{
    double angle = bearing2 - bearing1;

    while (angle > 180) angle -= 360;
    while (angle <= -180) angle += 360;

    return angle;
}

std::pair<double, double> Functions::addVectors(double bearing1, double magnitude1, double bearing2, double magnitude2)
{
    //maybe later change to cosine law formula, could be faster (less trig)
    if (magnitude1 < 0)
    {
        bearing1 = normalizeAngle(bearing1 + 180);
    }
    if (magnitude2 < 0)
    {
        bearing2 = normalizeAngle(bearing2 + 180);
    }

    std::pair<double, double> result;
    double bearing1Rad = degToRad(bearing1);
    double bearing2Rad = degToRad(bearing2);

    double x1 = magnitude1 * std::sin(bearing1Rad);
    double y1 = magnitude1 * std::cos(bearing1Rad);
    double x2 = magnitude2 * std::sin(bearing2Rad);
    double y2 = magnitude2 * std::cos(bearing2Rad);

    double x3 = x1 + x2;
    double y3 = y1 + y2;
    
    double magnitude3 = std::sqrt(x3 * x3 + y3 * y3);
    double bearing3 = 90 - radToDeg(std::atan2(y3, x3));
    bearing3 = normalizeAngle(bearing3);

    result.first = bearing3;
    result.second = magnitude3;

    return result;
}


double Functions::circleRadius(double x1, double y1, double x2, double y2, double x3, double y3)
{
    double a = std::sqrt(std::pow(x2 - x1, 2) + std::pow(y2 - y1, 2));
    double b = std::sqrt(std::pow(x3 - x2, 2) + std::pow(y3 - y2, 2));
    double c = std::sqrt(std::pow(x1 - x3, 2) + std::pow(y1 - y3, 2));

    double s = (a + b + c) / 2;

    double area = std::sqrt(s * (s - a) * (s - b) * (s - c));

    if (area == 0)
        return INF;

    double radius = (a * b * c) / (4 * area);
    return radius;
}

double Functions::degToRad(double degrees)
{
    return degrees * M_PI / 180.0;
}

double Functions::radToDeg(double radians)
{
    return radians * 180.0 / M_PI;
}

double Functions::normalizeAngle(double angle)
{
    angle = std::fmod(angle, 360.0);

    if (angle < 0)
        angle += 360.0;

    return angle;
}

double Functions::power_average(double P)
{
    return P;
}

double Functions::power_average_inv(double P)
{
    return P;
}

double Functions::power_normalized(double P)
{
    return std::pow(P,4);
}

double Functions::power_normalized_inv(double P)
{
    return std::pow(P,0.25);
}

std::string Functions::time_to_string(double t, const std::string& timeStrBase)
{
    std::tm baseTimeStruct = {};
    std::istringstream baseStream(timeStrBase);
    baseStream >> std::get_time(&baseTimeStruct, "%Y-%m-%dT%H:%M:%S");
    if (baseStream.fail())
    {
        throw std::invalid_argument("Invalid base time string format");
    }
    time_t baseTime = std::mktime(&baseTimeStruct);
    if (baseTime == -1)
    {
        throw std::invalid_argument("Failed to convert base time to time_t");
    }
    time_t adjustedTime = baseTime + static_cast<time_t>(t);


    std::ostringstream oss;
    oss << std::put_time(std::gmtime(&adjustedTime), "%Y-%m-%dT%H:%M:%S");

    double fractionalPart = t - static_cast<int>(t);
    std::ostringstream fractionalStream;
    fractionalStream << std::fixed << std::setprecision(5) << fractionalPart;
    std::string fractionalStr = fractionalStream.str();
    fractionalStr.erase(0, 1);
    oss << fractionalStr;
    oss << "Z";
    return oss.str();
}

double Functions::string_to_time(const std::string& timeStr, const std::string& timeStrBase)
{
    std::tm baseTimeStruct = {};
    std::istringstream baseStream(timeStrBase.substr(0, 19));
    baseStream >> std::get_time(&baseTimeStruct, "%Y-%m-%dT%H:%M:%S");

    if (baseStream.fail())
    {
        throw std::invalid_argument("Invalid base time string format");
    }
    time_t baseTime = std::mktime(&baseTimeStruct);
    if (baseTime == -1)
    {
        throw std::invalid_argument("Failed to convert base time to time_t");
    }
    double fractionalPartBase = 0.0;
    size_t fractionalPosBase = timeStr.find_first_of('.', 19);
    if (fractionalPosBase != std::string::npos)
    {
        std::string fractionalStrBase = timeStrBase.substr(fractionalPosBase + 1, 5);
        std::istringstream fractionalStream(fractionalStrBase);
        fractionalStream >> fractionalPartBase;
        fractionalPartBase /= 100000.0;
    }

    //

    std::tm timeStruct = {};
    std::istringstream timeStream(timeStr.substr(0, 19));
    timeStream >> std::get_time(&timeStruct, "%Y-%m-%dT%H:%M:%S");
    if (timeStream.fail())
    {
        throw std::invalid_argument("Invalid time string format");
    }
    time_t adjustedTime = std::mktime(&timeStruct);
    if (adjustedTime == -1)
    {
        throw std::invalid_argument("Failed to convert time string to time_t");
    }

    double fractionalPart = 0.0;
    size_t fractionalPos = timeStr.find_first_of('.', 19);
    if (fractionalPos != std::string::npos) {
        std::string fractionalStr = timeStr.substr(fractionalPos + 1, 5);
        std::istringstream fractionalStream(fractionalStr);
        fractionalStream >> fractionalPart;
        fractionalPart /= 100000.0;
    }

    //

    double timeDifference = difftime(adjustedTime, baseTime);
    return timeDifference + fractionalPart - fractionalPartBase;
}