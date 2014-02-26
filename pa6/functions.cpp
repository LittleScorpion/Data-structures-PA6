#include "header.h"
#include "Mushroom.h"


bool containsUnknownData(const string &mushroomString)
{
	bool hasTrash = false;
	//increment the loop by two because there is no point in checking the commas in the strings
	for (unsigned int i = 0; i < mushroomString.size(); i += 2)
	{
		if (mushroomString[i] == '?')
		{
			hasTrash = true;
			break;
		}
	}
	return hasTrash;
}


bool containsUnknownStalkRoot(const string &mushroomString)
{
	return (mushroomString[22] == '?');
}


Mushroom* getMushroomFromUser()
{
	string input = "";
	ifstream inputFile;
	Mushroom* mushroom = nullptr;

	//ask the user for the name of the data file of the mushroom
	cout << "Please enter the name of the data file you want to open" << endl;
	getline(cin, input);

	//open the file and validate that it was found
	inputFile.open(input);
	if (inputFile.fail())
	{
		cout << "ERROR, The file could not be found" << endl;
		inputFile.close();
		system("pause");
	}
	else
	{
		//read the mushroom string and close the file
		string mushroomString;
		getline(inputFile, mushroomString);
		inputFile.close();

		if (mushroomString.length >= 45)
		{
			mushroom = new Mushroom
			(
				(mushroomString)[0], (mushroomString)[2], (mushroomString)[4], (mushroomString)[6], (mushroomString)[8], (mushroomString)[10], (mushroomString)[12], (mushroomString)[14], 
				(mushroomString)[16], (mushroomString)[18], (mushroomString)[20], (mushroomString)[22], (mushroomString)[24], (mushroomString)[26], (mushroomString)[28], (mushroomString)[30], 
				(mushroomString)[32], (mushroomString)[34], (mushroomString)[36], (mushroomString)[38], (mushroomString)[40], (mushroomString)[42], (mushroomString)[44]
			);
		}
		else
		{
			cout << "ERROR, The file contained invalid data." << endl;
		}
		system("pause");
		//
	}
	return mushroom;
}


bool getMushroomStringDataFromFile(Queue<string*>* stringQueue, int &numberOfMushrooms, const string &fileName)
{
	bool loadOK = false;

	ifstream reader;
	reader.open(fileName);

	//check to see if the file loaded ok
	loadOK = !reader.fail();
	if (loadOK)
	{		
		string* current = nullptr;

		//read the file line by line
		while (!reader.eof())
		{
			current = new string();
			getline(reader, *current);
			stringQueue->enqueue(current);
			numberOfMushrooms++;
		}
		
	}

	reader.close();

	return loadOK;
}


void parseStringQueueToMushroomArray(Queue<string*>* &stringQueue, int numberOfStrings, Mushroom **mushroomArray)
{
	unsigned int i = 0;
	Mushroom* mushroom;
	string* str;

	while (!stringQueue->isEmpty())
	{
		str = stringQueue->dequeue();
		//str = p,x,y,w,t,p,f,c,n,p,e,e,s,s,w,w,p,w,o,p,k,v,g (Mushroom string)
		//the odd indices are the commas from the data file
		mushroom = new Mushroom
			(
				(*str)[0], (*str)[2], (*str)[4], (*str)[6], (*str)[8], (*str)[10], (*str)[12], (*str)[14], (*str)[16], (*str)[18], (*str)[20], 
				(*str)[22], (*str)[24], (*str)[26], (*str)[28], (*str)[30], (*str)[32], (*str)[34], (*str)[36], (*str)[38], (*str)[40], (*str)[42], (*str)[44]
			);
		//add the string to the mushroom array
		mushroomArray[i] = mushroom;
		i++;

		//free the memory from the string
		delete str;
	}

	//delete the queue since it is no longer needed
	delete stringQueue;

	//I pass the pointer by reference so I can change what the pointer is pointing to outside of this function. This means that the pointer outside this function will be pointing to NULL.
	stringQueue = nullptr;
}