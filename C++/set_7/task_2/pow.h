
#ifndef _pow_
#define _pow_

#include <cstdio>

template<size_t N, size_t M>
struct pow0 {
    enum {
        val = N * pow0<N, M - 1>::val
    };
};

template<size_t N>
struct pow0<N, 0> {
    enum {
        val = 1
    };
};

template<size_t M>
struct pow0<0, M> {
    enum {
        val = 0
    };
};

template<size_t M>
struct pow0<1, M> {
    enum {
        val = 1
    };
};

template<>
struct pow0<0, 0> {
    enum {
        val = 0
    };
};

#endif