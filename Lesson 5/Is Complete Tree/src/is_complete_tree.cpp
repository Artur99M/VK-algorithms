#include "is_complete_tree.hpp"
#include <queue>

namespace tree_hw {

template <typename T>
bool isCompleteTree(std::shared_ptr<Node<T>> root) {
    if (root == nullptr)
        return true;

    std::queue<std::shared_ptr<Node<T>>> queue;
    queue.push(root);
    bool seenNull = false;

    while (!queue.empty()) {
        std::shared_ptr<Node<T>> node = queue.back();
        queue.pop();

        if (node == nullptr)
            seenNull = true;

        else {
            if (seenNull)
                return false;

            queue.push(node->left_);
            queue.push(node->right_);
        }
    }

    return true;
}

template bool isCompleteTree(std::shared_ptr<Node<int>> root);
} //namespace tree_hw
