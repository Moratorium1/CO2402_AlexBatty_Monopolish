#pragma once
#include "CEvent.h"
class CPenalty :    public CEvent
{
public:
    CPenalty(istream& file);

    virtual unique_ptr<CPlayer> LandedOn(unique_ptr<CPlayer> player) override;
    virtual unique_ptr<CPlayer> LandedOn(unique_ptr<CPlayer> player, unique_ptr<CBank>& bank) override;
};

