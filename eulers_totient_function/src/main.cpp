#include "Functions.h"
#include <iostream>

int main()
{
    std::cout << "Enter an integer: ";
    int n {};
    std::cin >> n;

    if(n < 1 || n > 1000)
    {
        std::cout << "Input out of range\n";
        return 1;
    }

    int result { eulersTotientFunction(n) };
    std::cout << "phi(" << n << ") = " << result << '\n';

    return 0;
}