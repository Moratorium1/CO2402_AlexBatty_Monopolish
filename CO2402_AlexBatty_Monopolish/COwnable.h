#pragma once
#include "CSquare.h"

class CBank;

class COwnable :	public CSquare
{
public:
	COwnable(istream& file);
	friend istream& operator >> (istream& inputStream, COwnable& square);

	virtual unique_ptr<CPlayer> LandedOn(unique_ptr<CPlayer> player, unique_ptr<CBank>& bank, unique_ptr<CDie>& die, vector<unique_ptr<CPlayer>>& playerList) override;

protected:
	int mRent = 0;

	bool mbIsOwned = false;

	int mOwningPlayerIndex = -1;
};

