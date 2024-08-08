#include "RomanHelper.h"
#include <iostream>

int main() {
    RomanHelper rh;
    
    int number = 1987;
    std::string romanNumeral = rh.to_roman(number);
    std::cout << "The Roman numeral for " << number << " is: " << romanNumeral << std::endl;

    std::string romanString = "MCMLXXXVII";
    unsigned int numericValue = rh.from_roman(romanString);
    std::cout << "The numeric value for " << romanString << " is: " << numericValue << std::endl;

    
    int outOfRangeNumber = 4000;
    std::string outOfRangeRoman = rh.to_roman(outOfRangeNumber);
    std::cout << "The Roman numeral for " << outOfRangeNumber << " is: " << outOfRangeRoman << std::endl;

    return 0;
}