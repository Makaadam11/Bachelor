

#ifndef _sin_
#define _sin_

#include "../task_1/factorial.h"
#include "../task_3/pow.h"
#include "../task_5_6/inner.h"

template<int N>
double sin(double x) {
    return sin<N - 1>(x) + (N % 2 ? 1 : -1) * pow1<(2 * N - 1)>(x) / factorial<2 * N - 1>::val;
}

template<>
double sin<0>(double x) {
    return 0;
}

#endif
