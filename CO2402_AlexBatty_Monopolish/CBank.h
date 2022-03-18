#pragma once
#include <vector>

using namespace std;

class CBank
{
public:
	CBank();

	int mMoney = -1;

	/* Holds accrued rent payments between a players turn to be payed to them at the start of thier turn */
	vector<int>  amountForPlayer;

private:
	const int mkStartingMoney = 20000;
};

