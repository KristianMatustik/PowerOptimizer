#include "Functions.h"
#include <limits>


double PowerOptimizer::Functions::energy_kinetic(double mass, double velocity)
{
    return 0.5 * mass * velocity * velocity;
}


double PowerOptimizer::Functions::energy_potential(double mass, double height)
{
    return mass * g * height;
}


double PowerOptimizer::Functions::force_aero(double rho, double CdA, double velocity)
{
    return 0.5 * rho * CdA * velocity * velocity;
}


double PowerOptimizer::Functions::force_roll(double weight, double crr)
{
    return weight * crr;
}


double PowerOptimizer::Functions::velocity(double mass, double kineticEnergy, double inertiaMass)
{
    return std::sqrt(2 * kineticEnergy / (mass + inertiaMass));
}


double PowerOptimizer::Functions::bearing(double lat1, double lon1, double lat2, double lon2)
{
    double phi1 = lat1 * M_PI / 180.0;
    double phi2 = lat2 * M_PI / 180.0;
    double deltaLambda = (lon2 - lon1) * M_PI / 180.0;

    double y = std::sin(deltaLambda) * std::cos(phi2);
    double x = std::cos(phi1) * std::sin(phi2)
        - std::sin(phi1) * std::cos(phi2) * std::cos(deltaLambda);

    double bearing = std::atan2(y, x);
    bearing = bearing * 180.0 / M_PI;
    bearing = fmod((bearing + 360.0), 360.0);

    return bearing;
}


double PowerOptimizer::Functions::yaw(double bearing1, double bearing2)
{
    double angle = bearing2 - bearing1;

    while (angle > 180) angle -= 360;
    while (angle <= -180) angle += 360;

    return angle;
}


double PowerOptimizer::Functions::circle_radius(double x1, double y1, double x2, double y2, double x3, double y3)
{
    double a = std::sqrt(std::pow(x2 - x1, 2) + std::pow(y2 - y1, 2));
    double b = std::sqrt(std::pow(x3 - x2, 2) + std::pow(y3 - y2, 2));
    double c = std::sqrt(std::pow(x1 - x3, 2) + std::pow(y1 - y3, 2));

    double s = (a + b + c) / 2;

    double area = std::sqrt(s * (s - a) * (s - b) * (s - c));

    if (area == 0)
        return std::numeric_limits<double>::infinity();

    double radius = (a * b * c) / (4 * area);
    return radius;
}
