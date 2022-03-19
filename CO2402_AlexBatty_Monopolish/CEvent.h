#pragma once
#include "CSquare.h"
#include <fstream>
#include <vector>
#include <string>

using namespace std;

struct SEvent
{
	SEvent(string eventText, int eventAmount)
	{
		mEventText = eventText;
		mEventAmount = eventAmount;
	}

	string mEventText;
	int mEventAmount;
};

class CEvent :	public CSquare
{
public:
	CEvent(istream& file);
	~CEvent();

	virtual unique_ptr<CPlayer> LandedOn(unique_ptr<CPlayer> player, unique_ptr<CBank>& bank, unique_ptr<CDie>& die, vector<unique_ptr<CPlayer>>& playerVector) override;

protected:
	vector<unique_ptr<SEvent>>	eventVector;
};

