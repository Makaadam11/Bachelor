#include<vector>
#include<iostream>

template<typename T>
class Is_class {

    typedef char first;
    typedef struct {
        char c[2];
    } second;

    template<typename U>
    static first test(int U::*);

    template<typename U>
    static second test(...);

public:
    enum {
        check = (sizeof(test<T>(nullptr)) == sizeof(first))
    };
};

class X {
};

int main1() {

    std::cout << Is_class<int>::check << std::endl;
    std::cout << Is_class<X>::check << std::endl;
    std::cout << Is_class<std::vector<double> >::check << std::endl;

    return 0;
}
