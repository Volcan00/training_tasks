#ifndef TOUR_H
#define TOUR_H

#include <vector>
#include <string>
#include <unordered_map>

typedef std::unordered_map<std::string, double> stringdblmap;

class Tour
{
public:
    static int tour(std::vector<std::string> &arrFriends, std::vector<std::vector<std::string>> &ftwns, stringdblmap &h);
};

#endif