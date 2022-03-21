#include "CProperty.h"
#include "CBank.h"
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

unique_ptr<CPlayer> CProperty::LandedOn(unique_ptr<CPlayer> player, unique_ptr<CBank>& bank, unique_ptr<CDie>& die, vector<unique_ptr<CPlayer>>& playerVector)
{
    player = COwnable::LandedOn(move(player), bank, die, playerVector);

    if (mOwningPlayerIndex != player->GetIndex())
    {
        // Check if the index for the property appears in the banks mortgaged property vector - if so the property is mortgaged and no rent is to be paid
        bool bIsMortgaged = false;
        for (auto& property : bank->mortgagedPropertyVector)
        {
            if (property)
            {
                if (property->mIndex == mIndex)
                {
                    mbIsMortgaged = true;
                }
            }
        }

        // If the property is not mortgaged
        if (!bIsMortgaged)
        {
            int rentDue = mRent;

            // Check if the owning player owns all the properties of the colour
            int totalOfColour = bank->numberOfColourVector[mColour];
            int ownedOfColour = 0;
            for (auto& property : playerVector[mOwningPlayerIndex]->ownedProperties)
            {
                if (property)
                {
                    if (property->mColour == mColour)
                    {
                        ownedOfColour++;
                    }
                }
            }

            // Double the rent if the player does own all of colour
            if (ownedOfColour == totalOfColour)
            {
                rentDue += rentDue;
            }

            cout << player->GetName() << " pays \x9C" << rentDue << " to " << playerVector[mOwningPlayerIndex]->GetName() << endl;
            player->PayPlayer(rentDue, mOwningPlayerIndex, bank);
        }
    }

    return player;
}