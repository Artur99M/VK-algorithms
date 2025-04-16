#pragma once
#include "node.hpp"

namespace tree_hw {

template <typename T>
bool isSymmetricBFS(const std::shared_ptr<Node<T>> root);
template <typename T>
bool isSymmetricDFS(const std::shared_ptr<Node<T>> root);

} //namespace tree_hw
