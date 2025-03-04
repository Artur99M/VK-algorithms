#pragma once

#include <forward_list>
#include <algorithm>

namespace Artur99M {

template<typename T>
T& find_middle(std::forward_list<T>& arr) {
    auto fast = arr.begin(), slow = arr.begin();

    for (; fast != arr.end() && std::next(fast) != arr.end(); ++slow, ++++fast) {
    }

    return *slow;
}

} //namespace Artur99M
