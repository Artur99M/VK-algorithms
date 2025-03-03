#include "zero_in_back.hpp"
#include <iostream>

int main() {
    size_t size;
    std::cin >> size;
    std::vector<int> arr;
    for (size_t i = 0; i < size; ++i) {
        int x = 0;
        std::cin >> x;
        arr.push_back(x);
    }

    Artur99M::zero_in_back(arr);

    for (size_t i = 0; i < size; ++i) {
        std::cout << arr[i] << ' ';
    }
}
