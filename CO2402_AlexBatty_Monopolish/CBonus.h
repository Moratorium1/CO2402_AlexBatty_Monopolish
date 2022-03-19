#pragma once
#include "CEvent.h"

class CBonus :	public CEvent
{
public:
	CBonus(istream& file);
	~CBonus();

	virtual unique_ptr<CPlayer> LandedOn(unique_ptr<CPlayer> player, unique_ptr<CBank>& bank, unique_ptr<CDie>& die, vector<unique_ptr<CPlayer>>& playerVector) override;
};

