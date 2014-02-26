#include "Mushroom.h"
#include "MushroomConversions.h"

Mushroom::Mushroom()
{

}

Mushroom::Mushroom(bool edible, Shape capShape, Surface capSurface, Color capColor, bool bruises, Odor odor, GillAttachment gillAttachment, Color gillColor, 
			 GillSpacing gillSpacing, GillSize gillSize, Shape stalkShape, StalkRoot root, Surface stalkSurfaceAboveRing, Surface stalkSurfaceBelowRing, 
			 Color stalkColorAboveRing, Color stalkColorBelowRing, VeilType veilType, Color veilColor, short ringNumber, RingType ringType, Color sporePrintColor, Population population, Habitat habitat)
{
	mEdible = edible;
	mCapShape = capShape;
	mCapSurface = capSurface;
	mCapColor = capColor;
	mBruises = bruises;
	mOdor = odor;
	mGillAttachment = gillAttachment;
	mGillColor = gillColor;
	mGillSpacing = gillSpacing;
	mGillSize = gillSize;
	mStalkShape = stalkShape;
	mStalkRoot = root;
	mStalkSurfaceBelowRing = stalkSurfaceBelowRing;
	mStalkSurfaceAboveRing = stalkSurfaceAboveRing;
	mStalkColorBelowRing = stalkColorBelowRing;
	mStalkColorAboveRing = stalkColorAboveRing;
	mVeilType = veilType;
	mVeilColor = veilColor;
	mRingNumber = ringNumber;
	mSporePrintColor = sporePrintColor;
	mPopulation = population;
	mHabitat = habitat;
}
			

Mushroom::Mushroom(char edible, char capShape, char capSurface, char capColor, char bruises, char odor, char gillAttachment, char gillColor, 
			 char gillSpacing, char gillSize, char stalkShape, char stalkRoot, char stalkSurfaceAboveRing, char stalkSurfaceBelowRing, char stalkColorAboveRing,
			 char stalkColorBelowRing,
			 char veilType, char veilColor, char ringNumber, char ringType, char sporePrintColor, char population, char habitat)
{
	mEdible = false; //CALL EDIBLE CHAR FUNCTION!!
	mCapShape = MushroomConversions::charToShape(capShape);
	mCapSurface =  MushroomConversions::charToSurface(capSurface);
	mCapColor =  MushroomConversions::charToColor(capColor);
	mBruises =  MushroomConversions::charToBruises(bruises);
	mOdor =  MushroomConversions::charToOdor(odor);
	mGillAttachment =  MushroomConversions::charToGillAttachment(gillAttachment);;
	mGillColor =  MushroomConversions::charToColor(gillColor);
	mGillSpacing =  MushroomConversions::charToGillSpacing(gillSpacing);
	mGillSize =  MushroomConversions::charToGillSize(gillSize);
	mStalkShape =  MushroomConversions::charToShape(stalkShape);
	mStalkRoot =  MushroomConversions::charToStalkRoot(stalkRoot);
	mStalkSurfaceBelowRing = MushroomConversions::charToSurface(stalkSurfaceBelowRing);
	mStalkSurfaceAboveRing =  MushroomConversions::charToSurface(stalkSurfaceAboveRing);
	//
	//
	mVeilType =  MushroomConversions::charToVeilType(veilType);
	mVeilColor =  MushroomConversions::charToColor(veilColor);
	mRingNumber =  MushroomConversions::charToRingNumber(ringNumber);
	mSporePrintColor =  MushroomConversions::charToColor(sporePrintColor);
	mPopulation =  MushroomConversions::charToPopulation(population);
	mHabitat =  MushroomConversions::charToHabitat(habitat);
}