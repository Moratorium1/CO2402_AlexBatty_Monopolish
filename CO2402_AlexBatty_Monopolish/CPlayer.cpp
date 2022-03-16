#include "CPlayer.h"

void CPlayer::MovePlayer(const int rolledValue)
{
	mSquareIndex += rolledValue;
}

string CPlayer::GetName()
{
	return mName;
}

CPlayer::CPlayer(istream& file)
{
	file >> *this;
}

istream& operator>>(istream& inputStream, CPlayer& player)
{
	inputStream >> player.mName;
	return inputStream;
}