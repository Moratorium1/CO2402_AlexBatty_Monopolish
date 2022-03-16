#include "SquareFactory.h"
#include "CProperty.h"

unique_ptr<CSquare> CreateNewSquare(ESquareType squareType, istream& file)
{
	unique_ptr<CSquare> squarePtr;

	switch (squareType)
	{
	case ESquareType::Property:
		squarePtr = make_unique<CProperty>(file);
		break;

	default:
		squarePtr = make_unique<CSquare>(file);
		break;
	}

	return move(squarePtr);
}
