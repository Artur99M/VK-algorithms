#include "mergeArray.hpp"
#include <iostream>
#include <vector>


int main() {
    size_t sz1;
    std::cin >> sz1;
    std::vector<int> v1;
    for (size_t i = 0; i < sz1; ++i) {
        int x;
        std::cin >> x;
        v1.push_back(x);
    }
    size_t sz2;
    std::cin >> sz2;
    std::vector<int> v2;
    for (size_t i = 0; i < sz2; ++i) {
        int x;
        std::cin >> x;
        v2.push_back(x);
    }

    Artur99M::merge(v1, v2);
    size_t sz = v1.size();
    for (size_t i = 0; i < sz; ++i) {
        std::cout << v1[i] << ' ';
    }

}
