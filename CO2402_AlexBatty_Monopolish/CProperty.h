#pragma once
#include "COwnable.h"

class CProperty :	public COwnable
{
public:
	CProperty(istream& file);
	friend istream& operator >> (istream& inputStream, CProperty& property);

	virtual unique_ptr<CPlayer> LandedOn(unique_ptr<CPlayer> player, unique_ptr<CBank>& bank, unique_ptr<CDie>& die, vector<unique_ptr<CPlayer>>& playerList) override;
};

