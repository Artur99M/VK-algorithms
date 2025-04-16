#include "sub_trees.hpp"
#include "compare_trees.hpp"
namespace tree_hw {

template <typename T>
bool isSubTree(std::shared_ptr<Node<T>> a, std::shared_ptr<Node<T>> b) {
    if (b == nullptr)
        return true;

    if (a == nullptr)
        return false;

    if (isSameTree(a, b))
        return true;

    return isSubTree(a->left_, b) || isSubTree(a->right_, b);
}

template bool isSubTree(std::shared_ptr<Node<int>> a, std::shared_ptr<Node<int>> b);
} //namepsace tree_hw
