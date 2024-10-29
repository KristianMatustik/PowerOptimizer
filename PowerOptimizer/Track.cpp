#include "Track.h"
#include "Functions.h"
#include <vector>
#include <string>
#include "tinyxml2.h"
#include <stdexcept>

Track::Point::Point()
{
    lat = lon = 0;
    x = y = 0;
    altitude = 0;
    rho = DEFAULT_SEA_RHO;
    crr = DEFAULT_CRR;
    maxSpeed = INF;
    wind_speed = 0;
    wind_bearing = 0;
    wind_speed_travel = 0;
    next_distance = 0;
    next_bearing = 0;
    power = 0;
    kineticEnergy = 0;
    speed = 0;
    time = 0;
}

Track::Point::~Point() = default;

void Track::Point::initialize_GPS(double lat, double lon, double alt, double crr, double seaRho)
{
    set_gps(lat, lon);
    set_altitude(alt, seaRho);
    set_crr(crr);
}

void Track::Point::initialize_xy(double x, double y, double alt, double crr, double seaRho)
{
    set_xy(x, y);
    set_altitude(alt,seaRho);
    set_crr(crr);
}

double Track::Point::get_lat() const
{
    return lat;
}

double Track::Point::get_lon() const
{
    return lon;
}

void Track::Point::set_gps(double lat, double lon)
{
    if (lat < -90 || lat>90 || lon <= -180 || lon>180)
        throw std::invalid_argument("Lat or Lon out of bounds [-90,90]/(-180,180]");
    this->lat = lat;
    this->lon = lon;
}

double Track::Point::get_x() const
{
    return x;
}

double Track::Point::get_y() const
{
    return y;
}

void Track::Point::set_xy(double x, double y)
{
    this->x = x;
    this->y = y;
}

double Track::Point::get_altitude() const
{
    return altitude;
}

void Track::Point::set_altitude(double alt, double seaRho)
{
    if (seaRho < 0)
        throw std::invalid_argument("Negative sea Rho");
    this->altitude = alt;
    calculate_rho(seaRho);
}

double Track::Point::get_rho() const
{
    return rho;
}

void Track::Point::set_rho(double rho)
{
    if (rho < 0)
        throw std::invalid_argument("Negative Rho");
    this->rho = rho;
}

void Track::Point::calculate_rho(double seaRho)
{
    if (seaRho < 0)
        throw std::invalid_argument("Negative sea Rho");
    rho = seaRho * (11000 - altitude) / 11000;
}

double Track::Point::get_crr() const
{
    return crr;
}

void Track::Point::set_crr(double crr)
{
    if (crr < 0)
        throw std::invalid_argument("Negative crr");
    this->crr = crr;
}

double Track::Point::get_maxSpeed() const
{
    return maxSpeed;
}

void Track::Point::set_maxSpeed(double maxSpeed)
{
    if (maxSpeed <= 0)
        throw std::invalid_argument("MaxSpeed not positive");
    this->maxSpeed = maxSpeed;
}

double Track::Point::get_wind_speed() const
{
    return wind_speed;
}

double Track::Point::get_wind_bearing() const
{
    return wind_bearing;
}

double Track::Point::get_wind_speed_travel() const
{
    return wind_speed_travel;
}

void Track::Point::set_wind(double bearing, double speed)
{
    wind_bearing = bearing;
    wind_speed = speed;
    if (next != nullptr)
        wind_speed_travel = std::cos(Functions::degToRad(180 - bearing - next_bearing)) * speed;
}

double Track::Point::get_next_bearing() const
{
    return next_bearing;
}

double Track::Point::get_next_distance() const
{
    return next_distance;
}

double Track::Point::get_next_time() const
{
    return next_distance / speed;
}

void Track::Point::set_next(Point* next)
{
    if (next == nullptr)
    {
        next_distance = 0;
        next_bearing = 0;
        this->next = nullptr;
        return;
    }

    double lat2 = next->lat;
    double lon2 = next->lon;
    if (lat == lon && lat2 == lon2 && lat == lat2 && lat == 0.0)
    {
        next_distance = std::sqrt(std::pow(x - next->x, 2) + std::pow(y - next->y, 2));
        next_bearing = Functions::normalizeAngle(std::atan2(next->x - x, next->y - y));
    }
    else
    {
        next_distance = Functions::distance(lat, lon, lat2, lon2);
        next_bearing = Functions::bearing(lat, lon, lat2, lon2);
    }
    this->next = next;
}

double Track::Point::get_power() const
{
    return power;;
}

void Track::Point::set_power(double power)
{
    this->power = power;
}

double Track::Point::get_time() const
{
    return time;
}

double Track::Point::get_speed() const
{
    return speed;
}

void Track::Point::set_starting_speed(const Cyclist& cyclist, double v0)
{
    if (v0 <= 0)
        throw std::invalid_argument("V0 not positive");
    kineticEnergy = Functions::energy_kinetic(cyclist.get_mass(), v0);
    speed = v0;
}

double Track::Point::update_next(const Cyclist& cyclist)
{
    double m = cyclist.get_mass();

    std::pair<double,double> wind = Functions::addVectors(wind_bearing,wind_speed,next_bearing,speed);
    double yaw = Functions::yaw(wind.first, next_bearing);

    double cda = cyclist.get_CdA(yaw, power);

    double workAdded = power * get_next_time() * cyclist.get_efficiency();
    double potentialChange = Functions::energy_potential(m, altitude) - Functions::energy_potential(m, next->altitude);
    double aeroLoss = Functions::force_aero(rho, cyclist.get_CdA(0, 0), speed - wind_speed_travel) * next_distance;
    double rollLoss = Functions::force_roll(m * G, crr) * next_distance;

    next->kineticEnergy = kineticEnergy
                            + workAdded
                            + potentialChange
                            - aeroLoss
                            - rollLoss;
    next->speed = Functions::speed_fromKE(m,next->kineticEnergy,cyclist.get_mass_wheelInertia());
    next->time = time + get_next_time();

    return 0;
}



//////// Track
 
Track::Track() = default;

Track::~Track() = default;

void Track::load_GPX(const std::string& filePath)
{
    tinyxml2::XMLDocument doc;
    if (doc.LoadFile(filePath.c_str()) != tinyxml2::XML_SUCCESS)
    {
        throw std::runtime_error("Error loading GPX file.");
    }

    tinyxml2::XMLElement* gpx = doc.FirstChildElement("gpx");
    if (!gpx)
    {
        throw std::runtime_error("Invalid GPX format: <gpx> root element not found.");
    }

    tinyxml2::XMLElement* trk = gpx->FirstChildElement("trk");
    if (!trk)
    {
        throw std::runtime_error("Invalid GPX format: <trk> element not found.");
    }

    tinyxml2::XMLElement* trkseg = trk->FirstChildElement("trkseg");
    if (!trkseg)
    {
        throw std::runtime_error("Invalid GPX format: <trkseg> element not found.");
    }

    for (tinyxml2::XMLElement* trkpt = trkseg->FirstChildElement("trkpt"); trkpt != nullptr; trkpt = trkpt->NextSiblingElement("trkpt"))
    {
        double lat = trkpt->DoubleAttribute("lat");
        double lon = trkpt->DoubleAttribute("lon");
        double alt = 0;
        double pwr = 0;

        tinyxml2::XMLElement* ele = trkpt->FirstChildElement("ele");
        double altitude = 0;
        if (ele)
        {
            alt = ele->DoubleText();
        }

        tinyxml2::XMLElement* extensions = trkpt->FirstChildElement("extensions");
        if (extensions)
        {
            tinyxml2::XMLElement* powerElem = extensions->FirstChildElement("power");
            if (powerElem) {
                pwr = powerElem->DoubleText();
            }
        }
        Point point;
        point.initialize_GPS(lat, lon, alt);
        point.set_power(pwr);
        route.push_back(point);
    }

    set_connections();
}

void Track::save_GPX(const std::string& filePath)
{
    /////////
}

void Track::clear()
{
    route.clear();
}

void Track::push_GPS(double lat, double lon, double alt, double crr, double seaRho)
{
    Point p;
    p.initialize_GPS(lat, lon, alt, crr, seaRho);
    route.push_back(p);
    route[route.size() - 2].set_next(&route.back());
    route.back().set_next(nullptr);
}

void Track::push_xy(double x, double y, double alt, double crr, double seaRho)
{
    Point p;
    p.initialize_xy(x, y, alt, crr, seaRho);
    route.push_back(p);
    route[route.size() - 2].set_next(&route.back());
    route.back().set_next(nullptr);
}

const Track::Point& Track::operator[](int idx)
{
    if (idx < 0 || idx > route.size()-1)
        throw std::invalid_argument("Invalid index");
    return route[idx];
}

void Track::set_connections()
{
    Point& start = route[0];
    start.set_xy(0, 0);
    double sLat = start.get_lat();
    double sLon = start.get_lon();

    for (int i = 0; i < route.size() - 1; i++)
    {
        double iLat = route[i].get_lat();
        double iLon = route[i].get_lon();
        double x = Functions::distance(sLat, iLon, sLat, sLon) * (sLon < iLon ? 1 : -1);
        double y = Functions::distance(iLat, sLon, sLat, sLon) * (sLat < iLat ? 1 : -1);
        route[i].set_next(&route[i + 1]);
        route[i].set_xy(x, y);
    }
    double Lat = route.back().get_lat();
    double Lon = route.back().get_lon();
    double x = Functions::distance(sLat, Lon, sLat, sLon) * (sLon < Lon ? 1 : -1);
    double y = Functions::distance(Lat, sLon, sLat, sLon) * (sLat < Lat ? 1 : -1);
    route.back().set_next(nullptr);
    route.back().set_xy(x, y);
}

void Track::set_crr(double crr)
{
    for (int i = 0; i < route.size(); i++)
    {
        route[i].set_crr(crr);
    }
}

void Track::set_wind(double bearing, double speed)
{
    for (int i = 0; i < route.size(); i++)
    {
        route[i].set_wind(bearing, speed);
    }
}

void Track::set_rho(double seaRho)
{
    for (int i = 0; i < route.size(); i++)
    {
        route[i].calculate_rho(seaRho);
    }
}

void Track::set_corners(const Cyclist& cyclist)
{
    for (int i = 1; i < route.size() - 1; i++)
    {
        double r = Functions::circleRadius( route[i - 1].get_x(),    route[i - 1].get_y(),
                                            route[i].get_x(),       route[i].get_y(),
                                            route[i + 1].get_x(),   route[i + 1].get_y());
        route[i].set_maxSpeed(std::sqrt(G * r * std::tan(Functions::degToRad(cyclist.get_turnBankAngle()))));
    }
}

void Track::set_power(double P, int i)
{
    if (i < 0 || i > route.size() - 1)
        throw std::invalid_argument("Invalid index");
    route[i].set_power(P);
}

double Track::update_time(const Cyclist& cyclist, int start, int end)
{
    if (end < 0 || end > route.size() - 1)
        end = route.size() - 1;
    for (int i = start; i < end; i++)
    {
        route[i].update_next(cyclist);
    }
    return route[end].get_time();
}

void Track::initial_solution(const Cyclist& cyclist, double power, double v0)
{
    route[0].set_starting_speed(cyclist, v0);
    for (int i = 0; i < route.size() - 1; i++)
    {
        route[i].set_power(power);
        route[i].update_next(cyclist);
    }
    route.back().set_power(0);
}

double Track::averagePower_weighted(std::function<double(double)> f, std::function<double(double)> f_inv) const
{
    double P=0;
    for (int i = 0; i < route.size()-1; i++)
    {
        if (P > 0)
            P += f(route[i].get_power()) * route[i].get_next_time();
    }
    P = f_inv(P / route.back().get_time());
    return P;
}

int Track::size() const
{
    return route.size();
}

void Track::save(std::string filename) const
{
    /////////
}

void Track::load(std::string filename)
{
    /////////
}