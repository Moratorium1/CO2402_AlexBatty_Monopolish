// CO2402_AlexBatty_Monopolish.cpp : This file contains the 'main' function. Program execution begins and ends there.
// G20907182

#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#include <iostream>
#include "CMonopolish.h"

using namespace std;

int main()
{
    {
        auto game = make_unique<CMonopolish>(47);   // Create the game with the given seed to be passed to the die
    }
    _CrtDumpMemoryLeaks();
}
