#pragma once
#include <vector>
#include <algorithm>

namespace Artur99M {

template <typename T, T zero, T one, T two>
void dutch_flag_sort(std::vector<T>& arr) {
    size_t low = 0, mid = 0, high = arr.size() - 1;

    while(mid <= high) {
        if (arr[mid] == zero) {
            std::swap(arr[low], arr[mid]);
            ++low;
            ++mid;
        } else if (arr[mid] == two) {
            std::swap(arr[mid], arr[high]);
            --high;
        } else { //arr[mid] == one
            ++mid;
        }
    }
}

} //namespace Artur99M
