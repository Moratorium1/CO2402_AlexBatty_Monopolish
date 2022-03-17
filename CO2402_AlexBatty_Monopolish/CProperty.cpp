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

unique_ptr<CPlayer> CProperty::LandedOn(unique_ptr<CPlayer> player)
{
    player = CSquare::LandedOn(move(player));

    if (mOwningPlayerName != player->GetName() && !mbIsMortgaged)
    {
        // Check if the owning player has all the properties of this colour - get owning player using a get player of name function
        
    }

    return unique_ptr<CPlayer>();
}