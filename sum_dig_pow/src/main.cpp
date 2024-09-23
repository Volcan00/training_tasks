#include "SumDigPow.h"
#include <iostream>

int main()
{
    std::vector case1 { sumDigPow(1, 10) };

    for(const auto& n : case1)
        std::cout << n << " ";

    std::cout << '\n';

    std::vector case2 { sumDigPow(1, 100) };

    for(const auto& n : case2)
        std::cout << n << " ";

    std::cout << '\n';

    std::vector case3 { sumDigPow(90, 100) };

    for(const auto& n : case3)
        std::cout << n << " ";

    std::cout << '\n';

    return 0;
}