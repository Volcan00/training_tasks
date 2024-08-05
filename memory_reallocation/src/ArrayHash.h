#ifndef ARRAYHASH_H
#define ARRAYHASH_H

#include <array>
#include <cstddef>

struct ArrayHash {
    std::size_t operator()(const std::array<unsigned int, 16>& arr) const;
};

#endif