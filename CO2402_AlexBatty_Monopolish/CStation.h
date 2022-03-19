#pragma once
#include "COwnable.h"
class CStation :	public COwnable
{
public:
	CStation(istream& file);

	virtual unique_ptr<CPlayer> LandedOn(unique_ptr<CPlayer> player, unique_ptr<CBank>& bank, unique_ptr<CDie>& die, vector<unique_ptr<CPlayer>>& playerVector) override;

protected:
	const int mkCost = 200;

	const int mkTicketCost = 10;
};

