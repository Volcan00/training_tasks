#include "Same.h"
#include <cmath>
#include <algorithm>
#include <iostream>

bool Same::comp(std::vector<int>&a, std::vector<int>&b)
{
    if(a.size() != b.size())
        return false;

    for(size_t i = 0; i < a.size(); ++i)
    {
        a[i] = pow(a[i], 2);
    }

    std::sort(a.begin(), a.end());
    std::sort(b.begin(), b.end());

    return a == b;
}