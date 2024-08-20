#include "ConsecutiveStrings.h"
#include <iostream>

int main()
{
    std::vector<std::string> strArr1 { "tree", "foling", "trashy", "blue", "abcdef", "uvwxyz" };
    int k1 { 2 };
    std::cout << "Longest consecutive string (Test 1): " << LongestConsec::longestConsec(strArr1, k1) << std::endl;

    std::vector<std::string> strArr2 { "zone", "abigail", "theta", "form", "libe", "zas", "theta", "abigail" };
    int k2 { 2 };
    std::cout << "Longest consecutive string (Test 2): " << LongestConsec::longestConsec(strArr2, k2) << std::endl;

    std::vector<std::string> strArr3 { "one", "two", "three" };
    int k3 { 1 };
    std::cout << "Longest consecutive string (Test 3): " << LongestConsec::longestConsec(strArr3, k3) << std::endl;

    std::vector<std::string> strArr4 {};
    int k4 { 2 };
    std::cout << "Longest consecutive string (Test 4): " << LongestConsec::longestConsec(strArr4, k4) << std::endl;

    std::vector<std::string> strArr5 { "a", "b", "c" };
    int k5 { 4 };
    std::cout << "Longest consecutive string (Test 5): " << LongestConsec::longestConsec(strArr5, k5) << std::endl;

    return 0;
}