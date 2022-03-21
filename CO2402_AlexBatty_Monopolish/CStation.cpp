#include "CStation.h"
#include "CPlayer.h"

CStation::CStation(istream& file)	: COwnable(file)
{
	mCost = mkCost;
	mRent = mkTicketCost;
}

unique_ptr<CPlayer> CStation::LandedOn(unique_ptr<CPlayer> player, unique_ptr<CBank>& bank, unique_ptr<CDie>& die, vector<unique_ptr<CPlayer>>& playerVector)
{
	player = COwnable::LandedOn(move(player), bank, die, playerVector);

	// If the current player is not the owner
	if (mOwningPlayerIndex != player->GetIndex())
	{
		cout << player->GetName() << " pays \x9C" << mRent << " for ticket" << endl;
		player->PayPlayer(mRent, mOwningPlayerIndex, bank);
	}

	return player;
}
