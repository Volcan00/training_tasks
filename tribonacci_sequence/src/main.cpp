#include "Tribonacci.h"
#include <iostream>

int main() 
{
    std::vector<int> signature1 {0, 1, 1};
    int n1 { 10 };
    
    std::vector<int> result1 { tribonacci(signature1, n1) };
    
    std::cout << "Tribonacci sequence (n = 10): ";
    for (int num : result1) {
        std::cout << num << " ";
    }
    std::cout << '\n';

    std::vector<int> signature2 {1, 1, 1};
    int n2 { 5 };

    std::vector<int> result2 { tribonacci(signature2, n2) };

    std::cout << "Tribonacci sequence (n = 5): ";
    for (int num : result2) {
        std::cout << num << " ";
    }
    std::cout << '\n';

    std::vector<int> signature3 {1, 1, 2};
    int n3 { 0 };

    std::vector<int> result3 { tribonacci(signature3, n3) };

    std::cout << "Tribonacci sequence (n = 0): ";
    for (int num : result3) {
        std::cout << num << " ";
    }
    std::cout << '\n';

    return 0;
}