#include "ConsecutiveStrings.h"

std::string LongestConsec::longestConsec(const std::vector<std::string>& strArr, int k)
{
    int arrSize { static_cast<int>(strArr.size()) };

    if(arrSize == 0 || k > arrSize || k <= 0)
        return "";

    std::string longestConsecutive {};
    size_t maxSize {};

    for(int i = 0; i <= arrSize - k; ++i)
    {
        std::string consecStr {};
        for(int j = 0; j < k; ++j)
        {
            consecStr += strArr[i + j];
        }

        if(consecStr.size() > maxSize)
        {
            maxSize = consecStr.size();
            longestConsecutive = consecStr;
        }
    }

    return longestConsecutive;
}