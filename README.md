# DSP Library: Moving Average Filter

## Introduction

- This library is developed on August 11, 2022.
- This library implements the moving average filter with the window size `p` to conduct the digital signal processing.
- The following example illustrates how to use this library to perform digital signal processing based on the moving average filter.


## Example

```cpp
/* 2022-11-29 */
#include <Arduino.h>
#include <moving_average_filter.h>

double data = 0.0; // Measured data
double data_f = 0.0; // Filtered data
double data_n = 0.0; // Measurement noise (Pseudorandom binary sequence, PRBS)
double t = 0.0; // Current time (virtual)
double T = 0.001; // Sample time

/* Declare MovingAverageFilter object: */
MovingAverageFilter MAF;
int _window_size = 10; // window size of MAF

void setup()
{
    Serial.begin(115200);
    while (!Serial)
    {
    }

    /* Initialize MAF */
    MAF.init(_window_size);

    randomSeed(0);
}

void loop()
{
    static int i; // loop counter

    data_n = (double)(random(-1000, 1000)) / 1000.0;
    t = (double)(i)*T;
    data = sin(2.0 * PI * 1.0 * t) + data_n;

    /* update MAF */
    data_f = MAF.update(data);

    i++;

    /* Print data to software serial */
    Serial.print(String() + data + " " + data_f);
    Serial.println();
    Serial.flush();

    delay(1); // Delay 1 millisecond to simulate 1000 Hz sampling frequency
}
```
