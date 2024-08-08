#include "RomanHelper.h"
#include <vector>
#include <unordered_map>

// Function to convert unsigned integer to Roman numeral
std::string RomanHelper::to_roman(int num)
{
    if(num < 1 || num > 3999)
        return "Entered number is out of range!\n";

    const std::vector<std::pair<int, std::string>> romanMap {
        {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"},
        {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"},
        {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}
    };

    std::string result {};

    for(const auto& pair : romanMap)
    {
        while(num >= pair.first)
        {
            result += pair.second;
            num -= pair.first;
        }
    }

    return result;
}

// Function to convert Roman numeral to unsigned integer
unsigned int RomanHelper::from_roman(const std::string& s)
{
    std::unordered_map<char, unsigned int> romanMap = {
            {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50},
            {'C', 100}, {'D', 500}, {'M', 1000}
        };

        unsigned int result = 0;
        unsigned int n = s.length();

        for (unsigned int i = 0; i < n; ++i) {
            if (i < n - 1 && romanMap[s[i]] < romanMap[s[i + 1]]) {
                result -= romanMap[s[i]];
            } else {
                result += romanMap[s[i]];
            }
        }

        return result;
}