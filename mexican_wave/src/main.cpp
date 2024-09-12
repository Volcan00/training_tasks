#include "MexicanWave.h"
#include <iostream>

int main()
{
    std::vector<std::string> mexicanWave { wave("hello") };

    for(const auto& str : mexicanWave)
        std::cout << str << "\n";

    return 0;
}