#pragma once
#include <vector>

namespace Artur99M {

template <typename T>
std::vector<T> mergeArray(const std::vector<T>& v1, const std::vector<T>& v2) {
    size_t i = 0, j = 0,
    sz1 = v1.size(), sz2 = v2.size();
    std::vector<T> merged_array;

    while (i < sz1 && j < sz2) {
        if (v1[i] < v2[j]) {
            merged_array.push_back(v1[i]);
            ++i;
        } else {
            merged_array.push_back(v2[j]);
            ++j;
        }
    }
    while (i < sz1) {
        merged_array.push_back(v1[i]);
        ++i;
    }
    while (j < sz2) {
        merged_array.push_back(v2[j]);
        ++j;
    }

    return merged_array;
}

} //namespace Artur99M
