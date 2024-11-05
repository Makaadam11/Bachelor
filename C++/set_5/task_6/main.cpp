//
// Created by Mikołaj on 26/04/2022.
// https://onedrive.live.com/view.aspx?resid=2301EB34D0EAFE6B!3767&ithint=file%2cdocx&authkey=!APsI3JrmQ1Fv1tI
// https://wazniak.mimuw.edu.pl/index.php?title=Zaawansowane_CPP/Wyk%C5%82ad_6:_Funkcje_typ%C3%B3w_i_inne_sztuczki
//

#include <iostream>

template<typename H, typename T>
struct Type_list {
    typedef H head;
    typedef T tail;
};

class Null_type {
};

template<typename T>
struct Length;
template<>
struct Length<Null_type> {
    enum {
        value = 0
    };
};

template<typename H, typename T>
struct Length<Type_list<H, T> > {
    enum {
        value = 1 + Length<T>::value
    };
};


template<int N, typename T>
struct At {
    typedef typename At<N - 1, typename T::Tail>::Result Result;
};

template<typename T>
struct At<1, T> {
    typedef typename T::Head Result;
};

template<typename T, typename TL>
struct In {
    enum {
        yes = In<T, typename TL::Tail>::yes
    };
};

template<typename T, typename Tail>
struct In<T, Type_list<T, Tail> > {
    enum {
        yes = 1
    };
};

template<typename T>
struct In<T, Null_type> {
    enum {
        yes = 0
    };
};

class X {
};

int main() {

    typedef Type_list<int, Null_type> T1;
    typedef Type_list<double, T1> T2;
    typedef Type_list<float, T2> T3;

    std::cout << Length<T1>::value << " ";
    std::cout << Length<T2>::value << " ";
    std::cout << Length<T3>::value << "\n";
}
