#include <iostream>
#include <string>
#include "palindrome.hpp"

int main() {
    std::string str;
    std::getline(std::cin, str);
    std::cout << Artur99M::is_palindrome(str);

}
