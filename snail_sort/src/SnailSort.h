#ifndef SNAIL_SORT_H
#define SNAIL_SORT_H

#include <vector>
#include <iostream>

std::vector<int> snailSort(const std::vector<std::vector<int>>& snailMap)
{
    std::vector<int> result {};

    if (snailMap.empty() || snailMap[0].empty()) {
        return result;
    }

    int top { 0 };
    int bottom { static_cast<int>(snailMap.size()) };
    int left { 0 };
    int right { static_cast<int>(snailMap[0].size()) };


    while(top <= bottom && left <= right)
    {
        for(int i = left; i < right; ++i)
            result.push_back(snailMap[top][i]);

        ++top;

        for(int i = top; i < bottom; ++i)
            result.push_back(snailMap[i][bottom - 1]);

        --right;

        for(int i = right - 1; i >= left; --i)
            result.push_back(snailMap[bottom - 1][i]);
        
        --bottom;

        for(int i = bottom - 1; i >= top; --i)
            result.push_back(snailMap[i][left]);

        ++left;
    }

    return result;
}

#endif