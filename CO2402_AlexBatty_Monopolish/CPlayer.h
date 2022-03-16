#pragma once
#include <string>
#include <iostream>
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

	string GetName();

private:
	string mName = "Invalid";
};

