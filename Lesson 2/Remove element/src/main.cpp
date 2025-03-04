#include <iostream>
#include <list>
#include <unordered_map>
#include "remove.hpp"


int main() {
    size_t size;
    std::cin >> size;
    Artur99M::Node<int>* array = reinterpret_cast<Artur99M::Node<int>*>(operator new(sizeof(Artur99M::Node<int>) * size));
    for (size_t i = 0; i < size; ++i) {
        int x, next;
        std::cin >> x >> next;
        array[i].value = x;
        array[i].next = ((next == -1) ? nullptr : (array + next));
    }
    int delete_val;
    std::cin >> delete_val;
    Artur99M::Node<int>* head = array;
    head = Artur99M::remove(head, delete_val);
    for (Artur99M::Node<int>* it = head; it != nullptr; it = it->next) {
        std::cout << it->value << ' ';
    }
    operator delete(array);
}
