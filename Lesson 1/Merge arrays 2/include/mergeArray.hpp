#pragma once
#include <vector>
#include <iostream>

namespace Artur99M {

template <typename T>
std::vector<T>& merge(std::vector<T>& v1, const std::vector<T>& v2) {
    int sz1 = v1.size(), sz2 = v2.size(),
    sz = sz1 + sz2,
    i = sz1 - 1, j = sz2 - 1, k = sz - 1;
    v1.resize(sz);

    while (j >= 0) {
        if (i >= 0 && (v1[i] > v2[j])) {
            v1[k] = v1[i];
            --i;
        } else  {
            v1[k] = v2[j];
            --j;
        }
        --k;
    }

    return v1;
}

} //namespace Artur99M
