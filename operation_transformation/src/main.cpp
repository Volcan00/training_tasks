#include "Transform.h"
#include <iostream>

int main()
{
    std::cout << Transform::operation(1, 1) << '\n';
    std::cout << Transform::operation(4, 1) << '\n';
    std::cout << Transform::operation(1, 4) << '\n';
    std::cout << Transform::operation(9, 2) << '\n';
    std::cout << Transform::operation(4194304, 1) << '\n';

    return 0;
}