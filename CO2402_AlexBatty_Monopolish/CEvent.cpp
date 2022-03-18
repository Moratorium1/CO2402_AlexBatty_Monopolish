#include "CEvent.h"
#include "CPlayer.h"

CEvent::CEvent(istream& file)	: CSquare(file)
{

}

unique_ptr<CPlayer> CEvent::LandedOn(unique_ptr<CPlayer> player, unique_ptr<CBank>& bank, unique_ptr<CDie>& die)
{
    player = CSquare::LandedOn(move(player));

    return player;
}
