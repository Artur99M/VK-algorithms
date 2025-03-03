#pragma once
#include <vector>
#include <algorithm>

namespace Artur99M {

template <typename T = int, T zero = 0>
void zero_in_back(std::vector<T>& arr) {
    for (size_t left = 0, right = arr.size() - 1; left <= right;) {
        if (arr[left] == zero) {
            std::swap(arr[left], arr[right]);
            --right;
        } else {
            ++left;
        }
    }
}
} //namespace Artur99M
