#ifndef FIND_UNIQUE_NUMBER_H
#define FIND_UNIQUE_NUMBER_H

#include <vector>

float find_uniq(const std::vector<float>& arr)
{
    if(arr[0] != arr[1])
        return arr[0] == arr[2] ? arr[1] : arr[0];

    for(size_t i = 2; i < arr.size(); ++i)
    {
        if(arr[i] != arr[0])
            return arr[i];
    }

    return arr[0];
}

#endif