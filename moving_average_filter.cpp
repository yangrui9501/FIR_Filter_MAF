#include "moving_average_filter.h"

void MovingAverageFilter::init(int _window_size)
{
    p = _window_size;
    u_in = new double[p];
    memset(u_in, 0, sizeof(double) * p);
}

const double &MovingAverageFilter::update(const double &_u_in)
{
    u_in[current_idx] = _u_in;

    y = 0.0;
    for (int i = 0; i < p; i++)
    {
        y += u_in[i];
    }
    y = y / (double)(p);

    current_idx++;

    if (current_idx == p)
    {
        current_idx = 0;
    }

    return y;
}