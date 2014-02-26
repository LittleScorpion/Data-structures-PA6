/* ***       Author:  Template by Wei Kian Chen, finished by Christopher McCooey
     *  Last Update:  January 20, 2014
     *        Class:  CSI-281
     *     Filename:  linkedList.h
     *
     *  Description:
     *      This is the template linked list definition.
     *  
     *  Certification of Authenticity:
     *     I certify that this assignment is entirely my own work.
     **********************************************************************/

#ifndef LINKED_LIST
#define LINKED_LIST

#include <iostream>

using namespace std;

template <class T>
class LinkedList
{
   template <class T>
   struct Node
   {
      T       mData;
      Node<T> *mNext;

      /*      Pre:  None
       *     Post:  This object is initialized using default values
       *  Purpose:  To initialize date object
       *************************************************************************/
      Node()
      {
         mData = T();
         mNext = NULL;
      }


      /*      Pre:  None
       *     Post:  This object is initialized using specified data
       *  Purpose:  To intialize date object
       *************************************************************************/
      Node(T data)
      {
         mData = data;
         mNext = NULL;
      }
   };


   private:
      Node<T> *mHead, *mTail;
      int     mCount;

   public:
      LinkedList();
      ~LinkedList();

      int  getCount();
      T    getData(int index);
      void setData(int index, T data);

      void clear();
      void display();
      bool insert(T data);
      bool isEmpty();
      bool isExist(T searchKey);
      bool remove(T searchKey);
      T    removeAt(int index);

      T operator[](int index);
};


/*      Pre:  None
 *     Post:  This object is initialized using the default
 *  Purpose:  To initialize date object
 *****************************************************************************/
template <class T>
LinkedList<T>::LinkedList()
{
   mHead = NULL;
   mTail = NULL;
   mCount = 0;
}


/*      Pre:  None
 *     Post:  All the nodes in the list is deleted
 *  Purpose:  To remove all the nodes in the list 
 *****************************************************************************/
template <class T>
LinkedList<T>::~LinkedList()
{
	this->clear();
}


/*      Pre:  The object is instantiated
 *     Post:  The number of nodes in the linked list is returned to the caller
 *  Purpose:  To retrieve the number of nodes in the list
 *****************************************************************************/
template <class T>
int LinkedList<T>::getCount()
{
   return mCount;
}


/*      Pre:  The list is instantiated and the index is valid
 *     Post:  The data in the specified index is returned to the caller
 *  Purpose:  To retrieve the specified nodes in the list
 *****************************************************************************/
template <class T>
T LinkedList<T>::getData(int index)
{
	if (index < 0)
	{
		return NULL;
	}
	else if (index > mCount - 1)
	{
		return NULL;
	}

	//tranverse the list to get to the index
	int counter;
	Node<T>* currentNode = mHead;
	for (counter = 0; counter < index; counter++)
	{
		currentNode = currentNode->mNext;
	}
	return currentNode;
}


/*      Pre:  The list is instantiated, the index is valid and the data is
 *            available
 *     Post:  The data in the specified index is updated with the specified
 *            data
 *  Purpose:  To update the specified nodes in the list
 *****************************************************************************/
template <class T>
void LinkedList<T>::setData(int index, T data)
{
	//check to see if the list is empty
	if (mHead == NULL)
	{
		return;
	}
	int counter;
	Node<T>* currentNode = mHead;
	
	for (counter = 0; counter < index; counter++)
	{
		if (counter == index)
		{
			currentNode->mData = data;
		}
		if (currentNode->mNext == nullptr)
		{
			counter = index;
			return;
		}
		currentNode = currentNode->mNext;
	}
	
}



/*      Pre:  The list is initiated
 *     Post:  All the nodes in the list is deleted
 *  Purpose:  To remove all the nodes in the list 
 *****************************************************************************/
template <class T>
void LinkedList<T>::clear()
{
	Node<T> *current = mHead;
	Node<T> *tmp;
	while (current != NULL)
	{
		tmp = current;
		current = current->mNext;
		//isolate the node
		tmp->mNext = NULL;
		delete tmp;
	}
	mHead = NULL;
	mTail = NULL;
	mCount = 0;
}



/*      Pre:  The list is instantiated
 *     Post:  The entire list is displayed on the screen
 *  Purpose:  To show the content of the list
 *****************************************************************************/
template <class T>
void LinkedList<T>::display()
{
   Node<T> *tmp;

   if (mHead == NULL)
   {
      cout << "The list is empty";
      return;
   }

   tmp = mHead;
   while (tmp != NULL)
   {
      cout << tmp->mData; 
	  if (tmp != mTail) //Do not display a space after the last item in the list
	  cout << " ";
      tmp = tmp->mNext;
   }
}


/*      Pre:  The list is instantiated and the data is available
 *     Post:  The data is inserted in ascending order 
 *  Purpose:  To insert a data into the list in ascending order.  However, if
 *            the data already existed in the list, it will not be added again
 *****************************************************************************/
template <class T>
bool LinkedList<T>::insert(T data)
{
   Node<T> *tmp, *oneBefore, *newNode;

   newNode = new Node<T>(data);
   if (newNode == NULL)
      return false;

   if (mHead == NULL)
   {
      mHead = newNode;
      mTail = newNode;
   }
   else
   {
      if (data <= mHead->mData)
      {
         newNode->mNext = mHead;
         mHead = newNode;
      }
      else if (data >= mTail->mData)
      {
         mTail->mNext = newNode;
         mTail = newNode;
      }
      else
      {
         tmp = mHead;
         oneBefore = mHead;
         while (tmp->mData < data)
         {
            oneBefore = tmp;
            tmp = tmp->mNext;
         }

         newNode->mNext = tmp;
         oneBefore->mNext = newNode;
      }
   }

   mCount++;

   return true;
}


/*      Pre:  The list is instantiated 
 *     Post:  The function returns true is the list is empty; false otherwise
 *  Purpose:  To determine if the list is empty
 *****************************************************************************/
template <class T>
bool LinkedList<T>::isEmpty()
{
   return mHead == NULL;
}


/*      Pre:  The list is instantiated and the searchKey is available
 *     Post:  The function returns true if the search key exists in the list;
 *            otherwise false
 *  Purpose:  To determine if a specific value exists in the list or not
 *****************************************************************************/
template <class T>
bool LinkedList<T>::isExist(T searchKey)
{
	Node<T>* currentNode = mHead;
	bool found = false;
	while(currentNode != NULL)
	{
		if (currentNode->mData == searchKey)
		{
			found = true;
			break;
		}		
		currentNode = currentNode->mNext;
	}
	return found;
}


/*      Pre:  The list is instantiated and the searchKey is available
 *     Post:  If the searchKey exists, removes it from the list and the
 *            function returns true; otherwise the function does nothing
 *            and returns false
 *  Purpose:  To remove a specific value from the list
 *****************************************************************************/
template <class T>
bool LinkedList<T>::remove(T searchKey)
{	
	//check for empty
	if (mHead == NULL)
	{
		return false;
	}

	//transverse the list
	Node<T>* currentNode = mHead;
	Node<T>* previousNode = NULL;
	bool found = true;
	bool exit = false;
	while (!exit)
	{
		if (currentNode->mData == searchKey)
		{
			//remove head
			if (currentNode == mHead)
			{
				if (mHead == mTail)
				{
					mHead = NULL;
					mTail = NULL;
				}
				else
				{
					mHead = currentNode->mNext;
				}
			}
			//remove tail
			else if (currentNode == mTail)
			{				
				mTail = previousNode;
				mTail->mNext = NULL;
			}
			//remove middle
			else
			{
				previousNode->mNext = currentNode->mNext;
			}
			
			
			//isolate the node and delete it
			currentNode->mNext = NULL;			
			delete currentNode;
			mCount--;
			exit = true;
			found = true;
		}
		else
		{
			previousNode = currentNode;
			currentNode = currentNode->mNext;
			if (currentNode == NULL)
			{
				exit = true; //end of list and not found
			}
		}		
	}
	return found;
}


/*      Pre:  The list is instantiated and the index is valid
 *     Post:  Remove the element in the specified index location and returns
 *            its content to the caller.  If the index location is invalid, the  
 *            function returns the default value 
 *  Purpose:  To remove an item in the specified index location
 *****************************************************************************/
template <class T>
T LinkedList<T>::removeAt(int index)
{
	T returnVal = T();
	//check for problems
	if (mHead == NULL)
	{
		return returnVal;
	}
	else if (index < 0)
	{
		return returnVal;
	}
	else if (index >= mCount)
	{
		return returnVal;
	}

	//transverse the list
	Node<T>* currentNode = mHead;
	Node<T>* previousNode = NULL;
	int counter = 0;
	while (counter <= index)
	{
		//we found the node delete it
		if (index == counter)
		{
			//remove head
			if (currentNode == mHead)
			{
				if (mHead == mTail)
				{
					mHead = NULL;
					mTail = NULL;
				}
				else
				{
					mHead = currentNode->mNext;
				}
			}
			//remove tail
			else if (currentNode == mTail)
			{				
				mTail = previousNode;
				mTail->mNext = NULL;
			}
			//remove middle
			else
			{
				previousNode->mNext = currentNode->mNext;
			}
					
			//isolate the node and delete it
			currentNode->mNext = NULL;
			returnVal = currentNode->mData;
			delete currentNode;
			mCount--;
		}
		else
		{
			previousNode = currentNode;
			currentNode = currentNode->mNext;
		}
		counter++;
	}
	return returnVal;
}


/*      Pre:  The list is instantiated and the index is valid
 *     Post:  The data in the specified index is returned to the caller
 *  Purpose:  To retrieve the specified nodes in the list using [] operator
 *****************************************************************************/
template <class T>
 T LinkedList<T>::operator[](int index)
{
	
	//check for invalid index
	if (index < 0)
	{
		return NULL;
	}
	else if (index >= mCount)
	{
		return NULL;
	}

	//go through the list
	Node<T> *current = mHead;
	T data = NULL;
	for (int i = 0; i <= index; i++)
	{
		if (i == index)
		{
			data = current->mData;
		}
		current = current->mNext;
	}
	return data;
}

#endif