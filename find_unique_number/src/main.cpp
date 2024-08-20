#include "FindUniqueNumber.h"
#include <iostream>

int main()
{
    std::cout << find_uniq({1, 1, 1, 2, 1, 1}) << std::endl;
    std::cout << find_uniq({0, 0, 0.55, 0, 0}) << std::endl;

    return 0;
}