#include "CGo.h"
#include "CPlayer.h"

CGo::CGo(istream& file)	: CSquare(file)
{

}

unique_ptr<CPlayer> CGo::LandedOn(unique_ptr<CPlayer> player, unique_ptr<CBank>& bank, unique_ptr<CDie>& die, vector<unique_ptr<CPlayer>>& playerVector)
{
	player = CSquare::LandedOn(move(player));

	return player;
}
