
#include "array_tree.hpp"
#include "node.hpp"
#include <memory>
#include <gtest/gtest.h>
#include <vector>
#include "is_complete_tree.hpp"

TEST(IsComplete, Standart) {
    std::vector<int> vec = {8, 3, 9, 11, 6};
    std::shared_ptr<tree_hw::Node<int>> tree = tree_hw::tree_from_array(vec);
    EXPECT_TRUE(tree_hw::isCompleteTree(tree));
}

TEST(IsComplete, TwoLevelsComplete) {
    std::vector<int> vec = {1, 2, 3};
    std::shared_ptr<tree_hw::Node<int>> tree = tree_hw::tree_from_array(vec);
    EXPECT_TRUE(tree_hw::isCompleteTree(tree));
}

TEST(IsComplete, NotCompleteWithGap) {
    std::vector<int> vec = {1, 2, 3, 4, -1, 6}; // -1 означает отсутствие узла
    std::shared_ptr<tree_hw::Node<int>> tree = tree_hw::tree_from_array(vec);
    EXPECT_FALSE(tree_hw::isCompleteTree(tree));
}

TEST(IsComplete, ThreeLevelsComplete) {
    std::vector<int> vec = {1, 2, 3, 4, 5, 6, 7};
    std::shared_ptr<tree_hw::Node<int>> tree = tree_hw::tree_from_array(vec);
    EXPECT_TRUE(tree_hw::isCompleteTree(tree));
}

TEST(IsComplete, SingleNode) {
    std::vector<int> vec = {5};
    std::shared_ptr<tree_hw::Node<int>> tree = tree_hw::tree_from_array(vec);
    EXPECT_TRUE(tree_hw::isCompleteTree(tree));
}

TEST(IsComplete, EmptyTree) {
    std::shared_ptr<tree_hw::Node<int>> tree = nullptr;
    EXPECT_TRUE(tree_hw::isCompleteTree(tree)); // Пустое дерево считается полным
}

TEST(IsComplete, AlmostComplete) {
    std::vector<int> vec = {1, 2, 3, 4, 5, 6};
    std::shared_ptr<tree_hw::Node<int>> tree = tree_hw::tree_from_array(vec);
    EXPECT_TRUE(tree_hw::isCompleteTree(tree));
}

TEST(IsComplete, NotCompleteWrongOrder) {
    std::vector<int> vec = {1, 2, 3, -1, 5}; // Узел 5 должен быть справа от пустого
    std::shared_ptr<tree_hw::Node<int>> tree = tree_hw::tree_from_array(vec);
    EXPECT_FALSE(tree_hw::isCompleteTree(tree));
}

TEST(IsComplete, LargeCompleteTree) {
    std::vector<int> vec = {10,
                          5, 15,
                          3, 7, 12, 18,
                          2, 4, 6, 8, 11, 13, 16, 19};
    std::shared_ptr<tree_hw::Node<int>> tree = tree_hw::tree_from_array(vec);
    EXPECT_TRUE(tree_hw::isCompleteTree(tree));
}

TEST(IsComplete, MissingRightSubtree) {
    std::vector<int> vec = {1, 2, -1, 4}; // -1 означает отсутствие узла
    std::shared_ptr<tree_hw::Node<int>> tree = tree_hw::tree_from_array(vec);
    EXPECT_FALSE(tree_hw::isCompleteTree(tree));
}

TEST(IsComplete, LastLevelNotFull) {
    std::vector<int> vec = {1, 2, 3, 4, 5};
    std::shared_ptr<tree_hw::Node<int>> tree = tree_hw::tree_from_array(vec);
    EXPECT_TRUE(tree_hw::isCompleteTree(tree));
}

TEST(IsComplete, DifferentDepths) {
    std::vector<int> vec = {1, 2, 3, 4, -1, -1, 7, 8};
    std::shared_ptr<tree_hw::Node<int>> tree = tree_hw::tree_from_array(vec);
    EXPECT_FALSE(tree_hw::isCompleteTree(tree));
}

TEST(IsComplete, NegativeValuesComplete) {
    std::vector<int> vec = {-5, -10, -3, -15, -8};
    std::shared_ptr<tree_hw::Node<int>> tree = tree_hw::tree_from_array(vec);
    EXPECT_TRUE(tree_hw::isCompleteTree(tree));
}

TEST(IsComplete, ZeroValuesComplete) {
    std::vector<int> vec = {0, 0, 0, 0, 0};
    std::shared_ptr<tree_hw::Node<int>> tree = tree_hw::tree_from_array(vec);
    EXPECT_TRUE(tree_hw::isCompleteTree(tree));
}

TEST(IsComplete, ComplexIncomplete) {
    std::vector<int> vec = {1, 2, 3, 4, 5, -1, 7, 8, 9, -1, -1, 12};
    std::shared_ptr<tree_hw::Node<int>> tree = tree_hw::tree_from_array(vec);
    EXPECT_FALSE(tree_hw::isCompleteTree(tree));
}
