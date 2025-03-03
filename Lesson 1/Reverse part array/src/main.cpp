#include <iostream>
#include <vector>
#include <ReversePartArray.hpp>

int main() {
    size_t size_array = 0, k = 0;
    std::cin >> size_array >> k;
    std::vector<int> arr;
    for (size_t i = 0; i < size_array; ++i) {
        int x = 0;
        std::cin >> x;
        arr.push_back(x);
    }

    Artur99M::reversePartArray(arr, k);

    for (size_t i = 0; i < size_array; ++i) {
        std::cout << arr[i] << ' ';
    }
}
