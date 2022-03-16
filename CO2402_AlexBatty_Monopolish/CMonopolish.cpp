#include "CMonopolish.h"
#include "CSquare.h"
#include "CPlayer.h"
#include "CDie.h"
#include "SquareFactory.h"

void CMonopolish::SetPlayers()
{
	ifstream playerFile("players.txt");
	if (playerFile.is_open())
	{
		while (!playerFile.eof())
		{
			playerVector.push_back(make_unique<CPlayer>(playerFile));

			//pNewPlayer->SetOccupyingSquare(mpSquareList->GetType(ESquareType::Go));
			//pNewPlayer->SetStartingSquare(mpSquareList->GetType(ESquareType::Go));
			//mpBank->GiveMoney(pNewPlayer->mkStartingMoney, pNewPlayer);
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
		while (file)
		{
			int type = 0;
			file >> type;

			if (type != 0)
			{
				squareVector.push_back(CreateNewSquare(ESquareType(type), file));
			}
		}
	}
	else
	{
		cout << "File not open";
	}
	file.close();
}

CMonopolish::CMonopolish()
{
	SetPlayers();
	SetupSquares();
}

void CMonopolish::PlayRound()
{
	//int valueRolled;
/*
	for (int i = 0; i < playerList.size(); i++)
	{
		// Get a value via a dice roll
		valueRolled = mpDie->RollValue();

		// Add the valueRolled to the players mSquareList index 
		playerList[i]->MovePlayer(valueRolled);

		// With the square stored in the linked list at the index stored by the player call landed on passing the player by reference
		//mpSquareList->GetSquareOfIndex(playerList[i]->mSquareIndex)->LandedOn(playerList[i]);

		playerList[i] = squareVector[playerList[i]->mSquareIndex]->LandedOn(move(playerList[i]));
	}
*/
}


