#include "Same.h"
#include <iostream>

int main()
{
    std::vector<int> a1 {2, 3, 4};
    std::vector<int> b1 {4, 9, 16};
    std::cout << "Test Case 1: " << (Same::comp(a1, b1) ? "Pass" : "Fail") << std::endl;

    std::vector<int> a2 {1, 2, 3};
    std::vector<int> b2 {1, 4, 9};
    std::cout << "Test Case 2: " << (Same::comp(a2, b2) ? "Pass" : "Fail") << std::endl;

    std::vector<int> a3 {0, 0, 0};
    std::vector<int> b3 {0, 0, 0};
    std::cout << "Test Case 3: " << (Same::comp(a3, b3) ? "Pass" : "Fail") << std::endl;

    std::vector<int> a4 {2, 2};
    std::vector<int> b4 {4, 4};
    std::cout << "Test Case 4: " << (Same::comp(a4, b4) ? "Fail" : "Pass") << std::endl;

    std::vector<int> a5 {1, 2, 3, 4};
    std::vector<int> b5 {1, 4, 9, 16}; // Unscrambled
    std::cout << "Test Case 5: " << (Same::comp(a5, b5) ? "Pass" : "Fail") << std::endl;

    std::vector<int> a6 {5, 6, 7};
    std::vector<int> b6 {25, 36, 49};
    std::cout << "Test Case 6: " << (Same::comp(a6, b6) ? "Pass" : "Fail") << std::endl;

    std::vector<int> a7 {0, 1, 2, 3};
    std::vector<int> b7 {0, 1, 4, 9};
    std::cout << "Test Case 7: " << (Same::comp(a7, b7) ? "Pass" : "Fail") << std::endl;

    std::vector<int> a8 {10, 11, 12};
    std::vector<int> b8 {100, 121, 144};
    std::cout << "Test Case 8: " << (Same::comp(a8, b8) ? "Pass" : "Fail") << std::endl;

    return 0;
}