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
	if (ownedProperties.size() <= 0)
	{
		mbIsBankkrupt = true;
		return;
	}

	int index = 0;
	int indexToCheapest = -1;
	int cheapestCost = 0;
	string cheapestName = "Invalid";
	for (auto& property : ownedProperties)
	{
		if (property)
		{
			if ((property->mCost < cheapestCost || cheapestCost == 0) && property->mColour != -1)		// Checking for colour removes stations - Stations removed to match example output
			{
				// that is the index to the property on the squareList not the index of the property in the players ownedProperty Vector
				indexToCheapest = index;
				cheapestCost = property->mCost;
				cheapestName = property->mName;
			}
		}
		index++;
	}

	cout << mName << " mortgages " << cheapestName << " for \x9C" << cheapestCost << endl;

	PayedByBank(cheapestCost, bank);
	bank->mortgagedPropertyVector.push_back(move(ownedProperties[indexToCheapest]));
	mNumOfMortgagedProperties++;
	ownedProperties.shrink_to_fit();

	if (mMoney <= 0)
		MortgageTilAboveZero(bank);
}

void CPlayer::RepayMortgage(unique_ptr<CBank>& bank)
{
	int index = 0;
	int indexToCheapest = -1;
	int cheapestCost = 0;
	string cheapestName = "Invalid";
	for (auto& property : bank->mortgagedPropertyVector)
	{
		if (property)
		{
			if ((property->mCost < cheapestCost || cheapestCost == 0) && property->mPlayerIndex == mIndex)
			{
				indexToCheapest = index;
				cheapestCost = property->mCost;
				cheapestName = property->mName;
			}
		}
		index++;
	}

	if (cheapestCost < mMoney)
	{
		cout << mName << " repays mortgage on " << cheapestName << " for \x9C" << cheapestCost << endl;

		PayBank(cheapestCost, bank);
		ownedProperties.push_back(move(bank->mortgagedPropertyVector[indexToCheapest]));
		bank->mortgagedPropertyVector.shrink_to_fit();
		mNumOfMortgagedProperties--;
	}
}
