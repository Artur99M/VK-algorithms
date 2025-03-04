#pragma once

#include <forward_list>
#include <algorithm>

namespace Artur99M {

template <typename T>
std::forward_list<T> merged_list(const std::forward_list<T>& first, const std::forward_list<T>& second) {
    std::forward_list<T> ans;
    auto first_it = first.begin(), second_it = second.begin();

    if ((*first_it) < (*second_it)) {
        ans.push_front(*first_it);
        ++first_it;
    } else {
        ans.push_front(*second_it);
        ++second_it;
    }

    auto current = ans.begin();

    while (first_it != first.end() && second_it != second.end()) {
        if ((*first_it) < (*second_it)) {
            ans.insert_after(current, *first_it);
            ++first_it;
        } else {
            ans.insert_after(current, *second_it);
            ++second_it;
        }
        current = std::next(current);
    }

    while (first_it != first.end()) {
        ans.insert_after(current, *first_it);
        ++first_it;
        current = std::next(current);
    }
    while (second_it != second.end()) {
        ans.insert_after(current, *second_it);
        ++second_it;
        current = std::next(current);
    }

    return ans;
}
} //namespace Artur99M
