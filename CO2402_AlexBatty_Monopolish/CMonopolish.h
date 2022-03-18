#pragma once
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class CSquare;
class CPlayer;
class CBank;
class CDie;



class CMonopolish
{
public:
	CMonopolish();
	CMonopolish(const int seed);

	/* Calls PlayRound 20 times to play an enitre game */
	void PlayGame();

private:
	/* Calls PlayTurn on each player to play an entire round */
	void PlayRound();

	/* Output End Game, all player money and determine the winner */
	void EndGame();

	/* A vector of unique pointers to the players */
	vector<unique_ptr<CPlayer>> playerVector;

	/* Reads all the player names in from a txt file */
	void SetPlayers();

	/* Hold a pointer to the die - used to generate random values between 1 - 6 */
	unique_ptr<CDie> mpDie;

	/*  A vector of unique pointers to the squares of the board */
	vector<unique_ptr<CSquare>> squareVector;
	void SetupSquares();

	/* A calls that holds the finite amount of money in the game */
	unique_ptr<CBank> mpBank;

	const int mPassedGoAmount = 200;
};

