#pragma once
#include "CEvent.h"
class CPenalty :    public CEvent
{
public:
    CPenalty(istream&);
    ~CPenalty();

    virtual unique_ptr<CPlayer> LandedOn(unique_ptr<CPlayer> player, unique_ptr<CBank>& bank, unique_ptr<CDie>& die) override;
};

