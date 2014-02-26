#include "MushroomConversions.h"

Shape charToShape(char shape)
{
	Shape shapeToReturn;
	switch (shapeToReturn)
	{
	case 'b':
		shapeToReturn = SHAPE_BELL;
		break;
	case 'c':
		shapeToReturn = SHAPE_CONICAL;
		break;
	case 'x':
		shapeToReturn = SHAPE_CONVEX;
		break;
	case 'f':
		shapeToReturn = SHAPE_FLAT;
		break;
	case 'k':
		shapeToReturn = SHAPE_KNOBBED;
		break;
	case 's':
		shapeToReturn = SHAPE_SUNKEN;
		break;
	case 'e':
		shapeToReturn = SHAPE_ENLARGING;
		break;
	case 't':
		shapeToReturn = SHAPE_TAPERING;
		break;
	default:
		shapeToReturn = SHAPE_UNKNOWN;
		break;
	}
	return shapeToReturn;
}