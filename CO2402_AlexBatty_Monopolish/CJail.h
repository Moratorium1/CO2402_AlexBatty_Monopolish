#pragma once
#include "CSquare.h"
class CJail :	public CSquare
{
public:
	CJail(istream& file);

	virtual unique_ptr<CPlayer> LandedOn(unique_ptr<CPlayer> player) override;
};

