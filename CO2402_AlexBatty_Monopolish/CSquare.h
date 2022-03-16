#pragma once
#include <memory>
#include <iostream>

using namespace std;

enum class ESquareType : int
{
	Invalid,
	Property,
	Go,
	Station,
	Bonus,
	Penalty,
	Jail,
	GoToJail,
	FreeParking,
	Max
};

class CPlayer;

class CSquare
{
public:
	CSquare(istream& file);
	friend istream& operator >> (istream& inputStream, CSquare& square);

	virtual unique_ptr<CPlayer> LandedOn(unique_ptr<CPlayer> player);

protected:
	string mName = "Invalid";

	ESquareType mType = ESquareType::Invalid;

	int mColour = -1;

	int mCost = -1;

	bool mbIsMortgaged = false;
};

