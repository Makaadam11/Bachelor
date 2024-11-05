#include<vector>
#include<iostream>

template<typename T>
class has_value_type {
    typedef char one;
    typedef struct {
        char c[2];
    } two;

    template<typename U>
    static one test(typename U::value_type);

    template<typename U>
    static two test(...);

public:
    enum {
        check = (sizeof(test<T>(0)) == sizeof(one))
    };
};


class X {
};

int main2() {

    std::cout << has_value_type<int>::check << std::endl;
    std::cout << has_value_type<X>::check << std::endl;
    std::cout << has_value_type<std::vector<double> >::check << std::endl;

    return 0;
}