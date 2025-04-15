#include "shell_sort.hpp"
#include <iostream>
#include <vector>


int main() {
    size_t sz;
    std::cin >> sz;
    std::vector<int> arr;
    arr.reserve(sz);
    for (size_t i = 0; i < sz; ++i) {
        int x;
        std::cin >> x;
        arr.push_back(x);
    }
    shell_sort(arr);
    for (int x : arr)
        std::cout << x << ' ';
}
