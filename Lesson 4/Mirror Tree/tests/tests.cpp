
#include "array_tree.hpp"
#include "node.hpp"
#include <memory>
#include <gtest/gtest.h>
#include <vector>
#include "mirror_tree.hpp"

TEST(CountMirrorNodes, SymmetricTree) {
    std::vector<int> vec = {1, 2, 2, 3, 4, 4, 3};
    std::shared_ptr<tree_hw::Node<int>> tree = tree_hw::tree_from_array(vec);
    EXPECT_EQ(3, tree_hw::CountMirrorTwins(tree)); // Пары (2,2), (3,3), (4,4)
}

TEST(CountMirrorTwins, PartialSymmetricTree) {
    std::vector<int> vec = {1, 2, 2, -1, 3, -1, 3}; // -1 означает nullptr
    std::shared_ptr<tree_hw::Node<int>> tree = tree_hw::tree_from_array(vec);
    EXPECT_EQ(1, tree_hw::CountMirrorTwins(tree)); // Пары (2,2), (3,3)
}

TEST(CountMirrorTwins, AsymmetricTree) {
    std::vector<int> vec = {1, 2, 3, 4, 5, 6, 7};
    std::shared_ptr<tree_hw::Node<int>> tree = tree_hw::tree_from_array(vec);
    EXPECT_EQ(0, tree_hw::CountMirrorTwins(tree)); // Нет зеркальных пар
}

TEST(CountMirrorTwins, SingleNodeTree) {
    std::vector<int> vec = {5};
    std::shared_ptr<tree_hw::Node<int>> tree = tree_hw::tree_from_array(vec);
    EXPECT_EQ(0, tree_hw::CountMirrorTwins(tree)); // Нет пар для сравнения
}

TEST(CountMirrorTwins, EmptyTree) {
    std::shared_ptr<tree_hw::Node<int>> tree = nullptr;
    EXPECT_EQ(0, tree_hw::CountMirrorTwins(tree));
}

TEST(CountMirrorTwins, SingleLevelSymmetry) {
    std::vector<int> vec = {10, 5, 5, -1, -1, -1, -1};
    std::shared_ptr<tree_hw::Node<int>> tree = tree_hw::tree_from_array(vec);
    EXPECT_EQ(1, tree_hw::CountMirrorTwins(tree)); // Только пара (5,5)
}

TEST(CountMirrorTwins, DifferentValuesSymmetricPositions) {
    std::vector<int> vec = {10, 5, 6, 3, 8, 7, 4};
    std::shared_ptr<tree_hw::Node<int>> tree = tree_hw::tree_from_array(vec);
    EXPECT_EQ(0, tree_hw::CountMirrorTwins(tree)); // Нет совпадающих пар
}

TEST(CountMirrorTwins, NegativeValues) {
    std::vector<int> vec = {0, -5, -5, -10, -3, -3, -10};
    std::shared_ptr<tree_hw::Node<int>> tree = tree_hw::tree_from_array(vec);
    EXPECT_EQ(3, tree_hw::CountMirrorTwins(tree)); // Пары (-5,-5), (-10,-10), (-3,-3)
}

TEST(CountMirrorTwins, LargeSymmetricTree) {
    std::vector<int> vec = {100,
                          50, 50,
                          25, 75, 75, 25,
                          10,30,60,90,90,60,30,10};
    std::shared_ptr<tree_hw::Node<int>> tree = tree_hw::tree_from_array(vec);
    EXPECT_EQ(7, tree_hw::CountMirrorTwins(tree)); // 7 пар зеркальных близнецов
}

TEST(CountMirrorTwins, PartialValueMatches) {
    std::vector<int> vec = {10, 5, 5, 2, 8, 6, 8};
    std::shared_ptr<tree_hw::Node<int>> tree = tree_hw::tree_from_array(vec);
    EXPECT_EQ(1, tree_hw::CountMirrorTwins(tree)); // Пары (5,5) и (8,8)
}

TEST(CountMirrorTwins, DuplicatesNotMirrored) {
    std::vector<int> vec = {10, 5, 6, 5, 6, 6, 8};
    std::shared_ptr<tree_hw::Node<int>> tree = tree_hw::tree_from_array(vec);
    EXPECT_EQ(1, tree_hw::CountMirrorTwins(tree)); // Только пара (6,6)
}

TEST(CountMirrorTwins, SingleLeafTree) {
    std::vector<int> vec = {10, 5, -1, 3};
    std::shared_ptr<tree_hw::Node<int>> tree = tree_hw::tree_from_array(vec);
    EXPECT_EQ(0, tree_hw::CountMirrorTwins(tree)); // Нет пар для сравнения
}

TEST(CountMirrorTwins, MultiLevelPartialMatch) {
    std::vector<int> vec = {10,
                          5, 5,
                          3, -1, -1, 3,
                          2,4,-1,-1,-1,-1,4,2};
    std::shared_ptr<tree_hw::Node<int>> tree = tree_hw::tree_from_array(vec);
    EXPECT_EQ(4, tree_hw::CountMirrorTwins(tree)); // Пары (5,5), (3,3), (4,4), (2,2)
}

TEST(CountMirrorTwins, RootAndOneLevel) {
    std::vector<int> vec = {1, 2, 2};
    std::shared_ptr<tree_hw::Node<int>> tree = tree_hw::tree_from_array(vec);
    EXPECT_EQ(1, tree_hw::CountMirrorTwins(tree)); // Пара (2,2)
}

TEST(CountMirrorTwins, ComplexAsymmetry) {
    std::vector<int> vec = {1,
                          2, 2,
                          3, 4, 5, 3,
                          6,-1,-1,7,-1,-1,7,6};
    std::shared_ptr<tree_hw::Node<int>> tree = tree_hw::tree_from_array(vec);
    EXPECT_EQ(3, tree_hw::CountMirrorTwins(tree)); // Пары (2,2), (3,3), (7,7)
}
