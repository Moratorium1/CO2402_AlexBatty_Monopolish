#include "CMonopolish.h"
#include "SquareFactory.h"
#include "CSquare.h"
#include "CPlayer.h"
#include "CBank.h"
#include "CDie.h"

void CMonopolish::SetPlayers()
{
	ifstream playerFile("players.txt");
	if (playerFile.is_open())
	{
		int index = 0;

		while (!playerFile.eof())
		{
			playerVector.push_back(make_unique<CPlayer>(playerFile, mpBank, index));
			mpBank->amountForPlayer.push_back(0);
			index++;
		}
	}
	else
	{
		cout << "File not open";
	}
	playerFile.close();
}

void CMonopolish::SetupSquares()
{
	ifstream file("monopolish.txt");
	if (file.is_open())
	{
		int index = 0;

		while (file)
		{
			int type = 0;
			file >> type;

			if (type != 0)
			{
				squareVector.push_back(CreateNewSquare(ESquareType(type), file, index));
				index++;
			}
		}
	}
	else
	{
		cout << "File not open";
	}
	file.close();
}

CMonopolish::CMonopolish(const int seed)
{
	mpBank	= make_unique<CBank>();
	mpDie	= make_unique<CDie>(seed);

	SetPlayers();
	SetupSquares();
	PlayGame();
}

CMonopolish::CMonopolish()
{
	mpBank = make_unique<CBank>();
	mpDie = make_unique<CDie>();

	SetPlayers();
	SetupSquares();
	PlayGame();
}

void CMonopolish::PlayGame()
{
	for (int i = 1; i <= 20; i++)
	{
		cout << "Round " << i << endl;
		cout << "=====================" << endl;

		PlayRound();

		// Check if all but one player is bankrupt
	}

	EndGame();
}

void CMonopolish::PlayRound()
{
	for (auto& player : playerVector)
	{
		player->ClaimAccruedRent(mpBank);	// Get rent accured during other players turns

		int rolledValue = mpDie->RollValue();										// Roll a value to move th player

		cout << endl << player->GetName() << " rolled " << rolledValue << endl;		// Output value rolled

		player->MovePlayer(rolledValue);											// Move player			

		if (player->mSquareIndex > squareVector.size() - 1)							// Check if player has passed or landed on Go
		{
			int size = squareVector.size();

			player->MovePlayer(-size);												// Loop the player back to the start of the board

			cout << player->GetName() << " passes GO and collects \x9C" << mPassedGoAmount << endl;		// output that the player passed Go
			player->PayedByBank(mPassedGoAmount, mpBank);							// Pay player for passing go
		}

		player = squareVector[player->mSquareIndex]->LandedOn(move(player), mpBank, mpDie);

		// Handle mortgaging and rebuying properties && output player money

		cout << player->GetName() << " has \x9C" << player->GetMoney() << endl;
	}
	cout << endl;
}

void CMonopolish::EndGame()
{
	for (auto& player : playerVector)		// Loop through and claim all rent from the final round
	{
		player->ClaimAccruedRent(mpBank);
	}

	cout << "GAME END " << endl;
	cout << "=====================" << endl << endl;

	string winningPlayerName = "Invalid";
	int mostMoney = -1;
	for (auto& player : playerVector)
	{
		if (player->GetMoney() > mostMoney)
		{
			winningPlayerName = player->GetName();
			mostMoney = player->GetMoney();
		}

		cout << player->GetName() << " final money = \x9C" << player->GetMoney() << endl;
	}

	cout << winningPlayerName << " Wins!" << endl;
}

	
