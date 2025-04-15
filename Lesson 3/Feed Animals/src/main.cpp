#include "feed_animals.hpp"
#include <iostream>


int main() {
    size_t size_animals;
    std::cin >> size_animals;

    std::vector<unsigned> animals;
    animals.reserve(size_animals);

    for (size_t i = 0; i < size_animals; ++i) {
        unsigned x;
        std::cin >> x;
        animals.push_back(x);
    }

    size_t size_food;
    std::cin >> size_food;

    std::vector<unsigned> food;
    food.reserve(size_food);

    for (size_t i = 0; i < size_food; ++i) {
        unsigned x;
        std::cin >> x;
        food.push_back(x);
    }

    std::cout << feedAnimals(animals, food);
}
