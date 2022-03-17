#pragma once
#include <iostream>
#include <string>
using namespace std;

class CDie
{
public:
	CDie();
	CDie(const int seed);

	int RollValue();
};

