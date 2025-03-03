#pragma once
#include <vector>
#include <algorithm>

namespace Artur99M {
template<typename T, T zero, T one>
std::vector<T>& sort_binary_array(std::vector<T>& v) {
    size_t left = 0, right = v.size() - 1;

    while (left < right) {
        if (v[left] == zero) {
            ++left;
        } else if (v[right] == one) {
            --right;
        } else {
            std::swap(v[left], v[right]);
            ++left;
            --right;
        }
    }
    return v;
}

}//namespace Artur99M
