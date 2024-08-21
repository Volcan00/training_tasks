#include "Tortoise.h"
#include <cmath>

std::vector<int> Tortoise::race(int v1, int v2, int g)
{
    if(v1 >= v2)
        return {-1, -1, -1};

    std::vector<int> result {};

    int relativeSpeed { v2 - v1 };

    int totalSeconds = (g * 3600) / relativeSpeed;

    // Convert total seconds to hours, minutes, and seconds
    int hours = totalSeconds / 3600;
    int minutes = (totalSeconds % 3600) / 60;
    int seconds = totalSeconds % 60;

    return {hours, minutes, seconds};
}