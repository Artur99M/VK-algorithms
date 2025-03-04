#include "is_base.hpp"
#include <iostream>
#include <vector>

int main() {
    size_t size_base;
    std::cin >> size_base;
    std::vector<int> base;
    for (size_t i = 0; i < size_base; ++i) {
        int x;
        std::cin >> x;
        base.push_back(x);
    }

    size_t size_derived;
    std::cin >> size_derived;
    std::vector<int> derived;
    for (size_t i = 0; i < size_derived; ++i) {
        int x;
        std::cin >> x;
        derived.push_back(x);
    }

    std::cout << Artur99M::is_base(base, derived);
}
