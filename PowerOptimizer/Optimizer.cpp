#include "Optimizer.h"
#include <algorithm>


const std::function<double(double)> Optimizer::AP = [](double d) { return d; };
const std::function<double(double)> Optimizer::AP_inv = [](double d) { return d; };
const std::function<double(double)> Optimizer::NP = [](double d) { return std::pow(d,4); };
const std::function<double(double)> Optimizer::NP_inv = [](double d) { return std::pow(d, 0.25); };



void Optimizer::improve(const std::function<double(double)>& f, const std::function<double(double)>& f_inv, const std::vector<double>& adj_gradient, double dW, double k)
{
    for (int i = 0; i < adj_gradient.size(); i++)
    {
        double P_new = f_inv(std::max(0.0,f((*_track)[i].get_power()) - k * adj_gradient[i] * dW / _track->get_next_time(i)));
        _track->set_power(P_new, i);
    }
    _track->update_time(*_cyclist);
}

void Optimizer::improve_NP(const std::vector<double>& adj_gradient, double dP)
{
    for (int i = 0; i < adj_gradient.size(); i++)
    {
        double P_new = (*_track)[i].get_power() - adj_gradient[i] * dP;
        _track->set_power(P_new, i);
    }
    _track->update_time(*_cyclist);
}

void Optimizer::adjust_power_f(const std::function<double(double)>& f, const std::function<double(double)>& f_inv, double P_lim, double P_max, double P_eps)
{
    for (int i = 0; i < _track->size() - 1; i++)
    {
        if ((*_track)[i].get_power() < 0)
            _track->set_power(0, i);
    }
    
    double P_avg = _track->averagePower_weighted(f, f_inv);
    if (P_avg <= 0)
    {
        P_lim = 0;
        P_avg = 1;
    }
    
    double maxIters = 100;
    while (std::abs(P_avg - P_lim) > P_eps)
    {
        for (int i = 0; i < _track->size() - 1; i++)
        {
            double P_new = (*_track)[i].get_power() * P_lim / P_avg;
            P_new = P_new < P_max ? P_new : P_max;
            _track->set_power(P_new, i);
        }
        _track->update_time(*_cyclist);
        P_avg = _track->averagePower_weighted(f, f_inv); maxIters--;
        if (maxIters < 0)
            return;
    }
}

void Optimizer::adjust_power_CP(double CP, double W_max, double W_start, double W_end, const std::vector<double>& dP, const std::vector<double>& gradient, double P_max, double W_eps)
{
    for (int i = 0; i < _track->size() - 1; i++)
    {
        if ((*_track)[i].get_power() < 0)
            _track->set_power(0, i);
    }

    std::vector<double> W = W_balance(CP, W_max, W_start);

    bool changed = true;
    int maxIters = 100000;
    while (changed && maxIters>0)
    {
        if (maxIters == 1)
            changed = false;
        changed = false;

        /// non negative W
        for (int i = 0; i < W.size(); i++)
        {
            if (W[i] < -W_eps)
            {
                if (changed == false) { maxIters--; changed = true; }

                double invGradientSum = 0;
                for (int j = 0; j < i; j++)
                {
                    invGradientSum += 1 / gradient[j];
                }

                double dW = -W[i] / invGradientSum;
                for (int j = 0; j < i; j++)
                {
                    double Pnew = _track->get_power(j) - dW / gradient[j] / _track->get_next_time(j);
                    Pnew = Pnew > 0 ? Pnew : 0;
                    _track->set_power(Pnew, /**/ j);
                }
                W = W_balance(CP, W_max, W_start);
            }
        }

        /// different W at the end (usualy want W>0 example)

        if (std::abs(W.back() - W_end) > W_eps)
        {
            if (changed == false) { maxIters--; changed = true; }

            double gradientSum = 0;
            for (int j = 0; j < gradient.size(); j++)
            {
                gradientSum += gradient[j];
            }

            double dW = (W.back()-W_end) / gradientSum;
            for (int j = 0; j < _track->size()-1; j++)
            {
                double Pnew = _track->get_power(j) + dW * gradient[j] / _track->get_next_time(j);
                Pnew = Pnew > P_max ? P_max : Pnew;
                _track->set_power(Pnew, /**/ j);
            }
            W = W_balance(CP, W_max, W_start);
        }

        /// non Max W except 1st point

        for (int i = W.size() - 2; i  > 0; i--)
        {
            if (W[i] > W_max + W_eps)
            {
                if (changed == false) {maxIters--;changed = true;}

                double gradientSum = 0;
                for (int j = 0; j < i; j++)
                {
                    gradientSum += gradient[j];
                }

                double dW = (W[i] - W_max) / gradientSum;
                for (int j = 0; j < i; j++)
                {
                    double Pnew = _track->get_power(j) + dW * gradient[j] / _track->get_next_time(j);
                    Pnew = Pnew > P_max ? P_max : Pnew;
                    _track->set_power(Pnew, /**/ j);
                }
                W = W_balance(CP, W_max, W_start);
            }
        }
    }
    _track->update_time(*_cyclist);
}

std::vector<double> Optimizer::W_balance(double CP, double W_max, double W_start)
{
    std::vector<double> W;
    W.reserve(_track->size());
    W.push_back(W_start);
    _track->set_wbal(W_start, 0);
    for (int i = 1; i < _track->size(); i++)
    {
        double W_new = W.back() + (CP - _track->get_power(i - 1)) * _track->get_next_time(i - 1);
        W.push_back(W_new);
        _track->set_wbal(W_new, i);
    }
    return W;
}

void Optimizer::optimize_simple_f(const std::function<double(double)>& f, const std::function<double(double)>& f_inv, double v0, double P_lim, double P_max, double dt, double steps, double firstStepDP, double dW, double P_eps, double t_eps)
{
    _track->initial_solution(*_cyclist, P_lim, v0);

    std::vector<double> dP = calculate_dP(f, f_inv, dW);
    std::vector<double> gradient = calculate_gradient(f, f_inv, dt, dW, dP);
    std::vector<double> adj_gradient = adjusted_gradient(gradient);

    double max_dP = 0;
    double max_ag = 0;
    for (int i = 0; i < dP.size(); i++)
    {
        if (std::abs(dP[i]) > max_dP)
            max_dP = std::abs(dP[i]);
        if (std::abs(adj_gradient[i]) > max_ag)
            max_ag = std::abs(adj_gradient[i]);
    }


    double k = (P_lim * firstStepDP)/max_ag/max_dP;

    double oldTime = _track->update_time(*_cyclist);
    while (steps>0)
    {
        dP = calculate_dP(f, f_inv, dW);
        gradient = calculate_gradient(f, f_inv, dt, dW, dP);
        adj_gradient = adjusted_gradient(gradient);

        if (dW == DW_NP)
            improve_NP(adj_gradient, P_lim * firstStepDP / max_ag); //temporal fix till making 1 common method
        else
            improve(f, f_inv, adj_gradient, dW, k);
        adjust_power_f(f, f_inv, P_lim, P_max, P_eps);

        if (oldTime < (*_track).get_total_time() + t_eps)
        {
            k /= 2;
            firstStepDP /= 2;
            steps--;
        }
        oldTime = (*_track).get_total_time();
    }
}

void Optimizer::optimize_simple_CP(double v0, double CP, double W_max, double P_max, double W_start, double W_end, double dt, double steps, double firstStepDP, double dW, double W_eps)
{
    _track->initial_solution(*_cyclist, CP,v0);

    std::vector<double> dP = calculate_dP(AP, AP_inv, dW);
    std::vector<double> gradient = calculate_gradient(AP, AP_inv, dt, dW, dP);
    std::vector<double> adj_gradient = adjusted_gradient(gradient);

    double max_dP = 0;
    double max_ag = 0;
    for (int i = 0; i < dP.size(); i++)
    {
        if (std::abs(dP[i]) > max_dP)
            max_dP = std::abs(dP[i]);
        if (std::abs(adj_gradient[i]) > max_ag)
            max_ag = std::abs(adj_gradient[i]);
    }


    double k = (CP + W_max / _track->get_total_time()) * firstStepDP / max_ag / max_dP;

    double oldTime = _track->update_time(*_cyclist);
    while (steps > 0)
    {
        dP = calculate_dP(AP, AP_inv, dW);
        gradient = calculate_gradient(AP, AP_inv, dt, dW, dP);
        adj_gradient = adjusted_gradient(gradient);

        improve(AP,AP_inv,adj_gradient, dW, k);
        adjust_power_CP(CP, W_max, W_start, W_end, dP, gradient, P_max, W_eps);

        if (oldTime < (*_track).get_total_time())
        {
            k /= 2;
            steps--;
        }
        oldTime = (*_track).get_total_time();
    }
}


void Optimizer::optimize_f(const std::function<double(double)>& f, const std::function<double(double)>& f_inv, double P_lim, double P_max, double dt, double steps, double firstStepDP, double dW, double P_eps, double t_eps)
{
    _track->set_corners(*_cyclist);

    optimize_simple_f(f, f_inv, V0, P_lim, P_max, dt, steps, firstStepDP, dW, P_eps, t_eps);

    std::list<double> corners_idx = _track->find_corners();
    std::list<double> corners_v = _track->find_corners_speed();

    Track t;
    Optimizer o(&t, _cyclist);

    int start = 0;
    int end = corners_idx.front();
    double v_start = V0;
    double v_end = corners_v.front();
    if (corners_idx.size() == 1)
        corners_idx.pop_front();
    while (!corners_idx.empty())
    {
        end = corners_idx.front();
        while (!corners_idx.empty() && corners_idx.front() < end + 4)
        {
            end = corners_idx.front();
            corners_idx.pop_front();
            v_end = v_end < corners_v.front() ? v_end : corners_v.front();
            corners_v.pop_front();
        }
        
        t.new_copy(_track, start, end);
        t.update_times_only();
        double P_lim = t.averagePower_weighted(f, f_inv);
        o.optimize_simple_f(f, f_inv, v_start, P_lim, P_max, dt, steps, firstStepDP, dW, P_eps, t_eps);
        t.set_final_speed(_cyclist, v_end); 
        _track->copy(&t, start, end);
        _track->update_times_only();
        
        start = end + 1;
        v_start = v_end;
        v_end = INF;
    }
    _track->update_times_only();
}

void Optimizer::optimize_CP(double CP, double W_max, double P_max, double dt, double steps, double firstStepDP, double dW, double W_eps)
{
    _track->set_corners(*_cyclist);

    optimize_simple_CP(V0, CP, W_max, P_max, W_max, 0, dt, steps, firstStepDP, dW, W_eps);

    std::list<double> corners_idx = _track->find_corners();
    std::list<double> corners_v = _track->find_corners_speed();

    Track t;
    Optimizer o(&t, _cyclist);

    int start = 0;
    int end = corners_idx.front();
    double v_start = V0;
    double v_end = corners_v.front();
    if (corners_idx.size() == 1)
        corners_idx.pop_front();
    while (!corners_idx.empty())
    {
        end = corners_idx.front();
        while (!corners_idx.empty() && corners_idx.front() < end + 4)
        {
            end = corners_idx.front();
            corners_idx.pop_front();
            v_end = v_end < corners_v.front() ? v_end : corners_v.front();
            corners_v.pop_front();
        }
        
        t.new_copy(_track, start, end);
        t.update_times_only();
        double W_start = t.get_wbal(0);
        double W_end = t.get_wbal(t.size() - 1); _track->save_GPX("gpx/0.gpx");
        o.optimize_simple_CP(v_start, CP, W_max, P_max, W_start, W_end, dt, steps, firstStepDP, dW, W_eps);
        t.set_final_speed(_cyclist, v_end);
        _track->copy(&t, start, end);
        _track->update_times_only();
        
        start = end + 1;
        v_start = v_end;
        v_end = INF;
    }
    _track->update_times_only();
}

std::vector<double> Optimizer::calculate_dP(const std::function<double(double)>& f, const std::function<double(double)>& f_inv, double dW)
{
    std::vector<double> dP;
    dP.reserve(_track->size() - 1);
    for (int i = 0; i < _track->size() - 1; i++)
    {
        double P = (*_track)[i].get_power();
        double dp = f_inv(dW / (*_track)[i].get_next_time() + f(P)) - P;
        dP.push_back(dp);
    }
    return dP;
}

std::vector<double> Optimizer::calculate_gradient(const std::function<double(double)>& f, const std::function<double(double)>& f_inv, double dt, double dW, std::vector<double> dP)
{
    if (dP.size() != _track->size() - 1)
    {
        dP = calculate_dP(f, f_inv, dW);
    }

    std::vector<double> gradient;
    gradient.reserve(_track->size() - 1);

    double oldTime = _track->update_time(*_cyclist);
    double newTime = oldTime;
    for (int i = 0; i < _track->size() - 1; i++)
    {
        double P = (*_track)[i].get_power();
        _track->set_power(P + dP[i], i);
        int j = i;
        if (dt < 0)
        {
            j = _track->size() - 1;
        }
        else
        {
            double startTime = (*_track)[i].get_time();;
            while (j < _track->size() - 1 && (*_track)[j].get_time() - dt < startTime)
                j++;
        }
        oldTime = (*_track)[j].get_time();
        newTime = _track->update_time(*_cyclist, i, j);
        gradient.push_back(newTime-oldTime);
        _track->set_power(P, i);
        _track->update_time(*_cyclist, i, j);
    }

    return gradient;
}

std::vector<double> Optimizer::adjusted_gradient(const std::vector<double>& gradient)
{
    double sum = 0;
    for (double i : gradient)
    {
        sum += i;
    }
    double avg = sum / gradient.size();
    std::vector<double> adj_gradient;
    adj_gradient.reserve(gradient.size());
    for (int i = 0; i < gradient.size(); i++)
    {
        adj_gradient.push_back(gradient[i] - avg);
    }
    return adj_gradient;
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

void Optimizer::solve_AP(double P_lim, double P_max, double dt, double steps, double firstStepDP, double dW, double P_eps, double t_eps)
{
    optimize_f(AP, AP_inv, P_lim, P_max, dt, steps, firstStepDP, dW, P_eps, t_eps);
    double ap = _track->averagePower_weighted(AP, AP_inv);
    double np = _track->averagePower_weighted(NP, NP_inv);
    double tim = _track->get_total_time();
}

void Optimizer::solve_NP(double P_lim, double P_max, double dt, double steps, double firstStepDP, double dW, double P_eps, double t_eps)
{
    optimize_f(NP, NP_inv, P_lim, P_max, dt, steps, firstStepDP, dW, P_eps, t_eps);
    double ap = _track->averagePower_weighted(AP, AP_inv);
    double np = _track->averagePower_weighted(NP, NP_inv);
    double tim = _track->get_total_time();
}

void Optimizer::solve_CP(double CP, double W, double P_max, double dt, double steps, double firstStepDP, double dW, double W_eps)
{
    optimize_CP(CP, W, P_max, dt, steps, firstStepDP, dW, W_eps);
    double ap = _track->averagePower_weighted(AP, AP_inv);
    double np = _track->averagePower_weighted(NP, NP_inv);
    double tim = _track->get_total_time();
    auto Wb = W_balance(CP, W, W);
}