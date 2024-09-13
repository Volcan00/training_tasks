#include "GetPins.h"
#include <iostream>

int main()
{
    std::vector<std::string> variations { get_pins("11") };

    for(const auto& variation : variations)
    {
        std::cout << variation << " ";
    }

    std::cout << '\n';

    return 0;
}