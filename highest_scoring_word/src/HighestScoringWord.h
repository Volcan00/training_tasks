#include <string>
#include <vector>
#include <sstream>

std::string highestScoringWord(const std::string& str)
{
    std::vector<std::pair<std::string, int>> wordScoreArr {};

    std::istringstream iss(str);
    std::string word {};

    while(iss >> word)
    {
        int wordScore {};

        for(char c : word)
        {
            wordScore += c - 96;
        }

        wordScoreArr.push_back({word, wordScore});
    }

    int maxScore {};

    for(const auto& pair : wordScoreArr)
    {
        if(pair.second > maxScore) maxScore = pair.second;
    }

    for(const auto& pair : wordScoreArr)
    {
        if(maxScore == pair.second) return pair.first;
    }

    return "";
}