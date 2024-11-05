//
// Created by Mikołaj on 24/05/2022.
// https://wazniak.mimuw.edu.pl/index.php?title=Zaawansowane_CPP/Wyk%C5%82ad_9:_Szablony_wyra%C5%BCe%C5%84
// https://onedrive.live.com/view.aspx?cid=2301eb34d0eafe6b&page=view&resid=2301EB34D0EAFE6B!4272&parId=2301EB34D0EAFE6B!1993&authkey=!AClQInI_iOdOmN8&app=Word
//

#ifndef _functors_
#define _functors_

#include<cmath>

template<typename F>
double integrate(F f, double min, double max, double ds) {
    double integral = .0;
    for (double x = min; x < max; x += ds) {
        integral += f(x);
    }
    return integral * ds;
};


class Variable {
public:
    double operator()(double x) {
        return x;
    }
};


class Constant {
    double _c;
public:
    explicit Constant(double c) : _c(c) {};

    double operator()(double x) const { return _c; }
};

#endif