#include <iostream>
#include "VeryEasyTask.hpp"

unsigned copyTime(unsigned n, unsigned x, unsigned y) {
    unsigned l = 0, r = (n - 1) * (x > y ? x : y);

    while (l + 1 < r) {
        unsigned mid = (r + l) / 2;
        if (mid/x + mid/y < n - 1 )
            l = mid;
        else
            r = mid;
    }

    return r + (x < y ? x : y);
}
