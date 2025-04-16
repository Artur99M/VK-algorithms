#include "max_min_mult.hpp"

namespace tree_hw {

template <typename T>
T maxMinMultiplication(const std::vector<T>& data) {
    size_t sz = data.size();
    if (sz < 3) {
        if (sz == 0)
            return 0;
        if (sz == 1)
            return data[0] * data[0];
        // if (sz == 2)
            return data[0] * data[1];
    }


    size_t min_index = 1,
           max_index = 2;

    //поиск по левому поддереву
    for (size_t i = 1; i < sz; i = 2 * i + 1)
        min_index = i;

    //поиск по правому поддереву
    for (size_t i = 2; i < sz; i = 2 * i + 2)
        max_index = i;

    return data[min_index] * data[max_index];
}

template int maxMinMultiplication(const std::vector<int>& data);
} //tree_hw
