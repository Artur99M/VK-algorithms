#pragma once
#include <vector>
#include <algorithm>

namespace Artur99M {

template <typename T>
std::vector<T>& reverseArray(std::vector<T>& v) {
    size_t left = 0, right = v.size() - 1;
    while (left < right) {
        std::swap(v[left], v[right]);
        ++left;
        --right;
    }

    return v;
}

} //namespace Artur99M
