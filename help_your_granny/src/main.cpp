#include "Tour.h"
#include <iostream>

int main()
{
    std::vector<std::string> friends1 { "A1", "A2", "A3", "A4", "A5" };
    std::vector<std::vector<std::string>> fTowns1 { {"A1", "X1"}, {"A2", "X2"}, {"A3", "X3"}, {"A4", "X4"} };
    stringdblmap distTable1 { {"X1", 100.0}, {"X2", 200.0}, {"X3", 250.0}, {"X4", 300.0} };

    std::cout << Tour::tour(friends1, fTowns1, distTable1) << '\n'; 

    std::vector<std::string> friends2 { "A1", "A2", "A3", "A4", "A5" };
    std::vector<std::vector<std::string>> fTowns2 { {"A1", "X1"}, {"A2", "X2"}, {"A3", "X3"}, {"A4", "X4"}, {"A5", "X5"} };
    stringdblmap distTable2 { {"X1", 100.0}, {"X2", 200.0}, {"X3", 250.0}, {"X4", 300.0}, {"X5", 320.0} };

    std::cout << Tour::tour(friends2, fTowns2, distTable2) << '\n'; 

    return 0;
}