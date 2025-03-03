#include <iostream>
#include "sort10.hpp"
#include <vector>

int main() {
    size_t size_array = 0;
    std::cin >> size_array;
    std::vector<int> arr;
    arr.reserve(size_array);
    for (size_t i = 0; i < size_array; ++i) {
        int x;
        std::cin >> x;
        arr.push_back(x);
    }

    Artur99M::sort_binary_array<int, 0, 1>(arr);

    for (size_t i = 0; i < size_array; ++i) {
        std::cout << arr[i] << ' ';
    }

}
