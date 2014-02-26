#include "header.h"
#include <iostream>

int main()
{
	//file
	const string DATA_FILE_PATH = "data.txt";

	//this is the array data structure that the mushrooms are stored in
	Mushroom** mushroomArray;

	//create a queue of mushrooms that are represented by strings
	Queue<string*> *mushroomStringQueue;
	mushroomStringQueue = new Queue<string*>();
	int mushroomCount = 0;

	bool loadOK;

	//populate the queue with mushroom strings which will be read from the data file
	loadOK = getMushroomStringDataFromFile(mushroomStringQueue, mushroomCount, DATA_FILE_PATH);

	if (loadOK)
	{
		//take the queue data and parse the strings into mushrooms which will be put into the mushroom array
		parseStringQueueToMushroomArray(mushroomStringQueue, mushroomCount, mushroomArray);
	}


	system("pause");
	return 0;
}