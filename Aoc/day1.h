#pragma once
#include <vector>
#include <string>

namespace day1
{
	class submarine
	{
		std::vector<unsigned long long> depthList;

        public:
            [[nodiscard]] bool loadDepths(std::string&& fileName);
            [[nodiscard]] long long amountOfIncreases() const;
            [[nodiscard]] long long amtOfIncreasesBy3() const;
	};
}
