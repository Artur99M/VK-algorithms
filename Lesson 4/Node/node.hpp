#pragma once
#include <memory>

namespace tree_hw {

template <typename T>
struct Node {
    T                        val_            ;
    std::shared_ptr<Node<T>> left_  = nullptr;
    std::shared_ptr<Node<T>> right_ = nullptr;
};

} //namespace tree_hw
