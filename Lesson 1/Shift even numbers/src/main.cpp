#include <iostream>
#include <vector>
#include "shift_even.hpp"

int main() {
    size_t size;
    std::cin >> size;
    std::vector<int> arr;
    for (size_t i = 0; i < size; ++i) {
        int x;
        std::cin >> x;
        arr.push_back(x);
    }

    Artur99M::shift_evem_in_front(arr);
    for (size_t i = 0; i < size; ++i) {
        std::cout << arr[i] << ' ';
    }


}
