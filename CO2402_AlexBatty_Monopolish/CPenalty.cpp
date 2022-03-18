#include "CPenalty.h"
#include "CPlayer.h"

CPenalty::CPenalty(istream& file) : CEvent(file)
{

}

unique_ptr<CPlayer> CPenalty::LandedOn(unique_ptr<CPlayer> player)
{
    player = CSquare::LandedOn(move(player));

    return player;
}

unique_ptr<CPlayer> CPenalty::LandedOn(unique_ptr<CPlayer> player, unique_ptr<CBank>& bank)
{
    return player;
}
