#pragma once
#include <iostream>
#include <memory>
#include <vector>

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
class CBank;
class CDie;

class CSquare
{
public:
	CSquare(istream& file);
	friend istream& operator >> (istream& inputStream, CSquare& square);

	virtual ~CSquare();

	virtual unique_ptr<CPlayer> LandedOn(unique_ptr<CPlayer> player);
	virtual unique_ptr<CPlayer> LandedOn(unique_ptr<CPlayer> player, unique_ptr<CBank>& bank);
	virtual unique_ptr<CPlayer> LandedOn(unique_ptr<CPlayer> player, unique_ptr<CBank>& bank, unique_ptr<CDie>& die, vector<unique_ptr<CPlayer>>& playerList);

	int GetIndex();
	void SetIndex(const int index);

	void SetType(const ESquareType type);

	string mName = "Invalid";

protected:
	/* The index of the vector to get this square */
	int mIndex = -1;

	ESquareType mType = ESquareType::Invalid;

	int mColour = -1;

	int mCost = -1;

	bool mbIsMortgaged = false;
};

