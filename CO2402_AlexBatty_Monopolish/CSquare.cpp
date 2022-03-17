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

unique_ptr<CPlayer> CSquare::LandedOn(unique_ptr<CPlayer> player)
{
	cout << player->GetName() << " landed on " << mName << endl;
	return player;
}

int CSquare::GetIndex()
{
	return mIndex;
}
