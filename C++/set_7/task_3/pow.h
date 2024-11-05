
#ifndef _pow_o_
#define _pow_o_

#include <cstdio>

template<size_t N>
double pow1(double x) {
    return ((N % 2) ? x : 1) * pow1<N / 2>(x * x);
}

template<>
double pow1<1>(double x) { return x; };

template<>
double pow1<0>(double x) { return 1.0; };

#endif