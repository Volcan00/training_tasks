#include "DuplicateEncoder.h"
#include <iostream>

int main()
{
    std::cout << duplicate_encoder("recede") << "\n";
    std::cout << duplicate_encoder("recede") << "\n";
    std::cout << duplicate_encoder("Success") << "\n";
    std::cout << duplicate_encoder("(( @") << "\n";

    return 0;
}