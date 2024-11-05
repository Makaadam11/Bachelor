//
// Created by Mikołaj on 06/06/2022.
// https://1drv.ms/w/s!Amv-6tA06wEjpTsCU4E0r3QhIeAM?e=2eMjdL
// https://stackoverflow.com/questions/39954678/difference-between-execution-policies-and-when-to-use-them

#include <iostream>
#include <vector>
#include <execution>
#include <mutex>

int main() {
    std::cout << "Hello, World!" << std::endl;

    std::vector<int> v;
    for (int i = 0; i < 1000; ++i) {
        v.push_back(i);
    }
    int sum = 0;

    /// std::execution::sequenced_policy

    /// The execution policy type used as a unique type to disambiguate parallel algorithm overloading and require that
    /// a parallel algorithm's execution may not be parallelized. The invocations of element access functions in
    /// parallel algorithms invoked with this policy (usually specified as std::execution::seq) are indeterminately
    /// sequenced in the calling thread.

    std::cout << "seq" << std::endl;
    std::for_each(std::execution::seq, std::begin(v), std::end(v), [&](int i) {
        std::cout << i <<  " ";
        sum += i*i;
    });
    std::cout << "sum: " << sum << " " << std::endl << std::endl;

    /// std::execution::parallel_policy

    /// The execution policy type used as a unique type to disambiguate parallel algorithm overloading and indicate that
    /// a parallel algorithm's execution may be parallelized. The invocations of element access functions in parallel
    /// algorithms invoked with this policy (usually specified as std::execution::par) are permitted to execute in
    /// either the invoking thread or in a thread implicitly created by the library to support parallel algorithm
    /// execution. Any such invocations executing in the same thread are indeterminately sequenced with respect to
    /// each other.

    sum = 0;
    std::mutex m;

    std::cout << "par" << std::endl;
    std::for_each(std::execution::par, std::begin(v), std::end(v), [&](int i) {
        std::lock_guard<std::mutex> lock{m};
        std::cout << i <<  " ";
        sum += i*i;
    });
    std::cout << "sum: " << sum << " " << std::endl << std::endl;

    /// std::execution::parallel_unsequenced_policy,

    /// The execution policy type used as a unique type to disambiguate parallel algorithm overloading and indicate that
    /// a parallel algorithm's execution may be parallelized, vectorized, or migrated across threads (such as by a
    /// parent-stealing scheduler). The invocations of element access functions in parallel algorithms invoked with
    /// this policy are permitted to execute in an unordered fashion in unspecified threads, and unsequenced with
    /// respect to one another within each thread.

    std::cout << "par_unseq" << std::endl;
    std::atomic<int> summ{0};
    std::for_each(std::execution::par_unseq, std::begin(v), std::end(v), [&](int i) {
        std::cout << i <<  " ";
        summ.fetch_add(i*i, std::memory_order_relaxed);
    });
    std::cout << "sum: " << summ << " " << std::endl << std::endl;

    return 0;
}
