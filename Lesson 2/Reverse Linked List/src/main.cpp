#include <iostream>
#include "reverse_linked_list.hpp"
#include <forward_list>
#include <vector>


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
    auto val = Artur99M::reversed_list(list);

    for (int x : val) {
        std::cout << x << ' ';
    }

}
