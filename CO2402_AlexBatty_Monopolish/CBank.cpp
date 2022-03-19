#include "CBank.h"

CBank::CBank()
{
	mMoney = mkStartingMoney;
}

CBank::~CBank()
{
	mortgagedPropertyVector.clear();
	mortgagedPropertyVector.shrink_to_fit();
}
