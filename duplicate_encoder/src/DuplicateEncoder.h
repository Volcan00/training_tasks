#include <string>
#include <unordered_map>

std::string duplicate_encoder(const std::string& word)
{
    std::unordered_map<char, int> charCounter {};

    for(char c : word) {
        ++charCounter[tolower(c)];
    }

    std::string result {};

    for(char c : word) {
        if(charCounter[tolower(c)] > 1)
            result += ')';
        else
            result += '(';
    }

    return result;
}