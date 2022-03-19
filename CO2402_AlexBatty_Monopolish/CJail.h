#pragma once
#include "CSquare.h"
class CJail :	public CSquare
{
public:
	CJail(istream& file);

	virtual unique_ptr<CPlayer> LandedOn(unique_ptr<CPlayer> player, unique_ptr<CBank>& bank, unique_ptr<CDie>& die, vector<unique_ptr<CPlayer>>& playerVector) override;
};

