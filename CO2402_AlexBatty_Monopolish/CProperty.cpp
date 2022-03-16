#include "CProperty.h"

CProperty::CProperty(istream& file) : CSquare(file)
{
    file >> *this;
}

unique_ptr<CPlayer> CProperty::LandedOn(unique_ptr<CPlayer> player)
{
    player = CSquare::LandedOn(move(player));

    return unique_ptr<CPlayer>();
}

istream& operator>>(istream& inputStream, CProperty& property)
{
    inputStream >> property.mCost >> property.mRent >> property.mColour;
    return inputStream;
}