#include "TenMinuteWalk.h"
#include <iostream>

int main()
{

    std::vector<char> firstVector { 'n' };
    std::cout << std::boolalpha << isValidWalk(firstVector) << '\n';

    std::vector<char> secondVector{ 'n','s','n','s','n','s','n','s','n','s' };
    std::cout << std::boolalpha << isValidWalk(secondVector) << '\n';

    std::vector<char> thirdVector{ 'n','s','n','s','n','s','n','s','n','s','n','s' };
    std::cout << std::boolalpha << isValidWalk(thirdVector) << '\n';

    std::vector<char> fourthVector { 'n','s','n','s','n','s','n','s','n','n' };
    std::cout << std::boolalpha << isValidWalk(fourthVector) << '\n';

    return 0;
}