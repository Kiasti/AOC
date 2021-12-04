#include "day1.h"
#include <fstream>

bool day1::submarine::loadDepths(std::string&& fileName)
{
    if (depthList.empty())
    {
        if (std::ifstream ifs(fileName, std::ios::in | std::ios::binary); ifs.good())
        {
            depthList.reserve(1000);
            long long depth = 0;
            while (ifs >> depth)
                depthList.emplace_back(depth);
            ifs.close();
            return true;
        }
    }
    return false;
}

long long day1::submarine::amountOfIncreases() const
{
    if (!depthList.empty())
    {
        long long increase = 0;
        auto baseVal = depthList[0];
        for (size_t i = 1; i < depthList.size(); ++i)
        {
            if (baseVal < depthList[i])
                increase++;
            baseVal = depthList[i];
        }
        return increase;
    }
    return 0;

}

long long day1::submarine::amtOfIncreasesBy3() const
{
    if (!depthList.empty() && depthList.size() >= 3)
    {
        long long increase = 0;
        unsigned long long base = depthList[0] + depthList[1] + depthList[2];
        for (unsigned long long i = 1; i < depthList.size() && i + 2 < depthList.size(); ++i)
        {
            const auto second = depthList[i] + depthList[i + 1] + depthList[i + 2];
            if (second > base)
                increase++;
            base = second;
        }
        return increase;
    }
    return 0;
}