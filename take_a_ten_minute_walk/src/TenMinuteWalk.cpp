#include "TenMinuteWalk.h"
#include <unordered_map>

// Function checks the passed array of directions and  
// returns TRUE if the walk takes 10 minutes and returns
// you to the starting point 
bool isValidWalk(std::vector<char> walk)
{
    if(walk.size() != 10)
        return false;

    std::unordered_map<char, int> directionCount {};
    std::unordered_map<char, char> opositeDirections {
                                                     { 'n', 's' },
                                                     { 's', 'n' },
                                                     { 'w', 'e' },
                                                     { 'e', 'w' }
                                                     };

    for(char dir : walk)
        ++directionCount[dir];

    for(const auto& pair : directionCount)
    {
        if(directionCount[pair.first] != directionCount[opositeDirections[pair.first]])
            return false;
    }

    return true;
}