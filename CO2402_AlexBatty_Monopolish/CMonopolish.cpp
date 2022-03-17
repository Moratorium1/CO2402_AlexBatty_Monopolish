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
	PlayRound();
}

void CMonopolish::PlayRound()
{
	for (auto it = playerVector.begin(); it != playerVector.end(); it++)
	{
		unique_ptr<CPlayer>& player = *it;

		player->MovePlayer(mpDie->RollValue());

		player = squareVector[player->mSquareIndex]->LandedOn(move(player));
	}
}