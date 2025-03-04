#pragma once
#include <string>

namespace Artur99M {

bool is_palindrome(const std::string& str) {
    for (size_t left = 0, right = str.size() - 1; left < right; --right, ++left) {
        if (str[left] != str[right])
            return false;
    }

    return true;
}
} //namespace Artur99M
