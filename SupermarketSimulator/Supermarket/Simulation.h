#pragma once

#include <iostream>
#include <ctime>
#include "Queue.h"

class Simulation
{
public:

int start_simulation();

bool run_simulation(int nMinutes);

int get_rand(char lane);

};