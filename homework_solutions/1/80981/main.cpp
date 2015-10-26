#include <cstdio>

float preComp[32] = 
{ 
    0.5, 0.25, 0.125, 0.0625, 0.03125, 0.015625, 0.0078125, 0.00390625,
    0.001953125, 0.0009765625, 0.00048828125, 0.000244140625, 0.0001220703125,
    6.103515625e-05, 3.0517578125e-05, 1.52587890625e-05, 7.62939453125e-06,
    3.814697265625e-06, 1.9073486328125e-06, 9.5367431640625e-07,
    4.76837158203125e-07, 2.38418579101562e-07, 1.19209289550781e-07,
    5.96046447753906e-08, 2.98023223876953e-08, 1.49011611938477e-08,
    7.45058059692383e-09, 3.72529029846191e-09, 1.86264514923096e-09,
    9.31322574615479e-10, 4.65661287307739e-10, 2.3283064365387e-10
};

float derCorput(unsigned n)
{
    float res = 0;
    int pos = 0;
    while(n > 0){
        unsigned i = n & 0x01u;
        res += i*preComp[pos];
        ++pos;
        n >>= 1;
    }
    return res;
}

int main()
{
    for (auto i = 0; i < 20; ++i)
        printf("%f, ", derCorput(i));
    return 0;
}
