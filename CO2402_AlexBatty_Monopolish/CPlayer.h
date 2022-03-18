#pragma once
#include <string>
#include <iostream>
#include <vector>
using namespace std;

class CBank;

class CPlayer
{
public:
	CPlayer(istream& file, unique_ptr<CBank>& bank, const int index);
	friend istream& operator >> (istream& inputStream, CPlayer& player);

	/* The index of the SquareList Element that the player is currently on */
	int mSquareIndex = 0;

	/* Changes the mSquareIndex of the player to where the player has landed following the dice roll */
	void MovePlayer(const int rolledValue);

	/* A vector that holds the index of the players owned properties */
	vector<int> ownedPropertyIndex;

	string GetName();
	int GetIndex();
	int GetMoney();

	void PayBank(const int amount, unique_ptr<CBank>& bank);
	void PayedByBank(const int amount, unique_ptr<CBank>& bank);
	void ClaimAccruedRent(unique_ptr<CBank>& bank);

	void PayPlayer(const int amount, const int otherPlayerIndex, unique_ptr<CBank>& bank);

private:
	int mIndex = -1;

	string mName = "Invalid";

	int mMoney = 0;

	const int mkStartingMoney = 1500;
};

