#include "Copy.h"
#include <ctime>
#include <cmath>
#include <algorithm>
#include <chrono>
#include <cstring>
#include <iostream>

const size_t SIZE{200000000UL};

int main() {
    double* my_array = new double[SIZE];

//    srand(time(nullptr));
    for (auto i {0UL}; i < SIZE; ++i) {
        my_array[i] = rand() % 1000 / 1.67;
//        std::cout << value << ' ';
    }

    std::cout << "\n\n";

    double* your_array = new double[SIZE];

    auto before = std::chrono::steady_clock::now();

    copy<double, SIZE>(your_array, my_array);

    auto after = std::chrono::steady_clock::now() - before;
    std::cout << std::chrono::duration_cast<std::chrono::microseconds>(after).count() << '\n';


    double* array1 = new double[SIZE];
//    decltype(my_array) array2{};

    auto before1 = std::chrono::steady_clock::now();

    std::memcpy(array1, your_array, SIZE*sizeof (double));

    auto after1 = std::chrono::steady_clock::now() - before1;
    std::cout << std::chrono::duration_cast<std::chrono::microseconds>(after1).count() << '\n';

    delete[] my_array;
    delete[] your_array;
    delete[] array1;
//    for (auto& value : your_array) {
//        std::cout << value << ' ';
//    }
//    std::cout << "\n\n";

}
