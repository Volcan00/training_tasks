#include "DigPow.h"
#include <iostream>

int main()
{
    DigPow d {};

    std::cout << d.digPow(89, 1) << "\n\n";
    std::cout << d.digPow(92, 1) << "\n\n";
    std::cout << d.digPow(695, 2) << "\n\n";
    std::cout << d.digPow(46288, 3) << "\n\n";

    return 0;
}