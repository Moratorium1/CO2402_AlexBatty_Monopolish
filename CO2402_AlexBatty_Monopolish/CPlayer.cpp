#include "CPlayer.h"
#include  "CBank.h"
#include <algorithm>

CPlayer::CPlayer(istream& file, unique_ptr<CBank>& bank, const int index)
{
	file >> *this;

	mIndex = index;
	PayedByBank(mkStartingMoney, bank);
}

CPlayer::~CPlayer()
{
	ownedProperties.clear();
	ownedProperties.shrink_to_fit();
}

istream& operator>>(istream& inputStream, CPlayer& player)
{
	inputStream >> player.mName;
	return inputStream;
}

void CPlayer::MovePlayer(const int rolledValue)
{
	mSquareIndex += rolledValue;
}

void CPlayer::EndTurn(unique_ptr<CBank>& bank)
{
	if (mMoney < 0)
	{
		MortgageTilAboveZero(bank);
	}
	else if (mNumOfMortgagedProperties > 0)
	{
		RepayMortgage(bank);
	}

	cout << mName << " has \x9C" << mMoney << endl;
}

string CPlayer::GetName()
{
	return mName;
}

int CPlayer::GetIndex()
{
	return mIndex;
}

int CPlayer::GetMoney()
{
	return mMoney;
}

int CPlayer::GetNumOfMortgagedProperties()
{
	return mNumOfMortgagedProperties;
}

void CPlayer::PayBank(const int amount, unique_ptr<CBank>& bank)
{
	mMoney -= amount;
	bank->mMoney += amount;
}

void CPlayer::PayedByBank(const int amount, unique_ptr<CBank>& bank)
{
	if (bank->mMoney >= amount)		// Check the bank has enough money to pay amount
	{
		mMoney += amount;			// Remove amount from player
		bank->mMoney -= amount;		// Add amount to bank
	}
}

void CPlayer::ClaimAccruedRent(unique_ptr<CBank>& bank)
{
	int amount = bank->amountForPlayer[mIndex];		// Get accrued amount
	bank->amountForPlayer[mIndex] = 0;				// Clear accrued amount

	mMoney += amount;								// Pay player amount
	bank->mMoney -= amount;							// Take amount from bank
}

void CPlayer::PayPlayer(const int amount, const int otherPlayerIndex, unique_ptr<CBank>& bank)
{
	mMoney -= amount;										// Remove amount from player
	bank->mMoney += amount;									// Add amount to bank
	bank->amountForPlayer[otherPlayerIndex] += amount;		// Add amount to amount to be payed to player at the start of their turn
}

void CPlayer::MortgageTilAboveZero(unique_ptr<CBank>& bank)
{
	// Check if all the elements of the vector are empty if so set mIsBankrupt to true and stop the recursion of the function 
	if (ownedProperties.empty())
	{
		mbIsBankkrupt = true;
		return;
	}

	int index = 0;								// the number of times the for loop has looped - the index of the ownedProperties vector that the current property is in
	int indexToCheapest = -1;					// the index the cheapest property is stored in
	int cheapestCost = 0;						// the lowest cost of a property so far
	string cheapestName = "Invalid";
	for (auto& property : ownedProperties)
	{
		if (property)	// Required as moving the pointer to the banks mortgagedPropertyVector leaves empty elements 
		{
			if ((property->mCost < cheapestCost || cheapestCost == 0) && property->mColour != -1)		// Checking for colour removes stations - Stations removed to match example output
			{
				indexToCheapest = index;
				cheapestCost = property->mCost;
				cheapestName = property->mName;
			}
		}
		index++;
	}

	cout << mName << " mortgages " << cheapestName << " for \x9C" << cheapestCost << endl;

	PayedByBank(cheapestCost, bank);													// Player receives the cost of the property from the bank
	bank->mortgagedPropertyVector.push_back(move(ownedProperties[indexToCheapest]));	// The unique_ptr is moved to the banks vector
	mNumOfMortgagedProperties++;														// The variable the player has to track its total number of mortgaged properties is incremented
	ownedProperties.shrink_to_fit();

	if (mMoney <= 0)					// If the players money is still below zero call this function again
		MortgageTilAboveZero(bank);
}

void CPlayer::RepayMortgage(unique_ptr<CBank>& bank)
{
	int index = 0;				// the index of the mortgagedPropertyVector that is being checked
	int indexToCheapest = -1;	// stores the index of the mortgagedPropertyVector that has the property with the lowest cost
	int cheapestCost = 0;		// The cost of the cheapest property found so far
	string cheapestName = "Invalid";
	for (auto& property : bank->mortgagedPropertyVector)
	{
		if (property)
		{
			// if the property is the cheapest and belongs to this player store it as the new cheapest
			if ((property->mCost < cheapestCost || cheapestCost == 0) && property->mPlayerIndex == mIndex)
			{
				indexToCheapest = index;
				cheapestCost = property->mCost;
				cheapestName = property->mName;
			}
		}
		index++;
	}

	// If the player has more money than the cost of the cheapest property mortgaged that they own then buy it back
	if (cheapestCost < mMoney)
	{
		cout << mName << " repays mortgage on " << cheapestName << " for \x9C" << cheapestCost << endl;

		PayBank(cheapestCost, bank);														// Pay the bank the cost
		ownedProperties.push_back(move(bank->mortgagedPropertyVector[indexToCheapest]));	// move the property back to the player's ownedProperty vector
		bank->mortgagedPropertyVector.shrink_to_fit();
		mNumOfMortgagedProperties--;														// Decrease the number of properties the player has mortgaged
	}
}
