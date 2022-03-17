#include "CDie.h"
#include <ctime>

CDie::CDie()
{
    srand(static_cast<unsigned int> (time(0)));
}

CDie::CDie(const int seed)
{
    srand(seed);
}

int CDie::RollValue()
{
    return static_cast<int>(static_cast<double> (rand()) / (RAND_MAX + 1) * 6.0f + 1);;
}
