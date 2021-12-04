#include "day4.h"
#include "Util.h"
#include <fstream>
#include <iostream>

bool day4::bingoCard::isWinningCard()
{
    if (hasWon)
        return false;

    for (int i = 0; i < 5; ++i)
    {
        if (arr2[i][0] && arr2[i][1] && arr2[i][2] && arr2[i][3] && arr2[i][4])
            hasWon = true;
    }
    if (hasWon)
        return true;

    for (int j = 0; j < 5; ++j)
    {
        if (arr2[0][j] && arr2[1][j] && arr2[2][j] && arr2[3][j] && arr2[4][j])
            hasWon = true;
    }
    return hasWon;
}

int day4::bingoCard::sumAllUnmarked()
{
    int start = 0;
    for (int i = 0; i < 5; ++i)
    {
        for (int j = 0; j < 5; ++j)
        {
            if (!arr2[i][j])
                start += arr[i][j];
        }
    }
    return start;
}

void day4::bingoCard::setNumber(const int num)
{
    for (int i = 0; i < 5; ++i)
    {
        for (int j = 0; j < 5; ++j)
        {
            if (arr[i][j] == num)
                arr2[i][j] = true;
        }
    }
}

bool day4::kickSquidButt::loadCardsAndCalls(std::string&& fileName)
{
    if (std::ifstream ifs(fileName, std::ios::in | std::ios::binary); ifs.good())
    {
        std::string numbers;
        ifs >> numbers;

        numbersToCall = util::str::explodeToNumbers(std::move(numbers), ',');

        data.reserve(100);
        bingoCard bc{};
        while (!ifs.eof())
        {
            for (auto& i : bc.arr)
            {
                for (int& j : i)
	                ifs >> j;
            }
            data.emplace_back(bc);
        }
        ifs.close();
        return true;
    }
    return false;
}

void day4::kickSquidButt::playGame()
{
    bool gameWon = false;
    auto multiply = 0;
    for (const auto num : numbersToCall)
    {
        for (auto iter = data.begin(); iter != data.end(); ++iter)
        {
            iter->setNumber(num);
            if (iter->isWinningCard())
            {
                gameWon = true;
                multiply = iter->sumAllUnmarked() * num;

                if (gameWon && !letSquidWin)
                    break;
            }
        }
        if (gameWon && !letSquidWin)
            break;
    }
    std::cout << "The winning number: " << multiply << std::endl;
}