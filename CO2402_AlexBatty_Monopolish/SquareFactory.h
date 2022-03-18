#pragma once
#include "CSquare.h"

using namespace std;

unique_ptr<CSquare> CreateNewSquare(ESquareType squareType, istream& file, int index);