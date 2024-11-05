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


template<typename T>
class Variable {
public:
    T operator()(T x) {
        return x;
    }
};


template<typename T>
class Constant {
    T _c;
public:
    explicit Constant(T c) : _c(c) {};

    T operator()(T x) { return _c; }
};

template<typename T, typename R = Variable<T> >
class Expr {
    R _rep;
public:
    Expr() = default;

    explicit Expr(R rep) : _rep(rep) {};

    T operator()(T x) { return _rep(x); }

    R rep() const { return _rep; };
};


/// addition


template<typename T, typename LHS, typename RHS>
class AddExpr {
    LHS _lhs;
    RHS _rhs;
public:
    AddExpr(const LHS &l, const RHS &r) : _lhs(l), _rhs(r) {};

    T operator()(T x) {
        return _lhs(x) + _rhs(x);
    }
};

template<typename T, typename LHS, typename RHS>
Expr<T, AddExpr<T, LHS, RHS> > operator+(const Expr<T, LHS> &l,
                                         const Expr<T, RHS> &r) {
    return Expr<T, AddExpr<T, LHS, RHS> >(AddExpr<T, LHS, RHS>(l.rep(), r.rep()));
}

template<typename T, typename LHS>
Expr<T, AddExpr<T, LHS, Constant<T> > >
operator+(const Expr<T, LHS> &l,
          T r) {
    return Expr<T, AddExpr<T, LHS, Constant<T> > >(AddExpr<T, LHS, Constant<T> >(l.rep(), Constant<T>(r)));
}

template<typename T, typename LHS>
Expr<T, AddExpr<T, Constant<T>, LHS> > operator+(T r,
                                                 const Expr<T, LHS> &l) {
    return Expr<T, AddExpr<T, Constant<T>, LHS> >(AddExpr<T, Constant<T>, LHS>(Constant<T>(r), l.rep()));
}

#endif
