#include "array_tree.hpp"

namespace tree_hw {

template <typename T>
std::shared_ptr<Node<T>> buildTree(const std::vector<T>& vec, size_t i) {
    if (i >= vec.size()) {
        return nullptr;
    }
    if (vec[i] == -1) // в данном случае -1 показывает, что узла нет
        return nullptr;

    std::shared_ptr<Node<T>> root{new Node<T>};
    root->val_   = vec[i];
    root->left_  = buildTree(vec, 2 * i + 1);
    root->right_ = buildTree(vec, 2 * i + 2);

    return root;

}
template <typename T>
std::shared_ptr<Node<T>> tree_from_array(const std::vector<T>& vec) {
    return buildTree(vec, 0);
}

template std::shared_ptr<Node<int>> tree_from_array(const std::vector<int>&);
} //namespace tree_hw
