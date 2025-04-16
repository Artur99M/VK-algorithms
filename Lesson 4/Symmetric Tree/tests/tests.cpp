
#include "array_tree.hpp"
#include "node.hpp"
#include <memory>
#include <gtest/gtest.h>
#include <vector>
#include "symmetric_tree.hpp"

TEST(Symmetric, Standart) {

    std::vector<int> vec = {3, 8, 8, 9, 6, 6, 9};
    std::shared_ptr<tree_hw::Node<int>> tree = tree_hw::tree_from_array(vec);
    EXPECT_TRUE(tree_hw::isSymmetricBFS(tree));
    EXPECT_TRUE(tree_hw::isSymmetricDFS(tree));
}

TEST(Symmetric, NotSymmetric) {
    std::vector<int> vec = {3, 8, 8, 9, 6, 5, 9};
    std::shared_ptr<tree_hw::Node<int>> tree = tree_hw::tree_from_array(vec);
    EXPECT_FALSE(tree_hw::isSymmetricBFS(tree));
    EXPECT_FALSE(tree_hw::isSymmetricDFS(tree));
}

TEST(Symmetric, EmptyTree) {
    std::shared_ptr<tree_hw::Node<int>> tree = nullptr;
    EXPECT_TRUE(tree_hw::isSymmetricBFS(tree)); // Пустое дерево считается симметричным
    EXPECT_TRUE(tree_hw::isSymmetricDFS(tree));
}

TEST(Symmetric, SingleNode) {
    std::vector<int> vec = {5};
    std::shared_ptr<tree_hw::Node<int>> tree = tree_hw::tree_from_array(vec);
    EXPECT_TRUE(tree_hw::isSymmetricBFS(tree));
    EXPECT_TRUE(tree_hw::isSymmetricDFS(tree));
}

TEST(Symmetric, OddLevelsSymmetric) {
    std::vector<int> vec = {1, 2, 2, 3, 4, 4, 3, 5, 6, 7, 8, 8, 7, 6, 5};
    std::shared_ptr<tree_hw::Node<int>> tree = tree_hw::tree_from_array(vec);
    EXPECT_TRUE(tree_hw::isSymmetricBFS(tree));
    EXPECT_TRUE(tree_hw::isSymmetricDFS(tree));
}

TEST(Symmetric, StructuralAsymmetry) {
    std::vector<int> vec = {1, 2, 2, -1, 3, -1, 3}; // -1 означает отсутствие узла
    std::shared_ptr<tree_hw::Node<int>> tree = tree_hw::tree_from_array(vec);
    EXPECT_FALSE(tree_hw::isSymmetricBFS(tree));
    EXPECT_FALSE(tree_hw::isSymmetricDFS(tree));
}

TEST(Symmetric, NegativeValuesSymmetric) {
    std::vector<int> vec = {-10, 5, 5, 3, -8, -8, 3};
    std::shared_ptr<tree_hw::Node<int>> tree = tree_hw::tree_from_array(vec);
    EXPECT_TRUE(tree_hw::isSymmetricBFS(tree));
    EXPECT_TRUE(tree_hw::isSymmetricDFS(tree));
}

TEST(Symmetric, PartiallySymmetric) {
    std::vector<int> vec = {10, 20, 20, 30, 40, 40, 30, -1, 50, -1, -1, -1, -1, 50, -1};
    std::shared_ptr<tree_hw::Node<int>> tree = tree_hw::tree_from_array(vec);
    EXPECT_TRUE(tree_hw::isSymmetricBFS(tree));
    EXPECT_TRUE(tree_hw::isSymmetricDFS(tree));
}

TEST(Symmetric, LargeSymmetricTree) {
    std::vector<int> vec = {1,
                           2, 2,
                           3, 4, 4, 3,
                           5, 6, 7, 8, 8, 7, 6, 5,
                           9,10,11,12,13,14,15,16,16,15,14,13,12,11,10,9};
    std::shared_ptr<tree_hw::Node<int>> tree = tree_hw::tree_from_array(vec);
    EXPECT_TRUE(tree_hw::isSymmetricBFS(tree));
    EXPECT_TRUE(tree_hw::isSymmetricDFS(tree));
}
