#include <iostream>
#include "merge_lists.hpp"
#include <forward_list>
#include <vector>


int main() {
    size_t size1;
    std::cin >> size1;
    std::vector<int> v1;
    for (size_t i = 0; i < size1; ++i) {
        int x;
        std::cin >> x;
        v1.push_back(x);
    }
    std::forward_list<int> list1 {v1.begin(), v1.end()};

    size_t size2;
    std::cin >> size2;
    std::vector<int> v2;
    for (size_t i = 0; i < size2; ++i) {
        int x;
        std::cin >> x;
        v2.push_back(x);
    }
    std::forward_list<int> list2 {v2.begin(), v2.end()};

    auto val = Artur99M::merged_list(list1, list2);

    for (int x : val) {
        std::cout << x << ' ';
    }

}
