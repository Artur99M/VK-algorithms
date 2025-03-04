#pragma once
#include <vector>

namespace Artur99M {
template<typename T>
bool is_base(const std::vector<T>& base, const std::vector<T>& derived) {
    auto it_base = base.begin();
    for (auto it_derived = derived.begin(); it_derived != derived.end() && it_base != base.end(); ++it_derived) {
        if (*it_derived == *it_base)
            ++it_base;
    }

    return it_base == base.end();
}

} //namespace Artur99M
