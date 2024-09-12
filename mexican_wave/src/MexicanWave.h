#ifndef MEXICAN_WAVE_H
#define MEXICAN_WAVE_H

#include <string>
#include <vector>

std::vector<std::string> wave(std::string y)
{
    std::vector<std::string> waveArr {};

    for(size_t i = 0; i < y.size(); ++i)
    {
        std::string yCopy { y };

        if(isalpha(yCopy[i]))
        {
            yCopy[i] = toupper(yCopy[i]);
            waveArr.push_back(yCopy);
        }
    }

    return waveArr;
}

#endif