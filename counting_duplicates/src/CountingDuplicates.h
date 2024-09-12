#ifndef COUNTING_DUPLICATES_H
#define COUNTING_DUPLICATES_H

#include <string>
#include <unordered_map>

int duplicateCount(const std::string& in)
{
    std::unordered_map<char, int> duplicateMap {};

    for(char c : in)
    {
        ++duplicateMap[tolower(c)];
    }

    int duplicateCounter {};

    for(const auto& pair : duplicateMap)
    {
        if(pair.second > 1)
            ++duplicateCounter;
    }

    return duplicateCounter;
}

#endif