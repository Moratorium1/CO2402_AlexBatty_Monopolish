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

unique_ptr<CPlayer> CProperty::LandedOn(unique_ptr<CPlayer> player, unique_ptr<CBank>& bank, unique_ptr<CDie>& die)
{
    player = COwnable::LandedOn(move(player), bank, die);

    if (mOwningPlayerIndex != player->GetIndex() && !mbIsMortgaged)
    {
        int rentDue = mRent;
        // Check if the owning player has all the properties of this colour - get owning player using a get player of name function
        

        cout << player->GetName() << " pays \x9C" << rentDue << endl;
        player->PayPlayer(rentDue, mOwningPlayerIndex, bank);
    }

    return player;
}