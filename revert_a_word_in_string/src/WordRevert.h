#ifndef WORD_REVERT_H
#define WORD_REVERT_H

#include <string>
#include <sstream>
#include <algorithm>

std::string spinWords(const std::string& str)
{
    std::istringstream iss(str);
    std::string word {};
    std::string result {};

    while(iss >> word)
    {
        if(word.size() >= 5)
        {
            std::reverse(word.begin(), word.end());
        }

        result += word + (iss.eof() ? "" : " ");
    }

    return result;
}

#endif