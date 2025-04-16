
#include "array_tree.hpp"
#include "node.hpp"
#include <memory>
#include <gtest/gtest.h>
#include <vector>
#include "compare_trees.hpp"

TEST(IsSameTree, IdenticalStandardTrees) {
    std::vector<int> vec = {3, 8, 8, 9, 6, 6, 9};
    std::shared_ptr<tree_hw::Node<int>> a = tree_hw::tree_from_array(vec);
    std::shared_ptr<tree_hw::Node<int>> b = tree_hw::tree_from_array(vec);
    EXPECT_TRUE(tree_hw::isSameTree(a, b));
}

TEST(IsSameTree, DifferentStructureSameValues) {
    std::vector<int> vec1 = {1, 2, 3};
    std::vector<int> vec2 = {1, 3, 2};
    std::shared_ptr<tree_hw::Node<int>> a = tree_hw::tree_from_array(vec1);
    std::shared_ptr<tree_hw::Node<int>> b = tree_hw::tree_from_array(vec2);
    EXPECT_FALSE(tree_hw::isSameTree(a, b));
}

TEST(IsSameTree, BothTreesEmpty) {
    std::shared_ptr<tree_hw::Node<int>> a = nullptr;
    std::shared_ptr<tree_hw::Node<int>> b = nullptr;
    EXPECT_TRUE(tree_hw::isSameTree(a, b));
}

TEST(IsSameTree, OneTreeEmpty) {
    std::vector<int> vec = {1};
    std::shared_ptr<tree_hw::Node<int>> a = tree_hw::tree_from_array(vec);
    std::shared_ptr<tree_hw::Node<int>> b = nullptr;
    EXPECT_FALSE(tree_hw::isSameTree(a, b));
    EXPECT_FALSE(tree_hw::isSameTree(b, a));
}

TEST(IsSameTree, SingleNodeTrees) {
    std::vector<int> vec1 = {5};
    std::vector<int> vec2 = {3};
    std::shared_ptr<tree_hw::Node<int>> a = tree_hw::tree_from_array(vec1);
    std::shared_ptr<tree_hw::Node<int>> b = tree_hw::tree_from_array(vec1);
    std::shared_ptr<tree_hw::Node<int>> c = tree_hw::tree_from_array(vec2);

    EXPECT_TRUE(tree_hw::isSameTree(a, b));
    EXPECT_FALSE(tree_hw::isSameTree(a, c));
}

TEST(IsSameTree, LargeIdenticalTrees) {
    std::vector<int> vec = {10, 5, 15, 3, 7, 12, 18, 1, 4, 6, 9, 11, 13, 16, 20};
    std::shared_ptr<tree_hw::Node<int>> a = tree_hw::tree_from_array(vec);
    std::shared_ptr<tree_hw::Node<int>> b = tree_hw::tree_from_array(vec);
    EXPECT_TRUE(tree_hw::isSameTree(a, b));
}

TEST(IsSameTree, OneNodeDifference) {
    std::vector<int> vec1 = {1, 2, 3, 4, 5};
    std::vector<int> vec2 = {1, 2, 3, 4, 6};
    std::shared_ptr<tree_hw::Node<int>> a = tree_hw::tree_from_array(vec1);
    std::shared_ptr<tree_hw::Node<int>> b = tree_hw::tree_from_array(vec2);
    EXPECT_FALSE(tree_hw::isSameTree(a, b));
}

TEST(IsSameTree, TreesWithMissingNodes) {
    std::vector<int> vec1 = {1, 2, -1, 3}; // -1 означает отсутствие узла
    std::vector<int> vec2 = {1, 2, -1, 3};
    std::vector<int> vec3 = {1, 2, -1, 4};

    std::shared_ptr<tree_hw::Node<int>> a = tree_hw::tree_from_array(vec1);
    std::shared_ptr<tree_hw::Node<int>> b = tree_hw::tree_from_array(vec2);
    std::shared_ptr<tree_hw::Node<int>> c = tree_hw::tree_from_array(vec3);

    EXPECT_TRUE(tree_hw::isSameTree(a, b));
    EXPECT_FALSE(tree_hw::isSameTree(a, c));
}

TEST(IsSameTree, DifferentDepthTrees) {
    std::vector<int> vec1 = {1, 2, 3, 4};
    std::vector<int> vec2 = {1, 2, 3};

    std::shared_ptr<tree_hw::Node<int>> a = tree_hw::tree_from_array(vec1);
    std::shared_ptr<tree_hw::Node<int>> b = tree_hw::tree_from_array(vec2);

    EXPECT_FALSE(tree_hw::isSameTree(a, b));
}
