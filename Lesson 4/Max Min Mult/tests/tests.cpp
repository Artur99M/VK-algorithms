#include <memory>
#include <gtest/gtest.h>
#include <vector>
#include "max_min_mult.hpp"

TEST(Symmetric, Standart) {

    std::vector<int> vec = {5, 2, 8, 1, 3, 6, 10};
    EXPECT_EQ(tree_hw::maxMinMultiplication(vec), 10);
}

TEST(MaxMinMultiplication, NegativeValues) {
    std::vector<int> vec = {0, -5, 5, -10, -3, 3, 10};
    EXPECT_EQ(-100, tree_hw::maxMinMultiplication(vec)); // min=-10, max=10 → -10*10=-100
}

TEST(MaxMinMultiplication, SingleElement) {
    std::vector<int> vec = {7};
    EXPECT_EQ(49, tree_hw::maxMinMultiplication(vec)); // min=7, max=7 → 7*7=49
}

TEST(MaxMinMultiplication, EmptyTree) {
    std::vector<int> vec = {};
    EXPECT_EQ(0, tree_hw::maxMinMultiplication(vec)); // Пустое дерево → 0
}

TEST(MaxMinMultiplication, WithDuplicates) {
    std::vector<int> vec = {5, 2, 8, 2, 5, 8, 10};
    EXPECT_EQ(20, tree_hw::maxMinMultiplication(vec)); // min=2, max=10 → 2*10=20
}

TEST(MaxMinMultiplication, LargeValues) {
    std::vector<int> vec = {1000, 500, 1500, 250, 750, 1250, 2000};
    EXPECT_EQ(500000, tree_hw::maxMinMultiplication(vec)); // min=250, max=2000 → 250*2000=500000
}

TEST(MaxMinMultiplication, WithZero) {
    std::vector<int> vec = {10, 5, 15, 0, 7, 11, 20};
    EXPECT_EQ(0, tree_hw::maxMinMultiplication(vec)); // min=0, max=20 → 0*20=0
}

TEST(MaxMinMultiplication, AllElementsEqual) {
    std::vector<int> vec = {5, 5, 5, 5, 5, 5, 5};
    EXPECT_EQ(25, tree_hw::maxMinMultiplication(vec)); // min=5, max=5 → 5*5=25
}
