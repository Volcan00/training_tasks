#ifndef SUM_DIG_POW_H
#define SUM_DIG_POW_H

#include <vector>
#include <string>
#include <cmath>

std::vector<unsigned int> sumDigPow(unsigned int a, unsigned int b)
{
    std::vector<unsigned int> result {};

    for(int i = a; i <= b; ++i)
    {
        int sum {};
        int temp { i };
        std::string numStr { std::to_string(temp) };

        int numSize { static_cast<int>(numStr.size()) };

        while(numSize > 0)
        {
            int reminder { temp % 10 };

            sum += pow(reminder, numSize);
            temp = (temp - reminder) / 10;
            --numSize;
        }

        if(sum == i)
            result.push_back(i);
    }

    return result;
}

#endif