#pragma once
#include "CSquare.h"

class CGo :	public CSquare
{
public:
	CGo(istream& file);

	virtual unique_ptr<CPlayer> LandedOn(unique_ptr<CPlayer> player);
	
private:
	const int mCollectAmount = 200;
};

