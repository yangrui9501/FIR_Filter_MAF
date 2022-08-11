# IIR_Filter_MAF

* 2022-08-11
* This is a library to perform `Moving Average Filtering` in real-time.
* Given window size `p`, the `cut-off frequency` is `the sampling frequency divided by p`.
* How to use
```cpp
FIR_Filter_MAF MAF;

/* Initialization */
double _win_size = 10;
MAF.Init(_win_size);

/* Update */
double data_m, data_f;
data_f = MAF.Update(data_m);
```