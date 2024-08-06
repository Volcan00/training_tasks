#include "PigLatin.h"
#include <sstream>

std::vector<std::string> splitStringWithPunctuation(const std::string& str)
{
    std::vector<std::string> words {};
    std::string word {};

    for(char ch : str)
    {
        if(std::isspace(ch))
        {
            if(!word.empty())
            {
                words.push_back(word);
                word.clear();
            }
        }
        else
        {
            word += ch;
        }
    }

    if(!word.empty())
    {
        words.push_back(word);
    }

    return words;
}

std::string transformWord(const std::string& word)
{
    if(std::isalpha(word[0]))
    {
        return word.substr(1) + word[0] + "ay";
    }

    return word;
}

std::string pig_it(std::string str)
{
    std::vector words { splitStringWithPunctuation(str) };

    for(auto& w : words)
    {
        w = transformWord(w);
    }

    std::ostringstream oss;
    for(const auto& w : words)
    {
        oss << w << " ";
    }

    std::string output { oss.str() };

    if(!output.empty())
        output.pop_back();

    return output;
}