#include "CPenalty.h"
#include "CPlayer.h"
#include "CDie.h"

CPenalty::~CPenalty()
{
    CEvent::~CEvent();
}

CPenalty::CPenalty(istream& file) : CEvent(file)
{
    eventVector.push_back(make_unique<SEvent>("Buy a coffee in Starbucks. Gain \x9C", 20));
    eventVector.push_back(make_unique<SEvent>("Pay your broadband bill. Gain \x9C", 50));
    eventVector.push_back(make_unique<SEvent>("Visit the SU shop for food. Gain \x9C", 100));
    eventVector.push_back(make_unique<SEvent>("Buy an assignment solution. Gain \x9C", 150));
    eventVector.push_back(make_unique<SEvent>("Go for a romantic meal. Gain \x9C", 200));
    eventVector.push_back(make_unique<SEvent>("Pay some university fees. Gain \x9C", 300));
}

unique_ptr<CPlayer> CPenalty::LandedOn(unique_ptr<CPlayer> player, unique_ptr<CBank>& bank, unique_ptr<CDie>& die)
{
    player = CEvent::LandedOn(move(player), bank, die);

    int rolledValue = die->RollValue() - 1;
    int amount = eventVector[rolledValue]->mEventAmount;

    cout << player->GetName() << " rolls " << rolledValue << endl;

    cout << eventVector[rolledValue]->mEventText << amount << endl;

    player->PayBank(amount, bank);

    return player;
}
