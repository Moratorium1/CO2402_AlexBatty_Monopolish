#pragma once
#include "CSquare.h"

class CGoToJail :	public CSquare
{
public:
	CGoToJail(istream& file, const int jailIndex);
	friend istream& operator >> (istream& inputStream, CGoToJail& goToJail);

	virtual unique_ptr<CPlayer> LandedOn(unique_ptr<CPlayer> player, unique_ptr<CBank>& bank, unique_ptr<CDie>& die) override;

private:
	int mCost = 50;

	int mJailIndex = -1;
};

