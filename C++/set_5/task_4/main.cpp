#include<iostream>

template<typename T, typename U>
class Is_convertible {
    typedef char one;
    typedef struct {
        char c[2];
    } two;

    static one test(U);

    static two test(...);

    static T makeT();

public:
    enum {
        check = sizeof(test(makeT())) == sizeof(one),
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

template<typename T>
struct Strip {
    typedef T arg_t;
    typedef T striped_t;
    typedef T base_t;
    typedef const T const_type;

    typedef T &ref_type;
    typedef T &ref_base_type;
    typedef const T &const_ref_type;


};

template<typename T>
struct Strip<T const> {
    typedef const T arg_t;
    typedef T striped_t;
    typedef typename Strip<T>::base_t base_t;
    typedef T const const_type;

    typedef T const &ref_type;
    typedef T &ref_base_type;
    typedef T const &const_ref_type;


};

template<typename T>
struct Strip<T &> {

    typedef T &arg_t;
    typedef T striped_t;
    typedef typename Strip<T>::base_t base_t;
    typedef base_t const const_type;

    typedef T ref_type;
    typedef base_t &ref_base_type;
    typedef base_t const &const_ref_type;


};


int main4() {

    std::cout << Is_convertible<Strip<const int &>::base_t, int>::same_type << std::endl;
    std::cout << Is_convertible<Strip<const int &>::striped_t, const int>::same_type << std::endl;

    return 0;
}
