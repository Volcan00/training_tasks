#include "Functions.h"

int gcd(int a, int b)
{
    while(b != 0)
    {
        int temp { b };
        b = a % b;
        a = temp;
    }

    return a;
}

int eulersTotientFunction(int n)
{
    if(n == 1)
    {
        return n;
    }

    int counter {};

    for(int i = 1; i <= n; ++i)
    {
        if(gcd(i, n) == 1)
            ++counter;
    }

    return counter;
}