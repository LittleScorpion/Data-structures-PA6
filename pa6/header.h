#ifndef HEADER_H
#define HEADER_H

class Mushroom;

#include <iostream>
#include <fstream>
#include <sstream>
#include "queue.h"

using namespace std;



bool containsUnknownData(const string &mushroomString); //check to see if the string contains trash data
bool containsUnknownStalkRoot(const string &mushroomString); //check to see if the string contains trash data on the stalk root
Mushroom* getMushroomFromUser(); //get mushroom data from the user by asking for input
bool getMushroomStringDataFromFile(Queue<string*>* stringQueue, int &numberOfMushrooms, const string &fileName); //get a list of strings that contain the data for each mushroom
void parseStringQueueToMushroomArray(Queue<string*>* &stringQueue, int numberOfStrings, Mushroom **mushroomArray); //take the mushroom string data and parse the strings into mushrooms



#endif