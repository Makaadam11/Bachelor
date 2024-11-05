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

/// addition

template<typename LHS, typename RHS>
class AddExpr {
    LHS _lhs;
    RHS _rhs;
public:
    AddExpr(const LHS &l, const RHS &r) : _lhs(l), _rhs(r) {};

    double operator()(double x) {
        return _lhs(x) + _rhs(x);
    }
};

template<typename LHS, typename RHS>
AddExpr<LHS, RHS> operator+(const LHS &l,
                            const RHS &r) {
    return AddExpr<LHS, RHS>(l, r);
}

template<typename LHS>
AddExpr<LHS, Constant> operator+(const LHS &l,
                                 double r) {
    return AddExpr<LHS, Constant>(l, Constant(r));
};

template<typename RHS>
AddExpr<Constant, RHS> operator+(double l,
                                 const RHS &r) {
    return AddExpr<Constant, RHS>(Constant(l), r);
}

/// division

template<typename LHS, typename RHS>
class DivExpr {
    LHS _lhs;
    RHS _rhs;
public:
    DivExpr(const LHS &l, const RHS &r) : _lhs(l), _rhs(r) {};

    double operator()(double x) {
        return _lhs(x) / _rhs(x);
    }
};

template<typename LHS, typename RHS>
DivExpr<LHS, RHS> operator/(const LHS &l,
                            const RHS &r) {
    return DivExpr<LHS, RHS>(l, r);
}

template<typename LHS>
DivExpr<LHS, Constant> operator/(const LHS &l,
                                 double r) {
    return DivExpr<LHS, Constant>(l, Constant(r));
}

template<typename RHS>
DivExpr<Constant, RHS> operator/(double l,
                                 const RHS &r) {
    return DivExpr<Constant, RHS>(Constant(l), r);
}


template<typename Arg>
class SinExpr {
    Arg _arg;
public:
    SinExpr(const Arg &arg) : _arg(arg) {};

    double operator()(double x) { return sin(_arg(x)); }
};

template<typename Arg>
SinExpr<Arg> sin(const Arg &a) {
    return SinExpr<Arg>(a);
}

#endif