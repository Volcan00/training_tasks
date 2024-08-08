#ifndef ROMANHELPER_H
#define ROMANHELPER_H

#include <string>

class RomanHelper
{
public:

    std::string to_roman(int num);

    unsigned int from_roman(const std::string& s);
};

#endif