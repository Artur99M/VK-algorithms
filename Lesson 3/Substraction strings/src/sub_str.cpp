#include "sub_str.hpp"
#include <unordered_map>
#include <iostream>

char extraLetter(std::string a, std::string b) {

    std::unordered_map<char, unsigned> hashTableB;
    for (char i : b) {
        if (hashTableB.find(i) == hashTableB.end())
            hashTableB.emplace(i, 0);
        hashTableB[i] += 1;
    }

    for (char i : a) {
        if (--hashTableB[i] == 0)
            hashTableB.erase(i);
    }

    if (hashTableB.size() > 0)
        return hashTableB.begin()->first;
    else
        return '\0';
}
