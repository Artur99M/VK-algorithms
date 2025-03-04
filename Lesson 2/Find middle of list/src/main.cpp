#include <iostream>
#include "find_middle.hpp"

int main() {
    size_t size;
    std::cin >> size;
    std::vector<int> v;
    for (size_t i = 0; i < size; ++i) {
        int x;
        std::cin >> x;
        v.push_back(x);
    }
    std::forward_list<int> list {v.begin(), v.end()};

    std::cout << Artur99M::find_middle(list);
}
