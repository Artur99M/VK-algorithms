#include <iostream>
#include "ReverseArray.hpp"
#include <vector>

int main() {
    size_t size_array = 0;
    std::cin >> size_array;
    std::vector<int> arr;
    for (size_t i = 0; i < size_array; ++i) {
        int x = 0;
        std::cin >> x;
        arr.push_back(x);
    }

    Artur99M::reverseArray(arr);

    for (size_t i = 0; i < size_array; ++i) {
        std::cout << arr[i] << ' ';
    }
}
