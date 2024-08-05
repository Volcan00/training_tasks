#include "Redistribution.h"
#include <algorithm>

unsigned int mem_alloc(const std::array<unsigned int, 16>&banks)
{
    std::array<unsigned int, 16> banksCopy { banks };
    std::unordered_set<std::array<unsigned int, 16>, ArrayHash> seenConfiguration {};
    int cycles {};

    while(true)
    {
        if(seenConfiguration.find(banksCopy) != seenConfiguration.end())
            break;

        seenConfiguration.insert(banksCopy);

        auto maxElemIter { std::max_element(banksCopy.begin(), banksCopy.end()) };
        int index { static_cast<int>(std::distance(banksCopy.begin(), maxElemIter)) };
        unsigned int blocks { banksCopy[index] };
        banksCopy[index] = 0;

        std::size_t n { banksCopy.size() };
        for(std::size_t i = 0; i < blocks; ++i)
        {
            banksCopy[(index + 1 + i) % n]++;
        }

        cycles++;
    }

    return cycles;
}