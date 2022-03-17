#pragma once
#include "CEvent.h"

class CBonus :	public CEvent
{
	CBonus(istream& file);

	virtual unique_ptr<CPlayer> LandedOn(unique_ptr<CPlayer> player) override;
};

