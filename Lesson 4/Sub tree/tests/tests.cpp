
#include "array_tree.hpp"
#include "node.hpp"
#include <memory>
#include <gtest/gtest.h>
#include <vector>
#include "sub_trees.hpp"


TEST(IsSubTree, IdenticalStandardTrees) {
    std::vector<int> vec = {3, 8, 8, 9, 6, 6, 9};
    std::shared_ptr<tree_hw::Node<int>> a = tree_hw::tree_from_array(vec);
    std::shared_ptr<tree_hw::Node<int>> b = tree_hw::tree_from_array(vec);
    EXPECT_TRUE(tree_hw::isSubTree(a, b));
}

TEST(IsSubTree, SubtreeIsLeaf) {
    std::vector<int> vec_a = {3, 8, 8, 9, 6, 6, 9};
    std::vector<int> vec_b = {6};
    std::shared_ptr<tree_hw::Node<int>> a = tree_hw::tree_from_array(vec_a);
    std::shared_ptr<tree_hw::Node<int>> b = tree_hw::tree_from_array(vec_b);
    EXPECT_TRUE(tree_hw::isSubTree(a, b));
}

TEST(IsSubTree, LeftSubtree) {
    std::vector<int> vec_a = {10, 5, 15, 3, 7, 12, 18};
    std::vector<int> vec_b = {5, 3, 7};
    std::shared_ptr<tree_hw::Node<int>> a = tree_hw::tree_from_array(vec_a);
    std::shared_ptr<tree_hw::Node<int>> b = tree_hw::tree_from_array(vec_b);
    EXPECT_TRUE(tree_hw::isSubTree(a, b));
}

TEST(IsSubTree, RightSubtree) {
    std::vector<int> vec_a = {10, 5, 15, -1, -1, 12, 18}; // -1 означает отсутствие узла
    std::vector<int> vec_b = {15, 12, 18};
    std::shared_ptr<tree_hw::Node<int>> a = tree_hw::tree_from_array(vec_a);
    std::shared_ptr<tree_hw::Node<int>> b = tree_hw::tree_from_array(vec_b);
    EXPECT_TRUE(tree_hw::isSubTree(a, b));
}

TEST(IsSubTree, NotSubtreeDifferentValues) {
    std::vector<int> vec_a = {10, 5, 15};
    std::vector<int> vec_b = {5, 1, 7};
    std::shared_ptr<tree_hw::Node<int>> a = tree_hw::tree_from_array(vec_a);
    std::shared_ptr<tree_hw::Node<int>> b = tree_hw::tree_from_array(vec_b);
    EXPECT_FALSE(tree_hw::isSubTree(a, b));
}

TEST(IsSubTree, EmptySubtree) {
    std::vector<int> vec_a = {1, 2, 3};
    std::shared_ptr<tree_hw::Node<int>> a = tree_hw::tree_from_array(vec_a);
    std::shared_ptr<tree_hw::Node<int>> b = nullptr;
    EXPECT_TRUE(tree_hw::isSubTree(a, b)); // Пустое дерево считается поддеревом любого дерева
}

TEST(IsSubTree, MiddleSubtree) {
    std::vector<int> vec_a = {10, 5, 15, 3, 7, 12, 18, 2, 4, 6, 8};
    std::vector<int> vec_b = {7, 6, 8};
    std::shared_ptr<tree_hw::Node<int>> a = tree_hw::tree_from_array(vec_a);
    std::shared_ptr<tree_hw::Node<int>> b = tree_hw::tree_from_array(vec_b);
    EXPECT_TRUE(tree_hw::isSubTree(a, b));
}

TEST(IsSubTree, NotSubtreeDifferentStructure) {
    std::vector<int> vec_a = {10, 5, 15, 3, -1, 12, 18}; // -1 означает отсутствие узла
    std::vector<int> vec_b = {5, 3, 7};
    std::shared_ptr<tree_hw::Node<int>> a = tree_hw::tree_from_array(vec_a);
    std::shared_ptr<tree_hw::Node<int>> b = tree_hw::tree_from_array(vec_b);
    EXPECT_FALSE(tree_hw::isSubTree(a, b));
}

TEST(IsSubTree, LargeTreeWithSubtree) {
    std::vector<int> vec_a = {50, 30, 70, 20, 40, 60, 80, 10, 25, 35, 45, 55, 65, 75, 85};
    std::vector<int> vec_b = {40, 35, 45};
    std::shared_ptr<tree_hw::Node<int>> a = tree_hw::tree_from_array(vec_a);
    std::shared_ptr<tree_hw::Node<int>> b = tree_hw::tree_from_array(vec_b);
    EXPECT_TRUE(tree_hw::isSubTree(a, b));
}

TEST(IsSubTree, SubtreeWithNegativeValues) {
    std::vector<int> vec_a = {0, -5, 5, -10, -3, 3, 10};
    std::vector<int> vec_b = {-5, -10, -3};
    std::shared_ptr<tree_hw::Node<int>> a = tree_hw::tree_from_array(vec_a);
    std::shared_ptr<tree_hw::Node<int>> b = tree_hw::tree_from_array(vec_b);
    EXPECT_TRUE(tree_hw::isSubTree(a, b));
}

TEST(IsSubTree, SubtreeNotPresent) {
    std::vector<int> vec_a = {10, 5, 15};
    std::vector<int> vec_b = {5, -1, 7}; // -1 означает отсутствие узла
    std::shared_ptr<tree_hw::Node<int>> a = tree_hw::tree_from_array(vec_a);
    std::shared_ptr<tree_hw::Node<int>> b = tree_hw::tree_from_array(vec_b);
    EXPECT_FALSE(tree_hw::isSubTree(a, b));
}

TEST(IsSubTree, MainTreeEmpty) {
    std::vector<int> vec_b = {1};
    std::shared_ptr<tree_hw::Node<int>> a = nullptr;
    std::shared_ptr<tree_hw::Node<int>> b = tree_hw::tree_from_array(vec_b);
    EXPECT_FALSE(tree_hw::isSubTree(a, b)); // Пустое дерево не может содержать непустое поддерево
}
