#pragma once
#include <iostream>
#include <forward_list>
#include <algorithm>
namespace Artur99M {
template <typename T>
std::forward_list<T> reversed_list(const std::forward_list<T>& list) {
    std::forward_list<T> reversed_list;
    auto prev     = list.begin();
    auto current  = std::next(prev);
    reversed_list.push_front(list.front());

    while (current!= list.end()) {
        reversed_list.push_front(*current);
        prev = current;
        current = std::next(current);
    }

    return reversed_list;
}
}//namespace Artur99M
