#include "Optimizer.h"

Optimizer::Optimizer() = default;

Optimizer::~Optimizer() = default;

std::vector<double> Optimizer::calculate_gradient(double (*f)(double), double (*f_inv)(double), double t, double dp)
{
    std::vector<double> gradient;
    double oldTime = track.update_time(rider);
    double newTime = oldTime;
    for (int i = 0; i < track.size() - 1; i++)
    {
        double P = track[i].get_power();
        track.set_power(f_inv(f(P) + dp / track[i].get_next_time()),i);

        if (t < 0)
        {
            newTime = track.update_time(rider, i);
            gradient.push_back(oldTime - newTime);
            track.set_power(P,i);
            track.update_time(rider, i);
        }
        else
        {
            double startTime = track[i].get_time();;
            int j = i;
            while (j < track.size() - 2 && track[j].get_time() - t < startTime)
                j++;
            oldTime = track[j].get_time();
            newTime = track.update_time(rider, i, j);
            gradient.push_back(oldTime - newTime);
            track.set_power(P,i);
            track.update_time(rider, i, j);
        }
    }

    return gradient;
}