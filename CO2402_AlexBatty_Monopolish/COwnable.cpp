#include "COwnable.h"
#include "CPlayer.h"

COwnable::COwnable(istream& file)	: CSquare(file)
{
	file >> *this;
}

unique_ptr<CPlayer> COwnable::LandedOn(unique_ptr<CPlayer> player)
{
    player = CSquare::LandedOn(move(player));

    if (mOwningPlayerName == "Invalid")
    {
        cout << player->GetName() << " buys " << mName << " for \x9C" << mCost << endl;
        player->ownedPropertyIndex.push_back(mIndex);
        mOwningPlayerName = player->GetName();
        //player->PayBank(mCost);
    }

    return unique_ptr<CPlayer>();
}

istream& operator>>(istream& inputStream, COwnable& ownable)
{
    string secondWord;
    inputStream >> secondWord;
    ownable.mName = ownable.mName + " " + secondWord;
    return inputStream;
}

