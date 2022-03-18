#include "COwnable.h"
#include "CPlayer.h"
#include "CBank.h"

COwnable::COwnable(istream& file)	: CSquare(file)
{
	file >> *this;
}

istream& operator>>(istream& inputStream, COwnable& ownable)
{
    string secondWord;
    inputStream >> secondWord;
    ownable.mName = ownable.mName + " " + secondWord;
    return inputStream;
}

unique_ptr<CPlayer> COwnable::LandedOn(unique_ptr<CPlayer> player, unique_ptr<CBank>& bank, unique_ptr<CDie>& die, vector<unique_ptr<CPlayer>>& playerList)
{
    player = CSquare::LandedOn(move(player));

    if (mOwningPlayerIndex == -1)
    {
        cout << player->GetName() << " buys " << mName << " for \x9C" << mCost << endl;
        player->ownedProperties.push_back(make_unique<SPropertyDetails>(mIndex, mCost, mColour));
        mOwningPlayerIndex = player->GetIndex();
        player->PayBank(mCost, bank);
    }

    return player;
}


