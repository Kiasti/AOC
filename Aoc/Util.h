#pragma once
#include <string>
#include <vector>

namespace util
{
    namespace str
    {
        unsigned int countOccurance(const std::string& s, const char delimiter);
        [[nodiscard]] std::vector<int> explodeToNumbers(std::string&& s, const char delimiter);
        bool isNumber(const std::string& s);
    }
}