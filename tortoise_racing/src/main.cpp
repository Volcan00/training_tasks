#include "Tortoise.h"
#include <iostream>

int main()
{
    std::vector<std::tuple<int, int, int>> testCases {
        {720, 850, 70},
        {80, 91, 37},
        {850, 720, 70},
        {720, 720, 100},
    };

    for (const auto& testCase : testCases)
    {
        int v1, v2, g;
        std::tie(v1, v2, g) = testCase;

        std::vector<int> result { Tortoise::race(v1, v2, g) };

        if (result == std::vector<int>{-1, -1, -1})
        {
            std::cout << "v1 = " << v1 << ", v2 = " << v2 << ", g = " << g << " -> B will never catch A." << std::endl;
        }
        else
        {
            std::cout << "v1 = " << v1 << ", v2 = " << v2 << ", g = " << g << " -> Time: ";
            std::cout << result[0] << " hour(s), " << result[1] << " minute(s), " << result[2] << " second(s)." << std::endl;
        }
    }

    return 0;
}