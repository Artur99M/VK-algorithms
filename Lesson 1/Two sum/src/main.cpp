#include "two-sum.hpp"
#include <vector>
#include <iostream>
#include <sstream>
#include <string>

int main() {
    size_t n = 0;
    std::vector<int> nums;
    int target = 0;
    std::cin >> n;
    for (size_t i = 0; i < n; ++i) {
        int x;
        std::cin >> x;
        nums.push_back(x);
    }

    std::cin >> target;

    std::vector<int> ans = Artur99M::twoSum(nums, target);

    for (size_t i = 0; i < ans.size(); ++i) {
        std::cout << ' ' << ans[i];
    }
    std::cout << '\n';
}
