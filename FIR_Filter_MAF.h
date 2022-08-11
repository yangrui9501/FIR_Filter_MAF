/**
 * @file FIR_Filter_MAF.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 2.0
 * @date 2022-08-11
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <Arduino.h>

class FIR_Filter_MAF
{
public:
    FIR_Filter_MAF() { memset(this, 0, sizeof(FIR_Filter_MAF)); }

    void Init(int _window_size);
    const double &Update(const double &_u_in);

protected:
    int current_idx;
    int p;
    double *u_in;
    double y;
};