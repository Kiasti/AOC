#pragma once
#include <vector>
#include <string>

namespace day4
{
    struct bingoCard
    {
        int arr[5][5];
        bool arr2[5][5]{ {false, false, false, false, false}, {false, false, false, false, false}, {false, false, false, false, false}, {false, false, false, false, false}, {false, false, false, false, false} };
        bool hasWon = false;

        bool isWin();
        int sumAllUnmarked();
        void setNumber(int num);
    };

	class kickSquidButt
	{
        std::vector<int> numbersToCall;
		std::vector<bingoCard> data;

        bool letSquidWin = false;

    public:
        [[nodiscard]] bool isSquidWin() const { return letSquidWin; }
        void setSquidWin(const bool b) { letSquidWin = b; }
        [[nodiscard]] bool loadCardsAndCalls(std::string&& fileName);
        void playGame();
	};
}
