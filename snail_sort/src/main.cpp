#include "SnailSort.h"
#include <iostream>

int main()
{
    std::vector<std::vector<int>> case1 {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            std::cout << case1[i][j] << " ";
        }
        std::cout << '\n';
    }

    std::vector<int> result1 { snailSort(case1) };

    for(int n : result1)
        std::cout << n << ' ';

    std::cout << '\n';

    return 0;
}