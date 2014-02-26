#ifndef MUSHROOM_H
#define MUSHROOM_H

#include "MushroomAttributes.h"

/* //Dataset
http://archive.ics.uci.edu/ml/machine-learning-databases/mushroom/
*/
class Mushroom
{
private:
	bool mEdible;
	Shape mCapShape;
	Surface mCapSurface;
	Color mCapColor;
	bool mBruises;
	Odor mOdor;
	GillAttachment mGillAttachment;
	Color mGillColor;
	GillSpacing mGillSpacing;
	GillSize mGillSize;
	Shape mStalkShape;
	StalkRoot mStalkRoot;
	Surface mStalkSurfaceAboveRing;
	Surface mStalkSurfaceBelowRing;
	Color mStalkColorAboveRing;
	Color mStalkColorBelowRing;
	VeilType mVeilType;
	Color mVeilColor;
	short mRingNumber;
	RingType mRingType;
	Color mSporePrintColor;
	Population mPopulation;
	Habitat mHabitat;

public:
	//constructor
	Mushroom();
	Mushroom(bool edible, Shape capShape, Surface capSurface, Color capColor, bool bruises, Odor odor, GillAttachment gillAttachment, Color gillColor, 
			 GillSpacing spacing, GillSize size, Shape stalkShape, StalkRoot root, Surface stalkSurfaceAboveRing, Surface stalkSurfaceBelowRing, Color stalkColorAboveRing,
			 Color stalkColorBelowRing, VeilType veilType, Color veilColor, short ringNumber, RingType ringType, Color sporePrintColor, Population population, Habitat habitat);

	Mushroom(char edible, char capShape, char capSurface, char capColor, char bruises, char odor, char gillAttachment, char gillColor, 
			 char gillSpacing, char gillSize, char stalkShape, char stalkRoot, char stalkSurfaceAboveRing, char stalkSurfaceBelowRing , char stalkColorAboveRing,
			 char stalkColorBelowRing, char veilType, char veilColor, char ringNumber, char ringType, char sporePrintColor, char population, char habitat);
	~Mushroom();

	//accessors
	bool isEdible() const;
	Shape getCapShape() const;
	Surface getCapSurface() const;
	Color getCapColor() const;
	bool getBruises() const;
	Odor getOdor() const;
	GillAttachment getGillAttachment() const;
	Color getGillColor() const;
	GillSpacing getGillSpacing() const;
	GillSize getGillSize() const;
	Shape getStalkShape() const;
	StalkRoot getStalkRoot() const;
	Surface getStalkSurfaceAboveRing() const;
	Surface getStalkSurfaceBelowRing() const;
	Color getStalkColorAboveRing() const;
	Color getStalkColorBelowRing() const;
	VeilType getVeilType() const;
	Color getVeilColor() const;
	short getRingNumber() const;
	RingType getRingType() const;
	Color getSporePrintColor() const;
	Population getPopulation() const;
	Habitat getHabitat() const;

	static int distance(const Mushroom* a, const Mushroom* b);
};

#endif