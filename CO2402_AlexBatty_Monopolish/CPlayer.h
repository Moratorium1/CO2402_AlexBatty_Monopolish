#pragma once
#include <string>
#include <iostream>
#include <vector>
using namespace std;

class CBank;

struct SPropertyDetails
{
	SPropertyDetails(string name, int playerIndex, int index, int cost, int colour)
	{
		mName	= name;
		mPlayerIndex = playerIndex;
		mIndex	= index;
		mCost	= cost;
		mColour = colour;
	}

	int mPlayerIndex = -1;

	string mName = "Invalid";
	int mIndex	= -1;
	int mCost	= -1;
	int mColour = -1;
};

class CPlayer
{
public:
	CPlayer(istream& file, unique_ptr<CBank>& bank, const int index);
	friend istream& operator >> (istream& inputStream, CPlayer& player);

	/* Clears ownedProperties and shrinks to fit to clear memory leaks */
	~CPlayer();

	/* The index of the SquareList Element that the player is currently on */
	int mSquareIndex = 0;

	/* True if the player ends a round with less than 0 money - at which point the player is excluded from the game */
	bool mbIsBankkrupt = false;

	/* Changes the mSquareIndex of the player to where the player has landed following the dice roll */
	void MovePlayer(const int rolledValue);

	/* Performs turn end checks - Is player bankrupt? should they mortgage or rebuy properties? */
	void EndTurn(unique_ptr<CBank>& bank);

	/* A vector that holds the index of the players owned properties */
	vector<unique_ptr<SPropertyDetails>> ownedProperties;

	/* Returns player name */
	string GetName();

	/* Returns the players index - index of the player in the playerVector */
	int GetIndex();

	/* Returns the amount of money the player has */
	int GetMoney();

	/* Returns the players number of mortgaged properties */
	int GetNumOfMortgagedProperties();

	/* Send money to the bank */
	void PayBank(const int amount, unique_ptr<CBank>& bank);

	/* Recieve money from the bank - if the bank has enough money to pay it */
	void PayedByBank(const int amount, unique_ptr<CBank>& bank);

	/* Claim any rent payed to the player durign other players turns from the bank */
	void ClaimAccruedRent(unique_ptr<CBank>& bank);

	/* Moves Properties from the players ownedPropertyVector to the banks mortgagedPropertyVector to reclaim the cost of the property */
	void MortgageTilAboveZero(unique_ptr<CBank>& bank);

	/* Rebuys a property the player owns that is currently in the banks mortgagedPropertyVector */
	void RepayMortgage(unique_ptr<CBank>& bank);

	/* Sends amount to the bank to be given to the other player at the start of that players next turn */
	void PayPlayer(const int amount, const int otherPlayerIndex, unique_ptr<CBank>& bank);

private:
	/* Index of the player in the playerVector */
	int mIndex = -1;

	/* Name of the player */
	string mName = "Invalid";

	/* Current money held by the player */
	int mMoney = 0;

	/* The amount of money to be requested from the bank on creation */
	const int mkStartingMoney = 1500;

	/* The number of properties the player owns that have been mortgaged */
	int mNumOfMortgagedProperties = 0;
};

