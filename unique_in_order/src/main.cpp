#include "UniqueInOrder.h"
#include <iostream>

int main() {
    std::vector<int> numbers {1, 2, 2, 3, 3, 3, 4, 5, 5};
    std::vector<int> uniqueNumbers { uniqueInOrder(numbers) };

    std::cout << "Unique in order (integers): ";
    for (int num : uniqueNumbers) {
        std::cout << num << " ";
    }
    std::cout << '\n';

    std::string text { "AAAABBBCCDAABBB" };
    std::vector<char> uniqueChars { uniqueInOrder(text) };

    std::cout << "Unique in order (characters): ";
    for (char ch : uniqueChars) {
        std::cout << ch << " ";
    }
    std::cout << '\n';

    std::vector<char> charVec {'A', 'A', 'B', 'C', 'C', 'C', 'D'};
    std::vector<char> uniqueCharVec { uniqueInOrder(charVec) };

    std::cout << "Unique in order (character vector): ";
    for (char ch : uniqueCharVec) {
        std::cout << ch << " ";
    }
    std::cout << "\n";

    return 0;
}