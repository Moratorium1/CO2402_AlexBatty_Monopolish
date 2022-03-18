#include "CBonus.h"
#include "CPlayer.h"
#include "CDie.h"

CBonus::CBonus(istream& file)  : CEvent(file)
{
    eventVector.push_back(make_unique<SEvent>("Find some money. Gain \x9C", 20));
    eventVector.push_back(make_unique<SEvent>("Win a coding competition. Gain \x9C", 50));
    eventVector.push_back(make_unique<SEvent>("Receive a rent rebate. Gain \x9C", 100));
    eventVector.push_back(make_unique<SEvent>("Win the lottery. Gain \x9C", 150));
    eventVector.push_back(make_unique<SEvent>("Sell your iPad. Gain \x9C", 200));
    eventVector.push_back(make_unique<SEvent>("It’s your birthday. Gain \x9C", 300));
}

CBonus::~CBonus()
{
    CEvent::~CEvent();
}

unique_ptr<CPlayer> CBonus::LandedOn(unique_ptr<CPlayer> player, unique_ptr<CBank>& bank, unique_ptr<CDie>& die)
{
    player = CEvent::LandedOn(move(player), bank, die);

    int rolledValue = die->RollValue() - 1;
    int amount = eventVector[rolledValue]->mEventAmount;

    cout << player->GetName() << " rolls " << rolledValue << endl;

    cout << eventVector[rolledValue]->mEventText << amount << endl;

    player->PayedByBank(amount, bank);

    return player;
}