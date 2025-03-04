#pragma once

#include "node.hpp"

namespace Artur99M {

template<typename T>
Node<T>* remove(Node<T>* head, T val) {
    Node<T> dummy;
    dummy.next = head;
    Node<T>* prev = &dummy;
    Node<T>* cur  = head;

    while (cur != nullptr) {
        if (cur->value == val) {
            prev->next = cur->next;
            cur->next = nullptr;
        } else {
            prev = cur;
        }
        cur = cur->next;
    }

    return dummy.next;
}
} //namespace Artur99M
