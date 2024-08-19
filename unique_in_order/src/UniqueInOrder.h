#ifndef UNIQUE_IN_ORDER_H
#define UNIQUE_IN_ORDER_H

#include <vector>
#include <string>

template <typename T>
std::vector<T> uniqueInOrder(const std::vector<T>& iterable)
{
    std::vector<T> result {};

    int arrSize { static_cast<int>(iterable.size()) };

    if(arrSize == 0)
        return result;
    if(arrSize == 1)
    {
        result.push_back(iterable[0]);
        return result;
    }

    for(T elem : iterable)
    {
        if(!result.empty())
        {
            if(result.back() != elem)
                result.push_back(elem);
            else
                continue;
        }
        else
            result.push_back(elem);
    }

    return result;
}

std::vector<char> uniqueInOrder(const std::string& iterable)
{
    std::vector<char> result {};

    int arrSize { static_cast<int>(iterable.size()) };

    if(arrSize == 0)
        return result;
    if(arrSize == 1)
    {
        result.push_back(iterable[0]);
        return result;
    }

    for(char ch : iterable)
    {
        if(!result.empty())
        {
            if(result.back() != ch)
                result.push_back(ch);
            else
                continue;
        }
        else
            result.push_back(ch);
    }

    return result;
}

#endif