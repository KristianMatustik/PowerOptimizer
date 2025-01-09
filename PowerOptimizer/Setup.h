#pragma once
#include <limits>


//DEFAULT VALUES FOR SOME PARAMETERS


//global
#define INF std::numeric_limits<double>::infinity()

//cyclist
#define MASS 80 
#define CDA_TT 0.22
#define CDA_OOS 0.4
#define POWER_OOS 500
#define BRAKING_DECELERATION 2
#define BANKANGLE 30
#define EFFICIENCY 0.97
#define WHEEL_INERTIA 2.5


//track
#define CRR 0.004
#define G 9.8
#define SEA_RHO 1.225

//optimizer
#define P_EPS 1
#define W_EPS 100
#define T_EPS 0.01
#define DW_AP 1
#define DW_NP 1000000
#define STEPS 2
#define DT 5
#define FIRST_STEP 0.1
#define MAX_ITERS 100
#define V0 5
