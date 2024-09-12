#include "CountingDuplicates.h"
#include <iostream>

int main()
{
    std::cout << duplicateCount("abcde") << '\n';
    std::cout << duplicateCount("aabbcde") << '\n';
    std::cout << duplicateCount("aabBcde") << '\n';
    std::cout << duplicateCount("indivisibility") << '\n';
    std::cout << duplicateCount("Indivisibilities") << '\n';
    std::cout << duplicateCount("aA11") << '\n';
    std::cout << duplicateCount("ABBA") << '\n';

    return 0;
}