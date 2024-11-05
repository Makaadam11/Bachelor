#include<vector>
#include<deque>
#include<iostream>

template<typename T, typename U>
class Is_convertible {
    typedef char first;
    typedef struct {
        char c[2];
    } second;

    static first test(U);

    static second test(...);

    static T makeT();

public:
    enum {
        check = sizeof(test(makeT())) == sizeof(first),
        same_type = false
    };
};

template<typename T>
class Is_convertible<T, T> {
public:
    enum {
        check = true,
        same_type = true
    };
};

int main3() {

    std::cout << Is_convertible<int, double>::check << std::endl;
    std::cout << Is_convertible<double, int>::check << std::endl;

    std::cout << Is_convertible<double, int>::same_type << std::endl;

    std::cout << Is_convertible<size_t, unsigned int>::same_type << std::endl;
    std::cout << Is_convertible<std::vector<double>::value_type, double>::same_type << std::endl;

    std::cout << Is_convertible<std::vector<double>::iterator, double *>::same_type << std::endl;

    return 0;
}
