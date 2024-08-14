#include "FindMissingLetter.h"

// Conditions of the task were following.

// You will always get an valid array. 
// And it will be always exactly one letter be missing.
// The length of the array will always be at least 2.
// The array will always contain letters in only one case.

char findMissingLetter(const std::vector<char>& chars)
{
    int arrSize { static_cast<int>(chars.size()) };

    for(int i = 0; i < arrSize; ++i)
    {
        char temp { chars[i] };

        if(chars[i + 1] != ++temp)
            return temp;
    }

    return ' ';
}