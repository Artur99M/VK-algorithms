#include "mirror_tree.hpp"

namespace tree_hw {

template <typename T>
size_t dfs(std::shared_ptr<Node<T>> left, std::shared_ptr<Node<T>> right) {
    if (left == nullptr || right == nullptr)
        return 0;

    size_t count = 0;

    if (left->val_ == right->val_)
        count = 1;

    count += dfs(left->left_, right->right_);
    count += dfs(left->right_, right->left_);

    return count;
}

template <typename T>
size_t CountMirrorTwins(std::shared_ptr<Node<T>> root) {
    if (root == nullptr)
        return 0;

    return dfs(root->left_, root->right_);
}
template size_t CountMirrorTwins(std::shared_ptr<Node<int>> root);

} //namespace tree_hw
