#include "sum_two_elems.hpp"
#include <iostream>


int main() {
    size_t n;
    std::cin >> n;

    std::vector<int> data;
    data.reserve(n);
    for (size_t i = 0; i < n; ++i) {
        int x = 0;
        std::cin >> x;
        data.push_back(x);
    }

    int target;
    std::cin >> target;

    using it = typename std::vector<int>::iterator;
    std::pair<it, it> res = twoSum(data, target);

    std::cout << res.first - data.begin() << ' ' << res.second - data.begin() << std::endl;
}
