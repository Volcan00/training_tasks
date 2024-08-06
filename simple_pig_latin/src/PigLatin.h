#ifndef PIGLATIN_H
#define PIGLATIN_H

#include <string>
#include <vector>

std::vector<std::string> splitStringWithPunctuation(const std::string& str);

std::string transformWord(const std::string& word);

std::string pig_it(std::string str);

#endif