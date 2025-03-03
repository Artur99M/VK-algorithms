#pragma once
#include <vector>
#include <algorithm>

namespace Artur99M {

void shift_evem_in_front(std::vector<int>& arr) {
    for(size_t next_even = 0, it = 0, size = arr.size(); it < size; ++it) {
        if (arr[it] % 2 == 0) {
            std::swap(arr[it], arr[next_even]);
            ++next_even;
        }
    }
}
}//namespace Artur99M
