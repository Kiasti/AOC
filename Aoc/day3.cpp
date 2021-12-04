#include "day3.h"
#include <fstream>
#include <iostream>


long day3::diagnostics::getPowerConsumption() const
{
    if (data.empty())
        return 0;

    long gamma = 0;
    long epsilon = 0;
    int i = 11;
    do
    {
        unsigned long zero = 0;
        unsigned long one = 0;
        for (const auto v : data)
        {
            if ((v & (1 << i)) >> i)
                ++one;
            else
                ++zero;
        }
        gamma |= zero > one ? 0 << i : 1 << i;
        epsilon |= zero > one ? 1 << i : 0 << i;
        --i;
    } while (i > -1);
    return gamma * epsilon;
}


long day3::diagnostics::getLifeSupportRating() const
{
    if (data.empty())
        return 0; 

    std::vector<long> o2List = data;
    std::vector<long> co2List = data;
    int i = 11;
    do
    {
        std::vector<long> tempList1;
        std::vector<long> tempList2;
        tempList1.reserve(o2List.size());
        tempList2.reserve(o2List.size());

        if (o2List.size() != 1)
        {
            for (auto& v : o2List)
            {
                if ((v & (1 << i)) >> i)
                    tempList1.emplace_back(v);
                else
                    tempList2.emplace_back(v);
            }
            o2List = tempList1.size() >= tempList2.size() ? tempList1 : tempList2;

            tempList1.clear();
            tempList2.clear();
        }

        if (co2List.size() != 1)
        {
            for (auto& v : co2List)
            {
                if ((v & (1 << i)) >> i)
                    tempList1.emplace_back(v);
                else
                    tempList2.emplace_back(v);
            }
            co2List = tempList2.size() <= tempList1.size() ? tempList2 : tempList1;
        	
            tempList1.clear();
            tempList2.clear();
        }
        --i;
    } while (i > -1);
    return o2List[0] * co2List[0];
}

bool day3::diagnostics::loadDiagnosticReport(std::string&& fileName)
{
    if (std::ifstream ifs(fileName, std::ios::in | std::ios::binary); ifs.good())
    {
        std::vector<std::string> temp;
        temp.reserve(1000);

        std::string val;
        while (ifs >> val)
            temp.emplace_back(val);
        ifs.close();

        data.reserve(data.size());
        for (auto& str : temp)
            data.emplace_back(std::stoi(str, nullptr, 2));
        temp.clear();
    	
        return true;
    }
    return false;
}

