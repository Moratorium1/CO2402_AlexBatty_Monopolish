#include "CSquare.h"
#include "CPlayer.h"

CSquare::CSquare(istream& file)
{
	file >> *this;
}

istream& operator>>(istream& inputStream, CSquare& square)
{
	inputStream >> square.mName;
	return inputStream;
}

CSquare::~CSquare()
{
}

unique_ptr<CPlayer> CSquare::LandedOn(unique_ptr<CPlayer> player)
{
	cout << player->GetName() << " landed on " << mName << endl;
	return player;
}

unique_ptr<CPlayer> CSquare::LandedOn(unique_ptr<CPlayer> player, unique_ptr<CBank>& bank)
{
	return player;
}

unique_ptr<CPlayer> CSquare::LandedOn(unique_ptr<CPlayer> player, unique_ptr<CBank>& bank, unique_ptr<CDie>& die, vector<unique_ptr<CPlayer>>& playerList)
{
	return player;
}

int CSquare::GetIndex()
{
	return mIndex;
}

void CSquare::SetIndex(const int index)
{
	mIndex = index;
}

void CSquare::SetType(const ESquareType type)
{
	mType = type;
}
