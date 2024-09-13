#ifndef GET_PINS_H
#define GET_PINS_H

#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iostream>

std::vector<std::string> get_pins(std::string observed)
{
    std::unordered_map<char, std::vector<char>> adjacentDigits { 
                                                                 {'1', {'1', '2', '4'}}, {'2', {'1', '2', '3', '5'}}, {'3', {'2', '3', '6',}}, {'4', {'1', '4', '5', '7'}},
                                                                 {'5', {'2', '4', '5', '6', '8'} }, {'6', {'3', '5', '6', '9'}}, {'7', {'4', '7', '8'}},
                                                                 {'8', {'0', '5', '7', '8', '9'}}, {'9', {'6', '8', '9'}}, {'0', {'0', '8'}} 
                                                               };

    std::vector<std::string> result {""};

    for(char digit : observed)
    {
        std::vector<std::string> newResult {};

        for(const std::string& partialPIN : result)
        {
            for(char adjDig : adjacentDigits[digit])
            {
                newResult.push_back(partialPIN + adjDig);
            }
        }

        result = newResult;
    }
    
    return result;
}

#endif