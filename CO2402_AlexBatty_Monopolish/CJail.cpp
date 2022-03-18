#include "CJail.h"
#include "CPlayer.h"

CJail::CJail(istream& file) : CSquare(file)
{

}

unique_ptr<CPlayer> CJail::LandedOn(unique_ptr<CPlayer> player)
{
	player = CSquare::LandedOn(move(player));

	cout << player->GetName() << " is just visiting" << endl;

	return player;
}