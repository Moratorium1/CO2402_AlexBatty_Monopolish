#pragma once
#include "CSquare.h"

class COwnable :	public CSquare
{
public:
	COwnable(istream& file);
	friend istream& operator >> (istream& inputStream, CSquare& square);

	virtual unique_ptr<CPlayer> LandedOn(unique_ptr<CPlayer> player);

protected:
	int mRent = 0;

	bool mbIsOwned = false;

	string mOwningPlayerName = "Invalid";
};

