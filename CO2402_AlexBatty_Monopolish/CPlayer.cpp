#include "CPlayer.h"
#include  "CBank.h"

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
