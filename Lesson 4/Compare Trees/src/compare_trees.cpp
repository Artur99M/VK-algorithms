#include "compare_trees.hpp"

namespace tree_hw {

template <typename T>
bool isSameTree(std::shared_ptr<Node<T>> a, std::shared_ptr<Node<T>> b) {
    if (a == nullptr && b == nullptr)
        return true;

    if (a == nullptr || b == nullptr)
        return false;

    if (a->val_ != b->val_)
        return false;

    return isSameTree(a->left_, b->left_) && isSameTree(a->right_, b->right_);
}

template bool isSameTree(std::shared_ptr<Node<int>> a, std::shared_ptr<Node<int>> b);
} //namepsace tree_hw
