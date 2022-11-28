/**
 * @file MovingAverageFilter.h
 * @author Yang-Rui Li (you@domain.com)
 * @brief Moving average filter for signal processing
 * @version 2.0
 * @date 2022-08-11
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#pragma once

#include <Arduino.h>

class MovingAverageFilter
{
public:
    MovingAverageFilter() { memset(this, 0, sizeof(MovingAverageFilter)); }

    void init(int _window_size);
    const double &update(const double &_u_in);

protected:
    int current_idx;
    int p;
    double *u_in;
    double y;
};