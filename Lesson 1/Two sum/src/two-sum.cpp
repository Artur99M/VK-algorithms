#include "two-sum.hpp"

template<typename T>
std::vector<T>&& twoSum(std::vector<T> nums, T target) {
    static_assert(std::is_arithmetic_v<T>);
    size_t i = 0, j = nums.size() - 1;
    while (i < j) {
        T value = nums[i] + nums[j];
        if (value == target) {
            return std::vector<T>({nums[i], nums[j]});
        } else if (value < target) {
            ++i;
        } else {
            ++j;
        }
    }

    return std::vector<T>();
}
