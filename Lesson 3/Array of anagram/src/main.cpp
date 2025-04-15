#include "anagram_array.hpp"
#include <iostream>
#include <vector>
#include <string>


int main() {
    size_t n;
    std::cin >> n;

    std::vector<std::string> arr;
    arr.reserve(n);
    for (size_t i = 0; i < n; ++i) {
        std::string str;
        std::cin >> str;
        arr.push_back(str);
    }

    auto ans = make_array_angram(arr);

    std::cout << '[';
    for (std::set<std::string>& map : ans) {
        std::cout << '[';
        for (const std::string& str : map) {
            std::cout << '\"' << str << "\"";
        }
        std::cout << "]";
    }
    std::cout << "]\n";
}
