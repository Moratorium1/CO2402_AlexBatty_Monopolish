// CO2402_AlexBatty_Monopolish.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#include <iostream>
#include "CMonopolish.h"
#include "CPlayer.h"
#include "CSquare.h"
#include "CBank.h"
#include "CDie.h"

using namespace std;

int main()
{
    {
        auto Game = make_unique<CMonopolish>(47);
    }
    _CrtDumpMemoryLeaks();
}
