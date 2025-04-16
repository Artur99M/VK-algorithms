
#include <memory>
#include <gtest/gtest.h>
#include <vector>
#include "is_max_heap.hpp"

TEST(IsMaxHeap, Standart) {

    std::vector<int> vec = {21, 19, 18, 11, 12, 15, 16, 9, 8, 10};

    EXPECT_TRUE(tree_hw::isMaxHeap(vec));
}

TEST(IsMaxHeap, InvalidHeap) {
    std::vector<int> vec = {21, 19, 18, 11, 22, 15, 16}; // 22 > родительский 19
    EXPECT_FALSE(tree_hw::isMaxHeap(vec));
}

TEST(IsMaxHeap, SingleElement) {
    std::vector<int> vec = {5};
    EXPECT_TRUE(tree_hw::isMaxHeap(vec));
}

TEST(IsMaxHeap, EmptyHeap) {
    std::vector<int> vec = {};
    EXPECT_TRUE(tree_hw::isMaxHeap(vec)); // Пустой массив считается корректной кучей
}

TEST(IsMaxHeap, NegativeNumbers) {
    std::vector<int> vec = {-1, -3, -5, -7, -9};
    EXPECT_TRUE(tree_hw::isMaxHeap(vec));
}
