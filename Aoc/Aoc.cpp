#include <iostream>
#include <fstream>
#include <string>
#include "Util.h"
#include "day1.h"
#include "day2.h"
#include "day3.h"
#include "day4.h"

void runDay1()
{
    std::cout << "Do you want increase by subset of 3? 0 = false, 1 = true" << std::endl;
    bool option = false;
    std::cin >> option;

    if (day1::submarine sub; sub.loadDepths("aoc1.txt"))
    {
        const long long increase = option ? sub.amtOfIncreasesBy3() : sub.amountOfIncreases();
        std::cout << "The incrase: " << increase << std::endl;
    }
    else
        std::cout << "file not found" << std::endl;
}

void runDay2()
{
    std::cout << "Do you want to use aim mechanics? 0 = false, 1 = true" << std::endl;
    bool option = false;
    std::cin >> option;

    day2::submarine sub;
    sub.setPart2(option);
    if (sub.loadPositionalInputs("aoc2.txt"))
    {
        day2::pos& p = sub.getPosition();
        const long long value = p.x * p.y;
        std::cout << "The value: " << value << std::endl;
    }
    else
        std::cout << "file not found" << std::endl;
}

void runDay3()
{
    std::cout << "Do you want Power consumption or LifeSupportRating? 0 or 1? jk Day 2 wasnt fixed up yet." << std::endl;
    //bool option = false;
    //std::cin >> option;

    if (day3::diagnostics dm; dm.loadDiagnosticReport("aoc3.txt"))
    {
        //const long value = option ? dm.getLifeSupportRating() : dm.getPowerConsumption();
		const long value = dm.getLifeSupportRating();
        std::cout << "The value: " << value << std::endl;
    }
    else
        std::cout << "file not found" << std::endl;
}

void runDay4()
{
    bool letSquidWin = false;
    std::cout << "do you want squid to win? 0 = false, 1 = true" << std::endl;
    std::cin >> letSquidWin;

    if (day4::kickSquidButt kick; kick.loadCardsAndCalls("aoc4.txt"))
    {
        kick.setSquidWin(letSquidWin);
        kick.playGame();
    }
    else
        std::cout << "file not found" << std::endl;
}

int main()
{
    std::cout << "Which day would you like to sequence? Just press enter with nothing to close." << std::endl;

    std::string cmd;
    while (std::getline(std::cin, cmd))
    {
        std::cin.clear();
        if (cmd.empty())
            return 0;

        switch (const int day = util::str::isNumber(cmd) ? std::stoi(cmd) : 99; day)
        {
            case 1: runDay1(); break;
            case 2: runDay2(); break;
            case 3: runDay3(); break;
            case 4: runDay4(); break;
            case 0: std::cout << "Arrays do start as 0, but days don't" << std::endl; break;
            default: 
                std::cout << "Invalid day" << std::endl; 
                std::cout << "Which day would you like to sequence? Just press enter with nothing to close." << std::endl;
                break;
        }
    }
    return 0;
}




