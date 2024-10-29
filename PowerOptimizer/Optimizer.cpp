#include "Optimizer.h"
#include <algorithm>


const std::function<double(double)> Optimizer::AP = [](double d) { return d; };
const std::function<double(double)> Optimizer::AP_inv = [](double d) { return d; };
const std::function<double(double)> Optimizer::NP = [](double d) { return std::pow(d,4); };
const std::function<double(double)> Optimizer::NP_inv = [](double d) { return std::pow(d, 0.25); };



void Optimizer::adjust_power_f(std::function<double(double)> f, std::function<double(double)> f_inv, double P_lim, double P_max)
{
    double P_avg = _track->averagePower_weighted(f, f_inv);
    if (P_avg <= 0)
        return;
    for (int i = 0; i < _track->size() - 1; i++)
    {
        double P_new =(*_track)[i].get_power() * P_lim / P_avg;
        P_new = P_new < P_max ? P_new : P_max;
        _track->set_power(P_new, i);
    }
}

void Optimizer::optimize_simple_f(std::function<double(double)> f, std::function<double(double)> f_inv, double P_lim, double P_max, double iters, double r, double dp)
{
    _track->initial_solution(*_cyclist, P_lim);

    double DP = P_lim * dp/100;
    for (int i = 0; i < iters; i++)
    {
        std::vector<double> gradient = calculate_gradient(f, f_inv);
        std::vector<int> adjustment = gradient_to_adjustment(gradient);
        for (int j = 0; j < _track->size()-1; j++)
        {
            double P_new = (*_track)[j].get_power() + adjustment[j] * DP;
            P_new = P_new < P_max ? P_new : P_max;
            P_new = P_new > 0 ? P_new : 0;
            _track->set_power(P_new, j);
        }
        _track->update_time(*_cyclist);
        adjust_power_f(f, f_inv, P_lim, P_max);
        _track->update_time(*_cyclist);
        DP *= r;
    }
}

void Optimizer::optimize_f(std::function<double(double)> f, std::function<double(double)> f_inv, double P_lim, double P_max, double iters, double r, double dp)
{
    optimize_simple_f(f, f_inv, P_lim, P_max, iters, r, dp);
}

std::vector<double> Optimizer::calculate_gradient(std::function<double(double)> f, std::function<double(double)> f_inv, double t, double dp)
{
    std::vector<double> gradient;
    gradient.reserve(_track->size() - 1);
    double oldTime = _track->update_time(*_cyclist);
    double newTime = oldTime;
    for (int i = 0; i < _track->size() - 1; i++)
    {
        double P = (*_track)[i].get_power();
        _track->set_power(f_inv(f(P) + dp / (*_track)[i].get_next_time()), i);

        if (t < 0)
        {
            newTime = _track->update_time(*_cyclist, i);
            gradient.push_back(oldTime - newTime);
            _track->set_power(P, i);
            _track->update_time(*_cyclist, i);
        }
        else
        {
            double startTime = (*_track)[i].get_time();;
            int j = i;
            while (j < _track->size() - 1 && (*_track)[j].get_time() - t < startTime)
                j++;
            oldTime = (*_track)[j].get_time();
            newTime = _track->update_time(*_cyclist, i, j);
            gradient.push_back(oldTime - newTime);
            _track->set_power(P, i);
            _track->update_time(*_cyclist, i, j);
        }
    }

    return gradient;
}

std::vector<int> Optimizer::gradient_to_adjustment(const std::vector<double>& gradient)
{
    std::vector<double> temp = gradient;

    double median;
    size_t n = temp.size() / 2;

    if (temp.size() % 2 == 1) {
        std::nth_element(temp.begin(), temp.begin() + n, temp.end());
        median = temp[n];
    }
    else
    {
        std::nth_element(temp.begin(), temp.begin() + n - 1, temp.end());
        double left_middle = temp[n - 1];
        std::nth_element(temp.begin(), temp.begin() + n, temp.end());
        double right_middle = temp[n];
        median = (left_middle + right_middle) / 2;
    }

    std::vector<int> result;
    result.reserve(gradient.size());
    for (int i = 0; i < gradient.size(); i++)
    {
        if (gradient[i] > median)
            result.push_back(1);
        else if (gradient[i] < median)
            result.push_back(-1);
        else
            result.push_back(0);
    }

    return result;
}

Optimizer::Optimizer() : _cyclist(nullptr), _track(nullptr)
{
    
}

Optimizer::Optimizer(Track* track, Cyclist* cyclist) : _track(track), _cyclist(cyclist)
{

}

Optimizer::~Optimizer()
{

}

Cyclist*& Optimizer::cyclist()
{
    return _cyclist;
}

Track*& Optimizer::track()
{
    return _track;
}

std::vector<double> Optimizer::calculate_gradient_AP(double t, double dp)
{
    return calculate_gradient(AP, AP_inv, t, dp);
}

std::vector<double> Optimizer::calculate_gradient_NP(double t, double dp)
{
    return calculate_gradient(NP,NP_inv,t,dp);
}

void Optimizer::solve_AP(double P_lim, double P_max, double iters, double r, double dp)
{
    optimize_f(AP, AP_inv, P_lim, P_max, iters, r, dp);
}

void Optimizer::solve_NP(double P_lim, double iters, double r, double dp)
{
    optimize_f(NP, NP_inv, P_lim, iters, r, dp);
}