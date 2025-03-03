#pragma once
#include "ReverseArray.hpp"
#include <vector>

namespace Artur99M {
template <typename T>
std::vector<T>& reverseArray(std::vector<T>& v, size_t left, size_t right) {
    while (left < right) {
        std::swap(v[left], v[right]);
        ++left;
        --right;
    }

    return v;
}
template <typename T>
std::vector<T>& reversePartArray(std::vector<T>& v, size_t k) {
    size_t n = v.size();
    k = k % n;
    if (k == 0) return v;
    reverseArray(v);
    reverseArray(v, 0, k - 1);
    reverseArray(v, k, n - 1);

    return v;
}

} // namespace Artur99M
