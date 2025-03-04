#pragma once

namespace Artur99M {

template <typename T>
struct Node {
    T value;
    Node<T>* next;
};

} //namespace Artur99M
