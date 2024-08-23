#include "Convert.h"
#include <iostream>

int main()
{
    std::cout << uint32_to_ip(0) << "\n";
    std::cout << uint32_to_ip(32) << "\n";
    std::cout << uint32_to_ip(2149583361) << "\n";
    std::cout << uint32_to_ip(2154959208) << "\n";

    return 0;
}