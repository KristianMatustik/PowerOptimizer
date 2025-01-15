#include "Track.h"
#include "Functions.h"
#include <vector>
#include <string>
#include "tinyxml2.h"
#include <stdexcept>
#include <fstream>
#include <iostream>

Track::Point::Point()
{
    lat = lon = 0;
    x = y = 0;
    altitude = 0;
    rho = SEA_RHO;
    crr = CRR;
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
    Wbal = 0;
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
    rho = seaRho * std::exp(-altitude/10400);
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
        next_bearing = Functions::normalizeAngle(Functions::radToDeg(std::atan2(next->x - x, next->y - y)));
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

void Track::Point::set_time(double time)
{
    this->time = time;
}

double Track::Point::get_speed() const
{
    return speed;
}

void Track::Point::set_speed(double speed)
{
    this->speed = speed;
}

double Track::Point::get_slope() const
{
    return (next->altitude-this->altitude)/next_distance;
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
    if (next->kineticEnergy < Functions::energy_kinetic(m, 2))  //fix if the speed should be negative (bug explained in the thesis)
    {
        next->kineticEnergy = Functions::energy_kinetic(m, 2);
    }


    next->speed = Functions::speed_fromKE(m,next->kineticEnergy,cyclist.get_mass_wheelInertia());
    next->time = time + get_next_time();

    return 0;
}

double Track::Point::get_wbal() const
{
    return Wbal;
}

void Track::Point::set_wbal(double w)
{
    Wbal = w;
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

    std::string startTimeString = "";
    for (tinyxml2::XMLElement* trkpt = trkseg->FirstChildElement("trkpt"); trkpt != nullptr; trkpt = trkpt->NextSiblingElement("trkpt"))
    {
        double lat = trkpt->DoubleAttribute("lat");
        double lon = trkpt->DoubleAttribute("lon");
        double alt = 0;
        double pwr = 0;
        std::string timeString = "";
        double timeDouble = 0;

        tinyxml2::XMLElement* ele = trkpt->FirstChildElement("ele");
        if (ele)
        {
            alt = ele->DoubleText();
        }

        tinyxml2::XMLElement* tm = trkpt->FirstChildElement("time");
        if (tm)
        {
            timeString = tm->GetText();
            if (startTimeString == "")
            {
                startTimeString = timeString;
            }
            else
            {
                timeDouble = Functions::string_to_time(timeString, startTimeString);
            }
        }

        tinyxml2::XMLElement* extensions = trkpt->FirstChildElement("extensions");
        if (extensions)
        {
            tinyxml2::XMLElement* powerElem = extensions->FirstChildElement("power");
            if (powerElem)
            {
                pwr = powerElem->DoubleText();
            }
        }
        Point point;
        point.initialize_GPS(lat, lon, alt);
        point.set_power(pwr);
        point.set_time(timeDouble);
        route.push_back(point);
    }

    set_connections_gps();
}

void Track::save_GPX(const std::string& filePath) {
    tinyxml2::XMLDocument doc;

    tinyxml2::XMLElement* gpx = doc.NewElement("gpx");
    gpx->SetAttribute("version", "1.1");
    gpx->SetAttribute("creator", "PowerOptimizer");

    gpx->SetAttribute("xmlns", "http://www.topografix.com/GPX/1/1");
    gpx->SetAttribute("xmlns:xsi", "http://www.w3.org/2001/XMLSchema-instance");
    gpx->SetAttribute("xsi:schemaLocation", "http://www.topografix.com/GPX/1/1 http://www.topografix.com/GPX/1/1/gpx.xsd");

    tinyxml2::XMLElement* trk = doc.NewElement("trk");
    gpx->InsertEndChild(trk);

    tinyxml2::XMLElement* trkseg = doc.NewElement("trkseg");
    trk->InsertEndChild(trkseg);

    for (const auto& point : route)
    {
        tinyxml2::XMLElement* trkpt = doc.NewElement("trkpt");
        trkpt->SetAttribute("lat", point.get_lat());
        trkpt->SetAttribute("lon", point.get_lon());

        tinyxml2::XMLElement* ele = doc.NewElement("ele");
        ele->SetText(point.get_altitude());
        trkpt->InsertEndChild(ele);

        tinyxml2::XMLElement* timeElem = doc.NewElement("time");
        std::string ts = Functions::time_to_string(point.get_time());
        timeElem->SetText(ts.c_str());
        trkpt->InsertEndChild(timeElem);

        tinyxml2::XMLElement* extensions = doc.NewElement("extensions");
        trkpt->InsertEndChild(extensions);

        tinyxml2::XMLElement* powerElem = doc.NewElement("power");
        powerElem->SetText(point.get_power());
        extensions->InsertEndChild(powerElem);

        trkseg->InsertEndChild(trkpt);
    }

    doc.InsertEndChild(gpx);

    doc.SaveFile(filePath.c_str());
}

void Track::clear()
{
    route.clear();
}

void Track::push_gps(double lat, double lon, double alt, double crr, double seaRho)
{
    if (seaRho != SEA_RHO)
        seaRho_global = -1;
    Point p;
    p.initialize_GPS(lat, lon, alt, crr, seaRho);
    route.push_back(p);
    if (route.size() > 1)
        route[route.size() - 2].set_next(&route.back());
    route.back().set_next(nullptr);
}

void Track::push_xy(double x, double y, double alt, double crr, double seaRho)
{
    if (seaRho != SEA_RHO)
        seaRho_global = -1;
    Point p;
    p.initialize_xy(x, y, alt, crr, seaRho);
    route.push_back(p);
    if (route.size() > 1)
        route[route.size() - 2].set_next(&route.back());
    route.back().set_next(nullptr);
}

const Track::Point& Track::operator[](int idx)
{
    if (idx < 0 || idx > route.size()-1)
        throw std::invalid_argument("Invalid index");
    return route[idx];
}

void Track::set_connections_gps()
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

void Track::set_connections_xy()
{
    for (int i = 0; i < route.size() - 1; i++)
    {
        route[i].set_next(&route[i + 1]);
    }
    route.back().set_next(nullptr);
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
    seaRho_global = seaRho;
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

std::list<double> Track::find_corners()
{
    std::list<double> corners;
    for (int i = 0; i < route.size(); i++)
    {
        if (route[i].get_maxSpeed() < route[i].get_speed())
            corners.push_back(i);
    }
    corners.push_back(route.size() - 1);
    return corners;
}

std::list<double> Track::find_corners_speed()
{
    std::list<double> corners;
    for (int i = 0; i < route.size(); i++)
    {
        if (route[i].get_maxSpeed() < route[i].get_speed())
            corners.push_back(route[i].get_maxSpeed());
    }
    corners.push_back(INF);
    return corners;
}

void Track::set_final_speed(Cyclist* c, double v)
{
    int i = route.size() - 1;
    while (route[i].get_speed() > v)
    {
        route[i].set_speed(v);
        route[i].set_power(0);
        v = v + c->get_brakingDeceleration() * route[i - 1].get_next_time();
        i--;
    }
    route[i].set_power(0);
    update_times_only();
}


void Track::update_times_only()
{
    route[0].set_time(0);
    for (int i = 1; i < route.size(); i++)
    {
        route[i].set_time(route[i - 1].get_time() + route[i-1].get_next_time());
    }
}

double Track::get_power(int i) const
{
    return route[i].get_power();
}

void Track::set_power(double P, int i)
{
    if (i < 0 || i > route.size() - 1)
        throw std::invalid_argument("Invalid index");
    route[i].set_power(P);
}

double Track::get_next_time(int i)
{
    return route[i].get_next_time();
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
    route[0].set_time(0);
    for (int i = 0; i < route.size() - 1; i++)
    {
        route[i].set_power(power);
        route[i].update_next(cyclist);
    }
    route.back().set_power(0);
}

double Track::averagePower_weighted(std::function<double(double)> f, std::function<double(double)> f_inv) const
{
    double P_sum=0;
    for (int i = 0; i < route.size()-1; i++)
    {
        if (route[i].get_power() > 0)
            P_sum += f(route[i].get_power()) * route[i].get_next_time();
    }
    double P_avg = f_inv(P_sum / route.back().get_time());
    return P_avg;
}

int Track::size() const
{
    return route.size();
}

double Track::get_seaRho() const
{
    return seaRho_global;
}

void Track::set_wbal(double w, int i)
{
    route[i].set_wbal(w);
}

double Track::get_wbal(int i) const
{
    return route[i].get_wbal();
}

void Track::new_copy(Track* t, int start, int end)
{
    clear();
    if (end < 0 || end >  t->size() - 1)
        end = t->size() - 1;
    for (int i = start; i < end+1; i++)
    {
        route.push_back(t->route[i]);
    }
    set_connections_gps();
}

void Track::copy(Track* t, int start, int end)
{
    if (end < 0 || end >  size() - 1)
        end = size() - 1;
    if (start < 0)
        start = 0;
    int j = 0;
    for (int i = start; i < end+1; i++)
    {
        route[i]=(t->route[j++]);
    }
    set_connections_gps();
}

double Track::get_total_time(int i) const
{
    if (i<0 || i>route.size() - 1)
        i = route.size() - 1;
    return route[i].get_time();
}

void Track::save(std::string filePath) const
{
    std::ofstream outFile(filePath, std::ios::binary);

    if (!outFile) {
        std::cerr << "Error opening file for saving: " << filePath << std::endl;
        return;
    }

    outFile.write(reinterpret_cast<const char*>(&seaRho_global), sizeof(seaRho_global));

    size_t routeSize = route.size();
    outFile.write(reinterpret_cast<const char*>(&routeSize), sizeof(routeSize));

    for (const auto& point : route)
    {
        double lat = point.get_lat();
        double lon = point.get_lon();
        double altitude = point.get_altitude();
        double rho = point.get_rho();
        double crr = point.get_crr();
        double maxSpeed = point.get_maxSpeed();
        double wind_bearing = point.get_wind_bearing();
        double wind_speed = point.get_wind_speed();
        double wind_speed_travel = point.get_wind_speed_travel();
        double power = point.get_power();
        double speed = point.get_speed();
        double time = point.get_time();

        outFile.write(reinterpret_cast<const char*>(&lat), sizeof(double));
        outFile.write(reinterpret_cast<const char*>(&lon), sizeof(double));
        outFile.write(reinterpret_cast<const char*>(&altitude), sizeof(double));
        outFile.write(reinterpret_cast<const char*>(&rho), sizeof(double));
        outFile.write(reinterpret_cast<const char*>(&crr), sizeof(double));
        outFile.write(reinterpret_cast<const char*>(&maxSpeed), sizeof(double));
        outFile.write(reinterpret_cast<const char*>(&wind_bearing), sizeof(double));
        outFile.write(reinterpret_cast<const char*>(&wind_speed), sizeof(double));
        outFile.write(reinterpret_cast<const char*>(&wind_speed_travel), sizeof(double));
        outFile.write(reinterpret_cast<const char*>(&power), sizeof(double));
        outFile.write(reinterpret_cast<const char*>(&speed), sizeof(double));
        outFile.write(reinterpret_cast<const char*>(&time), sizeof(double));
    }

    outFile.close();
}

void Track::load(std::string filePath)
{
    std::ifstream inFile(filePath, std::ios::binary);

    if (!inFile) {
        std::cerr << "Error opening file for loading: " << filePath << std::endl;
        return;
    }

    inFile.read(reinterpret_cast<char*>(&seaRho_global), sizeof(seaRho_global));

    size_t routeSize;
    inFile.read(reinterpret_cast<char*>(&routeSize), sizeof(routeSize));
    route.resize(routeSize);

    for (auto& point : route)
    {
        double lat, lon, altitude, crr, rho, maxSpeed, wind_bearing, wind_speed, wind_speed_travel, power, time, speed;

        inFile.read(reinterpret_cast<char*>(&lat), sizeof(double));
        inFile.read(reinterpret_cast<char*>(&lon), sizeof(double));
        inFile.read(reinterpret_cast<char*>(&altitude), sizeof(double));
        inFile.read(reinterpret_cast<char*>(&rho), sizeof(double));
        inFile.read(reinterpret_cast<char*>(&crr), sizeof(double));
        inFile.read(reinterpret_cast<char*>(&maxSpeed), sizeof(double));
        inFile.read(reinterpret_cast<char*>(&wind_bearing), sizeof(double));
        inFile.read(reinterpret_cast<char*>(&wind_speed), sizeof(double));
        inFile.read(reinterpret_cast<char*>(&wind_speed_travel), sizeof(double));
        inFile.read(reinterpret_cast<char*>(&power), sizeof(double));
        inFile.read(reinterpret_cast<char*>(&speed), sizeof(double));
        inFile.read(reinterpret_cast<char*>(&time), sizeof(double));

        point.initialize_GPS(lat, lon, altitude, crr, rho);
        point.set_maxSpeed(maxSpeed);
        point.set_wind(wind_bearing, wind_speed);
        point.set_power(power);
        point.set_speed(speed);
        point.set_time(time);
    }

    inFile.close();
    set_connections_gps();
}