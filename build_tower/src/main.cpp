#include "BuildTower.h"
#include <iostream>

int main()
{
    std::vector<std::string> tower { towerBuilder(6) };

    for(const auto& floor : tower)
    {
        std::cout << floor << '\n';
    }

    return 0;
}