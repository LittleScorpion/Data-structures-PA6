
#ifndef MUSHROOM_CONVERSIONS_H
#define MUSHROOM_CONVERSIONS_H

#include "MushroomAttributes.h"

class MushroomConversions
{
public:
	//converts the chars to the data stored in the mushroom
	static Shape charToShape(char shape);
	static Surface charToSurface(char surface);
	static Color charToColor(char color);
	static bool charToBruises(char bruises);
	static Odor charToOdor(char odor);
	static GillAttachment charToGillAttachment(char gillAttachment);
	static GillSpacing charToGillSpacing(char gillSpacing);
	static GillSize charToGillSize(char gillSize);
	static StalkRoot charToStalkRoot(char stalkRoot);
	static VeilType charToVeilType(char veilType);
	static short charToRingNumber(char ringNumber);
	static RingType charToRingType(char ringType);
	static Population charToPopulation(char population);
	static Habitat charToHabitat(char habitat);
};

#endif