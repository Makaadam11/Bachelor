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

    /*
     ** count if
     */
    std::cout << "count if" << std::endl;

    /// par
    {
        std::vector<int> vec(100'000'000);
        for (int i = 0; i < 100'000'000; ++i) {
            vec.push_back(i);
        }

        const auto start = std::chrono::steady_clock::now();
        auto result = std::count_if(std::execution::par, vec.begin(), vec.end(), [](int i){return i % 4 == 0;});
        std::cout << "result: " << result << std::endl;
        const auto end = std::chrono::steady_clock::now();
        std::cout << "par: " << std::chrono::duration <double, std::milli>(end - start).count() << " ms" << std::endl;
    }

    /// seq
    {
        std::vector<int> vec(100'000'000);
        for (int i = 0; i < 100'000'000; ++i) {
            vec.push_back(i);
        }

        const auto start = std::chrono::steady_clock::now();
        auto result = std::count_if(std::execution::seq, vec.begin(), vec.end(), [](int i){return i % 4 == 0;});
        std::cout << "result: " << result << std::endl;
        const auto end = std::chrono::steady_clock::now();
        std::cout << "seq: " << std::chrono::duration <double, std::milli>(end - start).count() << " ms" << std::endl;
    }

    /*
     ** remove if
     */
    std::cout << "remove if" << std::endl;

    /// par
    {
        std::vector<int> vec(100'000'000);
        for (int i = 0; i < 100'000'000; ++i) {
            vec.push_back(i);
        }

        const auto start = std::chrono::steady_clock::now();
        std::remove_if(std::execution::par, vec.begin(), vec.end(), [](int i){return i % 4 == 0;});
        const auto end = std::chrono::steady_clock::now();
        std::cout << "par: " << std::chrono::duration <double, std::milli>(end - start).count() << " ms" << std::endl;
        for (int i = 0; i < 100; ++i) {
            std::cout << vec[i] << " ";
        }
        std::cout << std::endl;
    }

    /// seq
    {
        std::vector<int> vec(100'000'000);
        for (int i = 0; i < 100'000'000; ++i) {
            vec.push_back(i);
        }

        const auto start = std::chrono::steady_clock::now();
        std::remove_if(std::execution::seq, vec.begin(), vec.end(), [](int i){return i % 4 == 0;});
        const auto end = std::chrono::steady_clock::now();
        std::cout << "seq: " << std::chrono::duration <double, std::milli>(end - start).count() << " ms" << std::endl;
        for (int i = 0; i < 100; ++i) {
            std::cout << vec[i] << " ";
        }
        std::cout << std::endl;
    }

    /*
     ** min element
     */
    std::cout << "min element" << std::endl;

    /// par
    {
        std::vector<int> vec(100'000'000);
        for (int i = 0; i < 100'000'000; ++i) {
            vec.push_back(i);
        }

        const auto start = std::chrono::steady_clock::now();
        auto result = std::min_element(std::execution::par, vec.begin(), vec.end());
        std::cout << "result: " << std::distance(vec.begin(), result) << std::endl;
        const auto end = std::chrono::steady_clock::now();
        std::cout << "par: " << std::chrono::duration <double, std::milli>(end - start).count() << " ms" << std::endl;
    }

    /// seq
    {
        std::vector<int> vec(100'000'000);
        for (int i = 0; i < 100'000'000; ++i) {
            vec.push_back(i);
        }

        const auto start = std::chrono::steady_clock::now();
        auto result = std::min_element(std::execution::seq, vec.begin(), vec.end());
        std::cout << "result: " << std::distance(vec.begin(), result) << std::endl;
        const auto end = std::chrono::steady_clock::now();
        std::cout << "seq: " << std::chrono::duration <double, std::milli>(end - start).count() << " ms" << std::endl;
    }

    /*
     ** max element
     */
    std::cout << "max element" << std::endl;

    /// par
    {
        std::vector<int> vec(100'000'000);
        for (int i = 0; i < 100'000'000; ++i) {
            vec.push_back(i);
        }

        const auto start = std::chrono::steady_clock::now();
        auto result = std::max_element(std::execution::par, vec.begin(), vec.end());
        std::cout << "result: " << std::distance(vec.begin(), result) << std::endl;
        const auto end = std::chrono::steady_clock::now();
        std::cout << "par: " << std::chrono::duration <double, std::milli>(end - start).count() << " ms" << std::endl;
    }

    /// seq
    {
        std::vector<int> vec(100'000'000);
        for (int i = 0; i < 100'000'000; ++i) {
            vec.push_back(i);
        }

        const auto start = std::chrono::steady_clock::now();
        auto result = std::max_element(std::execution::seq, vec.begin(), vec.end());
        std::cout << "result: " << std::distance(vec.begin(), result) << std::endl;
        const auto end = std::chrono::steady_clock::now();
        std::cout << "seq: " << std::chrono::duration <double, std::milli>(end - start).count() << " ms" << std::endl;
    }

    /*
     ** is sorted
     */
    std::cout << "is sorted" << std::endl;

    /// par
    {
        std::vector<int> vec(100'000'000);
        for (int i = 0; i < 100'000'000; ++i) {
            vec.push_back(i);
        }

        const auto start = std::chrono::steady_clock::now();
        auto result = std::is_sorted(std::execution::par, vec.begin(), vec.end());
        std::cout << "result: " << result << std::endl;
        const auto end = std::chrono::steady_clock::now();
        std::cout << "par: " << std::chrono::duration <double, std::milli>(end - start).count() << " ms" << std::endl;
    }

    /// seq
    {
        std::vector<int> vec(100'000'000);
        for (int i = 0; i < 100'000'000; ++i) {
            vec.push_back(i);
        }

        const auto start = std::chrono::steady_clock::now();
        auto result = std::is_sorted(std::execution::seq, vec.begin(), vec.end());
        std::cout << "result: " << result << std::endl;
        const auto end = std::chrono::steady_clock::now();
        std::cout << "seq: " << std::chrono::duration <double, std::milli>(end - start).count() << " ms" << std::endl;
    }
}
