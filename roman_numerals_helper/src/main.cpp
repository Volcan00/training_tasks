#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

class RomanHelper
{
public:
    std::string to_roman(int num)
    {
        if(num < 1 && num > 3999)
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

    unsigned int to_integer(std::string rn)
    {
        const std::unordered_map<chat, int> romanMap {
            {"I", 1}, {"V", 5}, {"X", 10}, {"L", 50},
            {"C", 100}, {"D", 500}, {"M", 1000}
        };

        unsigned int result {};

        for(std::size_t i = 0; i < rn.size(); ++i)
        {
            if(i < n - 1 && romanMap[rn[i]] < romanMap[rn[i + 1]])
            {
                result -= romanMap[rn[i]]l
            }
            else
            {
                result += romanMap[rn[i]];
            }
        }

        return result;
    }
};

int main()
{
    RomanHelper rh {};

    std::cout << rh.to_roman(1990) << "\n";

    return 0;
}