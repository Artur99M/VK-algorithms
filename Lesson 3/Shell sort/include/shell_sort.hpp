#pragma once
#include <algorithm>
//Container with random access iterator
template <typename T, template<typename... args> class container = std::vector>
void shell_sort(container<T>& data) {
    size_t n   = data.size(),
           gap = n / 2;

    while (gap > 0) {

        for (size_t current_position = gap; current_position < n; ++current_position) {

            size_t m_gap = current_position;

            while (m_gap >= gap && data[m_gap] < data[m_gap - gap]) {
                std::swap(data[m_gap], data[m_gap - gap]);
                m_gap -= gap;
            }
        }
        gap /= 2;
    }
}
