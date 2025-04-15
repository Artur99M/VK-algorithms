#include "sub_str.hpp"
#include <iostream>
#include <algorithm>

int main() {
    std::string a, b;
    std::getline(std::cin, a);
    std::getline(std::cin, b);

    char ans = extraLetter(a, b);
    if (ans != '\0')
        std::cout << ans;
    else
        std::cout << "\"\"";

    std::cout << "\n";
}
