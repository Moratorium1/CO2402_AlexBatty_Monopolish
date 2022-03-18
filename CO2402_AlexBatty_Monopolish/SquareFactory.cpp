#include "SquareFactory.h"
#include "CGo.h"
#include "CProperty.h"
#include "CBonus.h"
#include "CJail.h"
#include "CStation.h"
#include "CPenalty.h"
#include "CFreeParking.h"
#include "CGoToJail.h"


unique_ptr<CSquare> CreateNewSquare(ESquareType squareType, istream& file, int index)
{
	unique_ptr<CSquare> squarePtr;

	static int jailIndex = 0;

	switch (squareType)
	{
	case ESquareType::Go:
		squarePtr = make_unique<CGo>(file);
		break;

	case ESquareType::Property:
		squarePtr = make_unique<CProperty>(file);
		break;

	case ESquareType::Bonus:
		squarePtr = make_unique<CBonus>(file);
		break;

	case ESquareType::Jail:
		squarePtr = make_unique<CJail>(file);
		jailIndex = index;
		break;

	case ESquareType::Station:
		squarePtr = make_unique<CStation>(file);
		break;

	case ESquareType::FreeParking:
		squarePtr = make_unique<CFreeParking>(file);
		break;

	case ESquareType::Penalty:
		squarePtr = make_unique<CPenalty>(file);
		break;

	case ESquareType::GoToJail:
		squarePtr = make_unique<CGoToJail>(file, jailIndex);
		break;

	default:
		squarePtr = make_unique<CSquare>(file);
		break;
	}

	squarePtr->SetType(squareType);
	squarePtr->SetIndex(index);
	return move(squarePtr);
}
