#include "CBonus.h"
#include "CPlayer.h"
#include "CDie.h"

CBonus::CBonus(istream& file)  : CEvent(file)
{

}

unique_ptr<CPlayer> CBonus::LandedOn(unique_ptr<CPlayer> player, unique_ptr<CBank>& bank, unique_ptr<CDie>& die)
{
    player = CEvent::LandedOn(move(player), bank, die);

    int rolledValue = die->RollValue() - 1;
    int amount = eventValue[rolledValue];

    cout << player->GetName() << " rolls " << rolledValue << endl;

    // output event text

    player->PayedByBank(amount, bank);

    return player;
}