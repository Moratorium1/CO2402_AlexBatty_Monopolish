#pragma once
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class CPlayer;
class CDie;
class CSquare;

class CMonopolish
{
public:
	CMonopolish();

	/* Calls PlayRound 20 times to play an enitre game */
	void PlayGame();

private:
	/* Calls PlayTurn on each player to play an entire round */
	void PlayRound();

	//A vector of unique pointers to the players
	vector<unique_ptr<CPlayer>> playerVector;
	void SetPlayers();

	//
	//unique_ptr<CDie> mpDie = make_unique<CDie>();

	vector<unique_ptr<CSquare>> squareVector;
	void SetupSquares();

	// Bank - holds functions and values related to currency
	// CBank mpBank = make_unique<CBank>();
};

