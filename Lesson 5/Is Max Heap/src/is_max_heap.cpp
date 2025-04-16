#include "is_max_heap.hpp"

namespace tree_hw {

template <typename T>
bool isMaxHeap(const std::vector<T>& arr) {
    size_t sz = arr.size();
    if (sz < 2)
        return true;
    for (size_t i = 0; i < (sz - 2) / 2; ++i) {
        size_t left  = 2 * i + 1,
            right = 2 * i + 2;
        if (left < sz && arr[i] < arr[left])
            return false;
        if (right < sz && arr[i] < arr[right])
            return false;
    }

    return true;
}
template bool isMaxHeap(const std::vector<int>& arr);

} //namespace tree_hw
