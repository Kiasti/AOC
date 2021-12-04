#pragma once
#include <string>

namespace day2
{
    enum class posType : unsigned char { down, up, forward, backward, null };
    inline posType getPosType(const std::string& str)
    {
        if (str == "forward") return posType::forward;
        if (str == "up") return posType::up;
        if (str == "down") return posType::down;
        if (str == "backward") return posType::backward;
        return posType::null;
    }

    struct pos
    {
        long long x;
        long long y;
        long long aim;
    	
        pos() : x(0), y(0), aim(0) { }
        [[nodiscard]] bool isEmpty() const { return x == 0 && y == 0 && aim == 0; }
        void alterPos(long long alter, std::string&& posType);
        void alterPos2(long long alter, std::string&& posType);
    };

	class submarine
    {
        bool part2 = false;
        pos currentPos{};
    
        public:
            [[nodiscard]] bool isPart2() const { return part2; }
            void setPart2(const bool b) { part2 = b; }
            bool loadPositionalInputs(std::string&& fileName);
            pos& getPosition() { return currentPos; }
	};
 }


