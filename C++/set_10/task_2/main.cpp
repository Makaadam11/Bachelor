//
// Created by Mikołaj on 06/06/2022.
// https://1drv.ms/w/s!Amv-6tA06wEjpTsCU4E0r3QhIeAM?e=2eMjdL
//

#include <vector>
#include <algorithm>
#include <execution>
#include <mutex>
#include <numeric>
#include <iostream>

int main() {

    /// par
    {
        std::vector<int> vec(10'000'000);
        std::iota(vec.begin(), vec.end(), 0);
        std::vector<int> output;

        std::mutex m;
        const auto start = std::chrono::steady_clock::now();
        std::for_each(std::execution::par, vec.begin(), vec.end(), [&output, &m](int &elem) {
            if (elem % 2 == 0) {
                std::lock_guard<std::mutex> lock{m};
                output.push_back(elem);
            }
        });
        const auto end = std::chrono::steady_clock::now();
        std::cout << "par: " << std::chrono::duration <double, std::milli>(end - start).count() << " ms" << std::endl;
    }

    /// seq
    {
        std::vector<int> vec(10'000'000);
        std::iota(vec.begin(), vec.end(), 0);
        std::vector<int> output;

        const auto start = std::chrono::steady_clock::now();
        std::for_each(std::execution::seq, vec.begin(), vec.end(), [&output](int &elem) {
            if (elem % 2 == 0) {
                output.push_back(elem);
            }
        });
        const auto end = std::chrono::steady_clock::now();
        std::cout << "seq: " << std::chrono::duration <double, std::milli>(end - start).count() << " ms" << std::endl;
    }
}
