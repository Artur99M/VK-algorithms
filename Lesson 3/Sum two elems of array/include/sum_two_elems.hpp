#pragma once
#include <vector>
#include <tuple>
#include <unordered_map>

template <typename T, template<typename... args> class container = std::vector>
std::pair<typename container<T>::iterator, typename container<T>::iterator>
twoSum(container<T>& data, T target) {

    std::unordered_map<T, typename container<T>::iterator> cache;

    for (auto iterator = data.begin(); iterator != data.end(); ++iterator)
        cache[*iterator] = iterator;

    for (auto iterator = data.begin(); iterator != data.end(); ++iterator) {
        T diff = target - *iterator;
        if (cache.find(diff) != cache.end()) {
            return std::make_pair(iterator, cache[diff]);
        }
    }

    return std::make_pair(data.end(), data.end());
}
