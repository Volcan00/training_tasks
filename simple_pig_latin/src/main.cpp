#include "PigLatin.h"
#include <iostream>


int main()
{
    std::string input { "Hello world !" };

    std::cout << pig_it(input) << '\n';

    return 0;
}