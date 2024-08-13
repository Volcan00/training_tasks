#include "DigPow.h"
#include <string>
#include <cmath>

int DigPow::digPow(int n, int p)
{
    std::string numString { std::to_string(n) };
    int numSize { static_cast<int>(numString.size()) };

    int sumOfPows {};
    int nCopy{ n };

    for(int i = numSize - 1; i >= 0; --i)
    {
        sumOfPows += pow((nCopy % 10), (p + i));
        nCopy /= 10; 
    }

    if(sumOfPows % n == 0)
        return (sumOfPows / n);
    else
        return -1;
}