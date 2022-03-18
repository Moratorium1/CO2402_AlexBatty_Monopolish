#include "CProperty.h"
#include "CPlayer.h"

CProperty::CProperty(istream& file) : COwnable(file)
{
    file >> *this;
}

istream& operator>>(istream& inputStream, CProperty& property)
{
    inputStream >> property.mCost >> property.mRent >> property.mColour;
    return inputStream;
}

unique_ptr<CPlayer> CProperty::LandedOn(unique_ptr<CPlayer> player, unique_ptr<CBank>& bank, unique_ptr<CDie>& die, vector<unique_ptr<CPlayer>>& playerList)
{
    player = COwnable::LandedOn(move(player), bank, die, playerList);

    if (mOwningPlayerIndex != player->GetIndex() && !mbIsMortgaged)
    {
        int rentDue = mRent;
        //playerList[mOwningPlayerIndex]->ownedProperties[]

        //


        cout << player->GetName() << " pays \x9C" << rentDue << endl;
        player->PayPlayer(rentDue, mOwningPlayerIndex, bank);
    }

    return player;
}