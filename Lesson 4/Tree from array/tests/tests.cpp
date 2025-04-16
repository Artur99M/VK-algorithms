
#include "array_tree.hpp"
#include "node.hpp"
#include <memory>
#include <gtest/gtest.h>
#include <vector>

TEST(buildTree, 1) {
    std::vector<int> vec = {8, 9, 11, 7, 16, 3 , 1};

    std::shared_ptr<tree_hw::Node<int>> res = tree_hw::tree_from_array(vec);
    EXPECT_EQ(res->val_  , 8      );
    EXPECT_NE(res->left_ , nullptr);
    EXPECT_NE(res->right_, nullptr);
    if (res->left_ != nullptr && res->right_ != nullptr) {

        EXPECT_EQ(res->left_->val_  , 9      );
        EXPECT_NE(res->left_->left_ , nullptr);
        EXPECT_NE(res->left_->right_, nullptr);
        if (res->left_->left_ != nullptr && res->left_->right_ != nullptr) {
            EXPECT_EQ(res->left_->left_->val_  , 7      );
            EXPECT_EQ(res->left_->left_->left_ , nullptr);
            EXPECT_EQ(res->left_->left_->right_, nullptr);

            EXPECT_EQ(res->left_->right_->val_  , 16     );
            EXPECT_EQ(res->left_->right_->left_ , nullptr);
            EXPECT_EQ(res->left_->right_->right_, nullptr);
        }

        EXPECT_EQ(res->right_->val_  , 11     );
        EXPECT_NE(res->right_->left_ , nullptr);
        EXPECT_NE(res->right_->right_, nullptr);
        if (res->right_->left_ != nullptr && res->right_->right_ != nullptr) {
            EXPECT_EQ(res->right_->left_->val_  , 3      );
            EXPECT_EQ(res->right_->left_->left_ , nullptr);
            EXPECT_EQ(res->right_->left_->right_, nullptr);

            EXPECT_EQ(res->right_->right_->val_  , 1      );
            EXPECT_EQ(res->right_->right_->left_ , nullptr);
            EXPECT_EQ(res->right_->right_->right_, nullptr);
        }
    }

}

TEST(buildTree, emptyTree) {
    std::vector<int> vec = {};
    std::shared_ptr<tree_hw::Node<int>> res = tree_hw::tree_from_array(vec);
    EXPECT_EQ(res, nullptr);
}

TEST(buildTree, singleNode) {
    std::vector<int> vec = {5};
    std::shared_ptr<tree_hw::Node<int>> res = tree_hw::tree_from_array(vec);
    EXPECT_EQ(res->val_, 5);
    EXPECT_EQ(res->left_, nullptr);
    EXPECT_EQ(res->right_, nullptr);
}

TEST(buildTree, missingRightChildren) {
    std::vector<int> vec = {10, 5, 15, 3, -1, 12, -1, 2};
    std::shared_ptr<tree_hw::Node<int>> res = tree_hw::tree_from_array(vec);

    EXPECT_EQ(res->val_, 10);
    EXPECT_NE(res->left_, nullptr);
    EXPECT_NE(res->right_, nullptr);

    // Проверка левого поддерева
    EXPECT_EQ(res->left_->val_, 5);
    EXPECT_NE(res->left_->left_, nullptr);
    EXPECT_EQ(res->left_->right_, nullptr); // Правый потомок отсутствует

    EXPECT_EQ(res->left_->left_->val_, 3);
    EXPECT_NE(res->left_->left_->left_, nullptr);
    EXPECT_EQ(res->left_->left_->right_, nullptr);

    EXPECT_EQ(res->left_->left_->left_->val_, 2);
    EXPECT_EQ(res->left_->left_->left_->left_, nullptr);
    EXPECT_EQ(res->left_->left_->left_->right_, nullptr);

    // Проверка правого поддерева
    EXPECT_EQ(res->right_->val_, 15);
    EXPECT_NE(res->right_->left_, nullptr);
    EXPECT_EQ(res->right_->right_, nullptr); // Правый потомок отсутствует

    EXPECT_EQ(res->right_->left_->val_, 12);
    EXPECT_EQ(res->right_->left_->left_, nullptr);
    EXPECT_EQ(res->right_->left_->right_, nullptr);
}

TEST(buildTree, negativeAndZeroValues) {
    std::vector<int> vec = {0, -5, 5, -10, -3, 3, 10};
    std::shared_ptr<tree_hw::Node<int>> res = tree_hw::tree_from_array(vec);

    EXPECT_EQ(res->val_, 0);
    EXPECT_NE(res->left_, nullptr);
    EXPECT_NE(res->right_, nullptr);

    // Левое поддерево
    EXPECT_EQ(res->left_->val_, -5);
    EXPECT_NE(res->left_->left_, nullptr);
    EXPECT_NE(res->left_->right_, nullptr);

    EXPECT_EQ(res->left_->left_->val_, -10);
    EXPECT_EQ(res->left_->left_->left_, nullptr);
    EXPECT_EQ(res->left_->left_->right_, nullptr);

    EXPECT_EQ(res->left_->right_->val_, -3);
    EXPECT_EQ(res->left_->right_->left_, nullptr);
    EXPECT_EQ(res->left_->right_->right_, nullptr);

    // Правое поддерево
    EXPECT_EQ(res->right_->val_, 5);
    EXPECT_NE(res->right_->left_, nullptr);
    EXPECT_NE(res->right_->right_, nullptr);

    EXPECT_EQ(res->right_->left_->val_, 3);
    EXPECT_EQ(res->right_->left_->left_, nullptr);
    EXPECT_EQ(res->right_->left_->right_, nullptr);

    EXPECT_EQ(res->right_->right_->val_, 10);
    EXPECT_EQ(res->right_->right_->left_, nullptr);
    EXPECT_EQ(res->right_->right_->right_, nullptr);
}

TEST(buildTree, withHoles) {
    std::vector<int> vec = {10, -1, 20, -1, -1, 15, 25}; // -1 означает отсутствие узла

    std::shared_ptr<tree_hw::Node<int>> res = tree_hw::tree_from_array(vec);

    EXPECT_EQ(res->val_, 10);
    EXPECT_EQ(res->left_, nullptr); // Левый потомок отсутствует
    EXPECT_NE(res->right_, nullptr);

    EXPECT_EQ(res->right_->val_, 20);
    EXPECT_NE(res->right_->left_, nullptr);
    EXPECT_NE(res->right_->right_, nullptr);

    EXPECT_EQ(res->right_->left_->val_, 15);
    EXPECT_EQ(res->right_->left_->left_, nullptr);
    EXPECT_EQ(res->right_->left_->right_, nullptr);

    EXPECT_EQ(res->right_->right_->val_, 25);
    EXPECT_EQ(res->right_->right_->left_, nullptr);
    EXPECT_EQ(res->right_->right_->right_, nullptr);
}
