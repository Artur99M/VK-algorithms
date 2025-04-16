
#include "array_tree.hpp"
#include "node.hpp"
#include <memory>
#include <gtest/gtest.h>
#include <vector>
#include "min_depth.hpp"

TEST(MIN_DEPTH, Standart) {
    std::vector<int> vec = {3, 8, 8, 9, 6, 6, 9};
    std::shared_ptr<tree_hw::Node<int>> tree = tree_hw::tree_from_array(vec);

    EXPECT_EQ(3, minDepth(tree));
}

TEST(MIN_DEPTH, SingleNode) {
    std::vector<int> vec = {5};
    std::shared_ptr<tree_hw::Node<int>> tree = tree_hw::tree_from_array(vec);
    EXPECT_EQ(1, tree_hw::minDepth(tree));
}

TEST(MIN_DEPTH, EmptyTree) {
    std::shared_ptr<tree_hw::Node<int>> tree = nullptr;
    EXPECT_EQ(0, tree_hw::minDepth(tree));
}

TEST(MIN_DEPTH, LeftMinDepth) {
    std::vector<int> vec = {1, 2, 3, 4, -1, -1, -1}; // -1 означает отсутствие узла
    std::shared_ptr<tree_hw::Node<int>> tree = tree_hw::tree_from_array(vec);
    EXPECT_EQ(3, tree_hw::minDepth(tree));
}

TEST(MIN_DEPTH, RightMinDepth) {
    std::vector<int> vec = {1, -1, 2, -1, -1, 3, -1};
    std::shared_ptr<tree_hw::Node<int>> tree = tree_hw::tree_from_array(vec);
    EXPECT_EQ(3, tree_hw::minDepth(tree));
}

TEST(MIN_DEPTH, UnbalancedTree) {
    std::vector<int> vec = {1, 2, -1, 3, -1, -1, -1, 4, -1};
    std::shared_ptr<tree_hw::Node<int>> tree = tree_hw::tree_from_array(vec);
    EXPECT_EQ(4, tree_hw::minDepth(tree));
}

TEST(MIN_DEPTH, FullTree) {
    std::vector<int> vec = {1, 2, 3, 4, 5, 6, 7};
    std::shared_ptr<tree_hw::Node<int>> tree = tree_hw::tree_from_array(vec);
    EXPECT_EQ(3, tree_hw::minDepth(tree));
}

TEST(MIN_DEPTH, SingleLeaf) {
    std::vector<int> vec = {1, 2, -1, -1, -1};
    std::shared_ptr<tree_hw::Node<int>> tree = tree_hw::tree_from_array(vec);
    EXPECT_EQ(2, tree_hw::minDepth(tree));
}

TEST(MIN_DEPTH, LargeTreeVaryingDepths) {
    std::vector<int> vec = {1,
                          2, 3,
                          4, -1, -1, 5,
                          -1, -1, -1, -1, -1, -1, 6, -1};
    std::shared_ptr<tree_hw::Node<int>> tree = tree_hw::tree_from_array(vec);
    EXPECT_EQ(4, tree_hw::minDepth(tree));
}

TEST(MIN_DEPTH, NegativeValues) {
    std::vector<int> vec = {-10, -5, -15, -3, -7, -12, -20};
    std::shared_ptr<tree_hw::Node<int>> tree = tree_hw::tree_from_array(vec);
    EXPECT_EQ(3, tree_hw::minDepth(tree));
}
