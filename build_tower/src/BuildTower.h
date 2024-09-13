#ifndef BUILD_TOWER_H
#define BUILD_TOWER_H

#include <string>
#include <vector>

std::vector<std::string> towerBuilder(unsigned nFloors)
{
    std::vector<std::string> result {};

    std::string floor (nFloors * 2 - 1, ' ');

    for(size_t i = 0; i < nFloors; ++i)
    {
        if(i == 0)
        {
            floor[floor.size() / 2 + i] = '*';
            
            result.push_back(floor);
        }
        else
        {
            floor[floor.size() / 2 + i] = '*';
            floor[floor.size() / 2 - i] = '*';

            result.push_back(floor);
        }
    }

    return result;
}

#endif