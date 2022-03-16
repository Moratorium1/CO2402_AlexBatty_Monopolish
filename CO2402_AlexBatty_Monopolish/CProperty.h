#pragma once
#include "CSquare.h"
#include "CPlayer.h"

class CProperty :	public CSquare
{
public:
	CProperty(istream& file);

	friend istream& operator >> (istream& inputStream, CProperty& property);
	virtual unique_ptr<CPlayer> LandedOn(unique_ptr<CPlayer> player) override;

protected:
	int mRent = -1;
};

