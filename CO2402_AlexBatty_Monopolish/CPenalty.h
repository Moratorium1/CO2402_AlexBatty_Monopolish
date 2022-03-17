#pragma once
#include "CEvent.h"
class CPenalty :    public CEvent
{
    CPenalty(istream& file);

    virtual unique_ptr<CPlayer> LandedOn(unique_ptr<CPlayer> player) override;
};

