#pragma once
#include <string>
#include <vector>

namespace day3
{
	class diagnostics
	{
        std::vector<long> data;
        bool part2 = false;
	
		public:
            [[nodiscard]] bool isPart2() const { return part2; }
            void setPart2(const bool b) { part2 = b; }

			[[nodiscard]] long getPowerConsumption() const;
            [[nodiscard]] long getLifeSupportRating() const;
            bool loadDiagnosticReport(std::string&& fileName);
		
	};
}
