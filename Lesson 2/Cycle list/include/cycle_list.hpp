#pragma once
#include "node.hpp"
#include <iostream>
namespace Artur99M {

template<typename T>
bool has_cycle(std::list<T> arr) {
    for (auto fast = arr.begin(), slow = arr.begin(); fast != arr.end(); ++slow, ++fast) {
        if (fast == slow) return true;

        if ((++fast) == arr.end()) break;
    }

    return false;
}

template<typename T>
bool has_cycle(Node<T>* arr) {
    for (auto fast = arr->next, slow = arr; fast != nullptr; slow = slow->next, fast = fast->next->next) {
        if (fast == slow) return true;
        if (fast->next == nullptr) break;
    }

    return false;
}
}
