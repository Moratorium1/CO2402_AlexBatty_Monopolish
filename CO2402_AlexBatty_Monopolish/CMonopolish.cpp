#include "CMonopolish.h"
#include "SquareFactory.h"
#include "CSquare.h"
#include "CPlayer.h"
#include "CBank.h"
#include "CDie.h"


void CMonopolish::SetPlayers()
{
	ifstream playerFile("players.txt");		// Open the text file
	if (playerFile.is_open())				// If the file was successfully opened
	{
		int index = 0;	// Holds the index of the vector that the player is being created in, passed to the player during creation

		while (!playerFile.eof())
		{
			playerVector.push_back(make_unique<CPlayer>(playerFile, mpBank, index));	// Create the unique_ptr to the player
			mpBank->amountForPlayer.push_back(0);										// Each player is to be assigned an element in the amount for player vector so that they can be paid rent
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
		int index = 0;	// The index of the element the square is being created in, passed to the square during creation

		while (file)
		{
			int type = 0;
			file >> type;

			if (type != 0)
			{
				squareVector.push_back(CreateNewSquare(ESquareType(type), file, index, mpBank));	// Create the square - bank is passed as bank holds the number of each colour
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

CMonopolish::CMonopolish()
{
	// Make the Bank and Die
	mpBank = make_unique<CBank>();
	mpDie = make_unique<CDie>();

	SetPlayers();
	SetupSquares();
	PlayGame();
}

CMonopolish::CMonopolish(const int seed)
{
	// Make the Bank and Die passing a seed to the die
	mpBank	= make_unique<CBank>();
	mpDie	= make_unique<CDie>(seed);

	SetPlayers();		// Populate the playerVector
	SetupSquares();		// Populate the sqaureVector
	PlayGame();			// Play 20 rounds
}

CMonopolish::~CMonopolish()
{
	// Delete all from the playerVector
	playerVector.clear();
	playerVector.shrink_to_fit();

	// Delete all from the squareVector
	squareVector.clear();
	squareVector.shrink_to_fit();
}

void CMonopolish::PlayGame()
{
	//
	for (int i = 1; i <= 20; i++)
	{
		cout << "Round " << i << endl;
		cout << "=====================" << endl;

		PlayRound();

		// Check if each player is bankrupt
		int numOfBankruptPlayers = 0;
		for (auto& player : playerVector)
		{
			if (player->GetMoney() < 0)		// If a player is bankrupt at this stage they failed to mortgage to get above zero and are bankrupt
			{
				player->mbIsBankkrupt = true;
				cout << player->GetName() << " is bankrupt" << endl;
				numOfBankruptPlayers++;
			}
		}

		// If the number of players bankrupt is one less than the total number of players than only one player reamains and the game should end
		if (numOfBankruptPlayers == playerVector.size() - 1)
		{
			EndGame();
			return;
		}
	}

	EndGame();
}

void CMonopolish::PlayRound()
{
	for (auto& player : playerVector)
	{
		if (!player->mbIsBankkrupt)
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
				player->PayedByBank(mPassedGoAmount, mpBank);												// Pay player for passing go
			}

			player = squareVector[player->mSquareIndex]->LandedOn(move(player), mpBank, mpDie, playerVector);	// Call the LandedOn function of the square landed on

			player->EndTurn(mpBank);	// End the players turn - handles mortgaging and rebuying properties
		}
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

	//Get the player with the highest money value and declare them the winner
	string winningPlayerName = "Invalid";
	int mostMoney = -1;
	for (auto& player : playerVector)
	{
		if (player->GetMoney() > mostMoney)
		{
			winningPlayerName = player->GetName();
			mostMoney = player->GetMoney();
		}

		cout << player->GetName() << " has \x9C" << player->GetMoney() << endl;
	}

	cout << endl << winningPlayerName << " Wins!" << endl;
}

	
