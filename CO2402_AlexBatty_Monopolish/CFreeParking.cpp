#include "CFreeParking.h"
#include "CPlayer.h"

CFreeParking::CFreeParking(istream& file) : CSquare(file)
{
	file >> *this;
}

istream& operator>>(istream& inputStream, CFreeParking& ownable)
{
	string secondWord;
	inputStream >> secondWord;
	ownable.mName = ownable.mName + " " + secondWord;
	return inputStream;
}

unique_ptr<CPlayer> CFreeParking::LandedOn(unique_ptr<CPlayer> player)
{
	player = CSquare::LandedOn(move(player));

	cout << player->GetName() << " is resting" << endl;

	return player;
}
