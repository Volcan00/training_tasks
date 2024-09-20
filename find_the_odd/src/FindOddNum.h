#ifndef FIND_ODD_NUM_H
#define FIND_ODD_NUM_H

#include <vector>
#include <unordered_map>

int findOdd(const std::vector<int>& numbers)
{
    std::unordered_map<int, int> numbersCounter {};

    for(int n : numbers)
        ++numbersCounter[n];

    for(const auto& pair : numbersCounter)
    {
        if(pair.second % 2 == 1)
            return pair.first;
    }

    return 0;
}

#endif