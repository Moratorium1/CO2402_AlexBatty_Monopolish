#include "CGo.h"
#include "CPlayer.h"

CGo::CGo(istream& file)	: CSquare(file)
{

}

unique_ptr<CPlayer> CGo::LandedOn(unique_ptr<CPlayer> player)
{
	return player;
}
