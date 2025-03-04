#include <iostream>
#include <list>
#include <unordered_map>
#include "cycle_list.hpp"


int main() {
//     std::list<int> arr;
//     using it = std::list<int>::iterator;
//     std::unordered_map<int, it> hash;
//
//     size_t size;
//     std::cin >> size;
//     for (size_t i = 0; i < size; ++i) {
//         int x, next;
//         std::cin >> x >> next;
//         if (hash.find(next) == hash.end()) {
//             arr.push_back(x);
//         } else {
//             arr.insert(hash[x], )
//         }
//     }

    size_t size;
    std::cin >> size;
    Artur99M::Node<int>* array = reinterpret_cast<Artur99M::Node<int>*>(operator new(sizeof(Artur99M::Node<int>) * size));
    for (size_t i = 0; i < size; ++i) {
        int x, next;
        std::cin >> x >> next;
        array[i].value = x;
        array[i].next = ((next == -1) ? nullptr : (array + next));
    }
    std::cout << Artur99M::has_cycle(array) << std::endl;
    operator delete(array);
}
