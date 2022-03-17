#pragma once
#include <string>
#include <iostream>
#include <vector>
using namespace std;

class CPlayer
{
public:
	CPlayer(istream& file);
	friend istream& operator >> (istream& inputStream, CPlayer& player);

	/* The index of the SquareList Element that the player is currently on */
	int mSquareIndex = 0;

	/* Changes the mSquareIndex of the player to where the player has landed following the dice roll */
	void MovePlayer(const int rolledValue);

	/* A vector that holds the index of the players owned properties */
	vector<int> ownedPropertyIndex;

	string GetName();

	



private:
	string mName = "Invalid";

	vector<unique_ptr<CPlayer>> playerVector;

};

