#pragma once
#include "node.hpp"
#include <vector>
#include <memory>

namespace tree_hw {

template <typename T>
std::shared_ptr<Node<T>> tree_from_array(const std::vector<T>& vec);

} //namespace tree_hw
