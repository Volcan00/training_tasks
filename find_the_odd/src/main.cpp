#include "FindOddNum.h"
#include <iostream>

int main()
{
    std::cout << findOdd( {20,1,-1,2,-2,3,3,5,5,1,2,4,20,4,-1,-2,5} ) << '\n';
    std::cout << findOdd( {1,1,2,-2,5,2,4,4,-1,-2,5} ) << '\n';
    std::cout << findOdd( {20,1,1,2,2,3,3,5,5,4,20,4,5} ) << '\n';
    std::cout << findOdd( {10} ) << '\n';
    std::cout << findOdd( {1,1,1,1,1,1,10,1,1,1,1} ) << '\n';

    return 0;
}