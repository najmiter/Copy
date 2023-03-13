#include "Copy.h"
#include <ctime>
#include <cmath>
#include <algorithm>

const size_t SIZE{2000UL};

int main() {
    int64_t my_array[SIZE]{};

    srand(time(nullptr));
    for (auto& value : my_array) {
        value = rand() % 1000 / 1.65;
        std::cout << value << ' ';
    }

    std::cout << "\n\n";

    decltype(my_array) your_array{};

    copy<int64_t, std::size(my_array)>(your_array, my_array);


    for (auto& value : your_array) {
        std::cout << value << ' ';
    }
    std::cout << "\n\n";

}
