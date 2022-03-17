#include "CPenalty.h"
#include "CPlayer.h"

CPenalty::CPenalty(istream& file) : CEvent(file)
{

}

unique_ptr<CPlayer> CPenalty::LandedOn(unique_ptr<CPlayer> player)
{
    player = CSquare::LandedOn(move(player));

    return unique_ptr<CPlayer>();
}
