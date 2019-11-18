#pragma once
#include "PriorityNode.h"

template<typename T>
class PriorityQueue
{
private:
	PriorityNode<T>* frontPtr;
	int count;

public:
	PriorityQueue();
	bool enqueue(const T& newEntry, int p);
	bool isEmpty() const;
	bool dequeue(T& frntEntry, int& p);
	bool peekFront(T& frntEntry, int& p)  const;
	void clear();
	~PriorityQueue();
};

/////////////////////////////////////////////////////////////////////////////////////////

/*
Function: PriorityQueue()
The constructor of the Queue class.

*/

template <typename T>
PriorityQueue<T>::PriorityQueue()
{
	frontPtr = nullptr;
	count = 0;
}
/////////////////////////////////////////////////////////////////////////////////////////

/*
Function: isEmpty
Sees whether this queue is empty.

Input: None.
Output: True if the queue is empty; otherwise false.
*/
template <typename T>
bool PriorityQueue<T>::isEmpty() const
{
	if (frontPtr == nullptr)
		return true;
	else
		return false;
}

/////////////////////////////////////////////////////////////////////////////////////////

/*Function:enqueue
Adds newEntry to its right place in this queue according to its priority.

Input: newEntry .
Output: True if the operation is successful; otherwise false.
*/

template <typename T>
bool PriorityQueue<T>::enqueue(const T& newEntry, int p)
{
	PriorityNode<T>* ptr = frontPtr;
	PriorityNode<T>* newNodePtr = new PriorityNode<T>(newEntry, p);
	count++;
	// Empty queue or insert first
	if (ptr == nullptr || ptr->getPriority() < p)
	{
		newNodePtr->setNext(frontPtr);
		frontPtr = newNodePtr;
		return true;
	}

	while (ptr)    // somewhere whithin
	{
		if (ptr->getNext()->getPriority() < p)
		{
			newNodePtr->setNext(ptr->getNext());
			ptr->setNext(newNodePtr);
			return true;
		}
		ptr = ptr->getNext();
	}
	ptr->setNext(newNodePtr); // insert End.
	return true;
} // end enqueue


/////////////////////////////////////////////////////////////////////////////////////////////////////////

/*Function: dequeue
Removes item with highest priority. That is, removes the item that was added
earliest.

Input: None.
Output: True if the operation is successful; otherwise false.
*/

template <typename T>
bool PriorityQueue<T>::dequeue(T& frntEntry, int& p)
{
	if (isEmpty())
		return false;
	count--;
	Node<T>* nodeToDeletePtr = frontPtr;
	frntEntry = frontPtr->getItem();
	p = frontPtr->getPriority();
	frontPtr = frontPtr->getNext();
	// Free memory reserved by the dequeued node
	delete nodeToDeletePtr;
	return true;
}

/////////////////////////////////////////////////////////////////////////////////////////

/*
Function: peekFront
gets the front of this queue. The operation does not modify the queue.

Input: None.
Output: The front of the queue.
return: flase if Queue is empty
*/
template <typename T>
bool PriorityQueue<T>::peekFront(T& frntEntry, int& p) const
{
	if (isEmpty())
		return false;

	frntEntry = frontPtr->getItem();
	p = frontPtr->getPriority();
	return true;

}
/////////////////////////////////////////////////////////////////////////////////////////

/*
Function: clear()
Empties the queue.
*/

template <typename T>
void PriorityQueue<T>::clear()
{
	PriorityNode<T>* ptr = frontPtr;
	while (frontPtr->getNext())
	{
		frontPtr = frontPtr->getNext();
		delete ptr;
		ptr = frontPtr;
	}
	count = 0;
}

///////////////////////////////////////////////////////////////////////////////////

template <typename T>
PriorityQueue<T>::~PriorityQueue()
{
}

