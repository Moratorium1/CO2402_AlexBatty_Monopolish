#pragma once
#include "CSquare.h"

using namespace std;

class CBank;

unique_ptr<CSquare> CreateNewSquare(ESquareType squareType, istream& file, int index, unique_ptr<CBank>& bank);