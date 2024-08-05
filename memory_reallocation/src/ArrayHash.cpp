#include "ArrayHash.h"
#include <functional>

std::size_t ArrayHash::operator()(const std::array<unsigned int, 16>& arr) const
{
    std::size_t hash {};
    for(unsigned int num : arr)
    {
        hash ^= std::hash<unsigned int>{}(num) + 0x9e3779b9 + (hash << 6) + (hash >> 2); 
    }

    return hash;
}
