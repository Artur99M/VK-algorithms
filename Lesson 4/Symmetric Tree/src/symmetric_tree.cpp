#include "symmetric_tree.hpp"
#include "node.hpp"
#include <deque>
namespace tree_hw {

template <typename T>
bool isSymmetricBFS(const std::shared_ptr<Node<T>> root) {
    if (root == nullptr)
        return true;

    std::deque<std::shared_ptr<Node<T>>> queue = {root};

    while (queue.size() > 0) {
        size_t sz = queue.size();
        for (size_t i = 0; i < sz; ++i) {

            if (queue[i] == nullptr && queue[sz - i - 1] == nullptr)
                continue;

            if (queue[i] == nullptr || queue[sz - i - 1] == nullptr)
                return false;

            if (queue[i]->val_ != queue[sz - i - 1]->val_)
                return false;

            queue.push_back(queue[i]->left_);
            queue.push_back(queue[i]->right_);
        }
        queue.erase(queue.begin(), queue.begin() + sz);
    }

    return true;
}

template <typename T>
std::vector<T>& deptSearch(std::shared_ptr<Node<T>> root, std::vector<T>& res) {
    if (root == nullptr)
        return res;

    deptSearch(root->left_, res);
    res.push_back(root->val_);
    deptSearch(root->right_, res);

    return res;
}

template <typename T>
bool isSymmetricDFS(const std::shared_ptr<Node<T>> root) {
    if (root == nullptr)
        return true;

    std::vector<T> data;
    deptSearch(root, data);

    for (size_t i = 0, j = data.size() - 1, sz_2 = data.size() / 2;
    i < sz_2; ++i, --j)
        if (data[i] != data[j])
            return false;

    return true;
}

template bool isSymmetricBFS(const std::shared_ptr<Node<int>> root);
template bool isSymmetricDFS(const std::shared_ptr<Node<int>> root);
} //namespace tree_hw
