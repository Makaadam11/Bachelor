
#include <iostream>
#include "col_fact.h"

int main() {

    ColorFactory factory1;
    ColorFactory<Default_on_error_policy<>> factory2;
    ColorFactory<Default_on_error_policy<1, 1, 1>> factory3;

    try {
        std::cout << "factory1" << std::endl;
        factory1.returnColor("red").print();
    } catch(...) {
        std::cout << "exception caught.\n";
    }

    try {
        std::cout << "factory2" << std::endl;
        factory2.returnColor("red").print();
    } catch(...) {
        std::cout << "exception caught.\n";
    }

    try {
        std::cout << "factory3" << std::endl;
        factory3.returnColor("red").print();
    } catch(...) {
        std::cout << "exception caught.\n";
    }
    return 0;
}
