#pragma once
#include "CSquare.h"
class CFreeParking :	public CSquare
{
public:
	CFreeParking(istream& file);
	friend istream& operator >> (istream& inputStream, CFreeParking& square);

	virtual unique_ptr<CPlayer> LandedOn(unique_ptr<CPlayer> player) override;
	
};

