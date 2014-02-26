/* ***       Author:  Wei Kian Chen
     *  Last Update:  January 21, 2014
     *        Class:  CSI-281
     *     Filename:  stack.h
     *
     *  Description:
     *      This is the template stack definition.
     *  
     *  Certification of Authenticity:
     *     I certify that this assignment is entirely my own work.
     **********************************************************************/

#ifndef STACK_H
#define STACK_H

#include <iostream>

using namespace std;

template <class T>
class Stack {
   private:
       template <class T>
       struct Node
       {
          T       mData;
          Node<T> *mNext;

          /*      Pre:  None
           *     Post:  This object is initialized using default values
           *  Purpose:  To intialize date object
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

      Node<T> *mHead, *mTail;
      int     mCount;

   public:
      Stack();
      ~Stack();

      int  getCount();

      void clear();
      void display();
      bool isEmpty();
      bool isExist(T searchKey);
      T    pop();
      void push(T data);
};


template <class T>
Stack<T>::Stack()
{
   mHead  = NULL;
   mTail  = NULL;
   mCount = 0;
}


template <class T>
Stack<T>::~Stack()
{
   while (!isEmpty())
      pop();
}


template <class T>
int Stack<T>::getCount()
{
   return mCount;
}


template <class T>
void Stack<T>::clear()
{
   while (!isEmpty())
      pop();
}


template <class T>
void Stack<T>::display()
{
   Node<T> *tmp;

   if (isEmpty())
      cout << "Empty Stack\n";
   else
   {
      tmp = mHead;

      while (tmp != NULL)
      {
         cout << tmp->mData << " ";
         tmp = tmp->mNext;
      }
      cout << endl;
   }
}


template <class T>
bool Stack<T>::isEmpty()
{
   return mCount == 0;
}


/*      Pre:  The stack is initialized and searchKey is available
 *     Post:  The function retuns true if the searchKey exists in the stack;
 *            otherwise return false
 *  Purpose:  To determine if a given value exists in the stack or not
 *************************************************************************/
template <class T>
bool Stack<T>::isExist(T searchKey)
{
	bool returnVal = false;
	Node<T>* current = mHead;
	while(current != NULL)
	{
		if (current->mData == searchKey)
		{
			returnVal = true;
			current = NULL;
		}
		else
		{
			current = current->mNext;
		}
	}
	return returnVal;
}


/*      Pre:  The stack is initialized
 *     Post:  The first node in the stack is removed, and its content is
 *            returned.  If the stack is empty return the default value
 *            for the given data type
 *  Purpose:  To remove the first node in the stack
 *************************************************************************/
template <class T>
T Stack<T>::pop()
{
	if (mHead == NULL)
	{
		return NULL;
	}
	Node<T>* tmp = mHead;
	T data = mHead->mData;
	mHead = mHead->mNext;
	mCount--;

	//isolate and delete
	tmp->mNext = NULL;
	delete tmp;
	
	return data;
}


/*      Pre:  The stack is initialized
 *     Post:  The new node is added at the beginning of the stack.
 *            Duplication is allowed
 *  Purpose:  To add a new node at the beginning of the stack
 *************************************************************************/
template <class T>
void Stack<T>::push(T data)
{
	Node<T>* node = new Node<T>();
	node->mData = data;
	node->mNext = mHead;
	mHead = node;
	mCount++;
}


#endif