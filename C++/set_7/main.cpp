#include <iostream>
#include <vector>
#include <cmath>

#include "task_1/factorial.h"
#include "task_2/pow.h"
#include "task_3/pow.h"
#include "task_4/sin.h"
#include "task_5_6/inner.h"

int main() {

    /// factorial
    auto result1 = factorial<5>();
    std::cout << result1.val << std::endl;

    /// pow
    auto result2 = pow0<2,8>();
    std::cout << result2.val << std::endl;

    /// powO
    auto result = pow1<8>(2);
    std::cout << result << std::endl;

    /// sin

    auto result4 = sin<2>(2.3);
    std::cout << result4 << std::endl;

    /// inner

    auto vector1 = new double[3];
    vector1[0] = 1.0;
    vector1[1] = 2.0;
    vector1[2] = 3.0;

    auto vector2 = new double[3];
    vector2[0] = 1.0;
    vector2[1] = 2.0;
    vector2[2] = 3.0;

    auto result5 = dot<3, double>(vector1 ,vector2);
    std::cout << result5 << std::endl;

    return 0;
}
