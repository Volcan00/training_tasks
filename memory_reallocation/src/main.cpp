#include <iostream>
#include "Redistribution.h"

int main() {
    std::array<unsigned int, 16> banks = {0, 2, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    int cycles = mem_alloc(banks);

    std::cout << "Number of cycles before a repeat configuration: " << cycles << std::endl;

    return 0;
}