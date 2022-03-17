#pragma once
#include "CSquare.h"
#include <fstream>
#include <vector>
#include <string>

using namespace std;

class CEvent :	public CSquare
{
public:
	CEvent(istream& file);

	virtual unique_ptr<CPlayer> LandedOn(unique_ptr<CPlayer> player) override = 0;

protected:
	vector<int>	eventValue{ 20, 50, 100, 150, 200, 300 };
};

