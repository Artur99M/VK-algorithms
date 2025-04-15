#include "feed_animals.hpp"
#include <algorithm>

unsigned feedAnimals(std::vector<unsigned> animals, std::vector<unsigned> food) {
    if (animals.size() == 0 || food.size() == 0)
        return 0;

    auto cmp = [](unsigned x, unsigned y){return x < y;};
    std::sort(animals.begin(), animals.end(), cmp);
    std::sort(food.begin(), food.end(), cmp);

    unsigned count = 0;

    for (unsigned f : food) {
        if (f >= animals[count])
            ++count;

        if (count == animals.size())
            break;
    }

    return count;
}
