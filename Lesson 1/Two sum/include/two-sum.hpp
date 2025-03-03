#pragma once
#include <vector>
#include <type_traits>
#include <atomic>
#include <cassert>
namespace Artur99M {
template<typename T>
std::vector<T> twoSum(const std::vector<T>& nums, T target) {
    static_assert(std::is_arithmetic_v<T>);
    size_t i = 0, j = nums.size() - 1;
    while (i < j) {
        auto sum = nums[i] + nums[j];
        if (sum == target) {
            return std::vector<T>({nums[i], nums[j]});
        } else if (sum < target) {
            ++i;
        } else {
            --j;
        }
    }

    return std::vector<T>();
}
} //namespace Artur99M
