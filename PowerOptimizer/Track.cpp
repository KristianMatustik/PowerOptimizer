#include "Track.h"
#include "Functions.h"

Track::Point::Point()
{

}

Track::Point::~Point()
{

}

double Track::Point::update(Point& next, Cyclist rider)
{
    double m = rider.get_mass();

    std::pair<double,double> wind = Functions::addVectors(wind_bearing,wind_speed,Functions::normalizeAngle(next_bearing-180),speed);
    double yaw = Functions::yaw(wind.first, Functions::normalizeAngle(next_bearing - 180));

    double cda = rider.CdA(yaw, power);

    next.kineticEnergy = kineticEnergy
        + power * time_to_next() * rider.get_efficiency()
        + Functions::energy_potential(m, altitude) - Functions::energy_potential(m, next.altitude)
        - Functions::force_aero(rho, rider.CdA(0, 0), speed + wind_speed_travel) * next_distance
        - Functions::force_roll(m * g, crr) * next_distance;
    next.speed = Functions::speed_fromKE(m,next.kineticEnergy);
    next.time = time + time_to_next();

    return 0;
}

double Track::Point::time_to_next()
{
    return next_distance / speed;
}



//////// Track
 


Track::Track()
{

}

Track::~Track()
{

}

void Track::loadGPX(std::string filePath)
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
        Point point;
        point.lat = trkpt->DoubleAttribute("lat");
        point.lon = trkpt->DoubleAttribute("lon");

        tinyxml2::XMLElement* ele = trkpt->FirstChildElement("ele");
        double altitude = 0;
        if (ele)
        {
            point.altitude = ele->DoubleText();
        }

        tinyxml2::XMLElement* extensions = trkpt->FirstChildElement("extensions");
        if (extensions)
        {
            tinyxml2::XMLElement* powerElem = extensions->FirstChildElement("power");
            if (powerElem) {
                point.power = powerElem->DoubleText();  // Read power value
            }
        }
        if (route.size() == 0)
        {
            point.x = 0;
            point.y = 0;
        }
        else
        {
            point.x = Functions::distance(route[0].lat, point.lon, route[0].lat, route[0].lon) * (route[0].lon < point.lon ? 1 : -1);
            point.y = Functions::distance(point.lat, route[0].lon, route[0].lat, route[0].lon) * (route[0].lat < point.lat ? 1 : -1);
        }
        route.push_back(point);
    }
    calculate_distances();
}


void Track::set_crr(double crr)
{
    for (int i = 0; i < route.size(); i++)
    {
        route[i].crr = crr;
    }
}

void Track::set_wind(double bearing, double speed)
{
    for (int i = 0; i < route.size(); i++)
    {
        route[i].wind_bearing = bearing;
        route[i].wind_speed = speed;
        route[i].wind_speed_travel = std::cos(180 - bearing - route[i].next_bearing) * speed;
    }
}

void Track::set_rho(double seaRho)
{
    for (int i = 0; i < route.size(); i++)
    {
        route[i].rho = seaRho * (11000 - route[i].altitude) / 11000;
    }
}

void Track::calculate_distances()
{
    for (int i = 0; i < route.size() - 1; i++)
    {
        double lat1 = route[i].lat;
        double lon1 = route[i].lon;
        double lat2 = route[i + 1].lat;
        double lon2 = route[i + 1].lon;

        route[i].next_distance = Functions::distance(lat1, lon1, lat2, lon2);
        route[i].next_bearing = Functions::bearing(lat1, lon1, lat2, lon2);
    }
}

void Track::initialize(Cyclist rider, double v0)
{
    for (int i = 0; i < route.size()-1; i++)
    {
        route[i].power = 0;
        route[i].kineticEnergy = 0;
        route[i].speed = 0;
        route[i].time = 0;
    }
    route[0].kineticEnergy = Functions::energy_kinetic(rider.get_mass(), v0);
    route[0].speed = v0;
    set_rho();
    set_crr(0.004);
}

void Track::load(std::string filename)
{

}

void Track::save(std::string filename)
{

}

void Track::update_time(Cyclist rider)
{
    for (int i = 0; i < route.size()-1; i++)
    {
        route[i].update(route[i + 1], rider);
    }
}

void Track::test()
{
    Cyclist rider;
    rider.set_CdA(std::vector<double>{0.2}, std::vector<double>{}, 0.4, 350);
    rider.set_mass(80);
    rider.set_efficiency(0.98);

    loadGPX("test.gpx");
    initialize(rider);
    for (int i = 0; i < route.size() - 1; i++)
    {
        route[i].power = 300;
    }
    update_time(rider);
}