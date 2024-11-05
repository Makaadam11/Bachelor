
#ifndef _inner_
#define _inner_

#include <cstdio>

template<int N>
double inner(double *a, double *b) {
    auto x = (*a) * (*b) + inner<N - 1>(++a, ++b);
    return x;
}

template<>
double inner<1>(double *a, double *b) {
    return (*a) * (*b);
}

template<size_t N, typename T = double>
struct Inner {
    static T dot(T *a, T *b) {
        return (*a) * (*b) + Inner<N - 1, T>::dot(++a, ++b);
    }
};

template<typename T>
struct Inner<1, T> {
    static T dot(T *a, T *b) {
        return (*a) * (*b);
    }
};

template<size_t N, typename T>
T dot(T *a, T *b) {
    auto x = Inner<N, T>::dot(a, b);
    return x;
}

#endif

