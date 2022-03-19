#pragma once
#include "CPlayer.h"
#include <vector>

using namespace std;

class CBank
{
public:
	CBank();
	~CBank();

	int mMoney = -1;

	/* Holds accrued rent payments between a players turn to be payed to them at the start of thier turn */
	vector<int>  amountForPlayer;

	/* Holds the details of all mortgaged properties along with the index to the player who mortgaged it */
	vector<unique_ptr<SPropertyDetails>> mortgagedPropertyVector;

	vector<int> numberOfColourVector = {0, 0, 0, 0, 0, 0, 0, 0};

private:
	const int mkStartingMoney = 20000;
};

