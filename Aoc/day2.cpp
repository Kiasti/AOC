#include "day2.h"
#include <fstream>

void day2::pos::alterPos(const long long alter, std::string&& posType)
{
    switch (getPosType(posType))
    {
        case posType::down: y += alter; break;
        case posType::up: y -= alter; break;
        case posType::forward: x += alter; break;
        case posType::backward: x -= alter; break;
        case posType::null: break;
    }
}

void day2::pos::alterPos2(const long long alter, std::string&& posType)
{
    switch (getPosType(posType))
    {
        case posType::down: aim += alter; break;
        case posType::up: aim -= alter; break;
        case posType::forward: x += alter; y += aim * alter; break;
        case posType::backward: x -= alter; y -= aim * alter; break;
		case posType::null: break;
    }
}

bool day2::submarine::loadPositionalInputs(std::string&& fileName)
{
    if (currentPos.isEmpty())
    {
        if (std::ifstream ifs(fileName, std::ios::in | std::ios::binary); ifs.good())
        {
            std::string type;
            long long alteration = 0;
            while (ifs >> type >> alteration)
                if (part2)
                    currentPos.alterPos2(alteration, std::move(type));
                else
                    currentPos.alterPos(alteration, std::move(type));
            return true;
        }
    }
    return false;
}

