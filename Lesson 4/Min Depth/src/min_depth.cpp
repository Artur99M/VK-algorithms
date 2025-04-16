#include "min_depth.hpp"

namespace tree_hw {

template <typename T>
size_t minDepth(const std::shared_ptr<Node<T>> root) {
    if (root == nullptr)
        return 0;

    if (root->left_ == nullptr && root->right_ == nullptr)
        return 1;

    if (root->left_ != nullptr && root->right_ != nullptr) {
        size_t l = minDepth(root->left_),
               r = minDepth(root->right_);

        return 1 + (l > r ? l : r);
    }

    if (root->left_ != nullptr)
        return 1 + minDepth(root->left_);

    // if (root->right_ != nullptr)
        return 1 + minDepth(root->right_);

}

template size_t minDepth(const std::shared_ptr<Node<int>> root);
}
