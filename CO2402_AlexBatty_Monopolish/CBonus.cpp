#include "CBonus.h"
#include "CPlayer.h"

unique_ptr<CPlayer> CBonus::LandedOn(unique_ptr<CPlayer> player)
{
    player = CSquare::LandedOn(move(player));

    return player;
}
