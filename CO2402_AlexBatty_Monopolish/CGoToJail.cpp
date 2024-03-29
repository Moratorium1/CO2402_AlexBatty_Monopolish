#include "CGoToJail.h"
#include "CPlayer.h"

CGoToJail::CGoToJail(istream& file, const int jailIndex)	:	CSquare(file)
{
	file >> *this;
	mJailIndex = jailIndex;
}

istream& operator>>(istream& inputStream, CGoToJail& goToJail)
{
	string secondWord, thirdWord;
	inputStream >> secondWord >> thirdWord;
	goToJail.mName = goToJail.mName + " " + secondWord + " " + thirdWord;
	return inputStream;
}

unique_ptr<CPlayer> CGoToJail::LandedOn(unique_ptr<CPlayer> player, unique_ptr<CBank>& bank, unique_ptr<CDie>& die, vector<unique_ptr<CPlayer>>& playerVector)
{
	player = CSquare::LandedOn(move(player));

	cout << player->GetName() << " goes to Jail" << endl;
	cout << player->GetName() << " pays \x9C" << mCost << endl;

	player->PayBank(mCost, bank);	// Player pays the bank the cost

	player->mSquareIndex = mJailIndex;	// Player squareIndex is set to the index of the jail square

	return player;
}


