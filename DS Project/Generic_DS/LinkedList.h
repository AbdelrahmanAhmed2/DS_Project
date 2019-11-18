#pragma once
#include "Node.h"

template<typename T>
class LinkedList
{
private:
	Node<T>* head;
	Node<T>* tail;
	int count;
public:

	LinkedList()
	{
		head = nullptr;
		tail = nullptr;
		count = 0;
	}

	//List is being desturcted ==> delete all items in the list
	~LinkedList() 
	{
		DeleteAll();
	}

	////////////////////////////////////////////////////////////////////////
	/*
	* Function: InsertBeg.
	* Creates a new node and adds it to the beginning of a linked list.
	* Parameters:
	*	- data : The value to be stored in the new node.
	*/

	void InsertBeg(const T& data)
	{
		Node<T>* newNodePtr = new Node<T>(data);
		newNodePtr->setNext(head);
		head = newNodePtr;
		if (tail == nullptr) tail = newNodePtr;
		count++;
	}


	/* Function: InsertEnd.
	* Creates a new node and adds it to the end of a linked list.
	* Parameters:
	*	- data : The value to be stored in the new node. */
	void InsertEnd(const T& data)
	{
		if (head == nullptr) {
			InsertBeg(data);
			return;
		}
		else {
			Node<T>* newNodePtr = new Node<T>(data);
			tail->setNext(newNodePtr);
			tail = newNodePtr;
			count++;
			return;
		}
	}

	////////////////////////////////////////////////////////////////////////
   /*
   * Function: DeleteAll.
   * Deletes all nodes of the list.
   */
	void DeleteAll()
	{
		Node<T>* p = head;
		while (head)
		{
			p = head->getNext();
			delete head;
			head = p;
		}
		tail = nullptr;
		count = 0;
	}

	// CloneList
	/* Clones a given linked list into a new list and returns the new list. */

	LinkedList* CloneList()
	{
		LinkedList* L = new LinkedList();
		Node<T>* p = head;
		while (p)
		{
			L->InsertEnd(p->getItem());
			p = p->getNext();
		}
		return L;
	}

	// InsertSorted 
	/* Given a sorted linked list, the function inserts a given data into its correct position.
	If data is already in the list, it is not inserted and the function returns false*/

	bool InsertSorted(const T& value)
	{
		Node<T>* p = head;

		// Special cases for the head.
		if ((head == nullptr) || (head->getItem() > value))
		{
			// The List is empty or the first item is already larger than the value.
			InsertBeg(value);

		}
		else {

			// If the head value is equal to the value given.
			if (head->getItem() == value)
			{
				return false;
			}
			// If not, then we iterate through the list
			while (p->getNext() != nullptr && (p->getNext())->getItem() < value)
			{
				p = p->getNext();
			}
			// If next item is the value given then don't insert.
			if ((p->getNext())->getItem() == value)
			{
				return false;
			}
			else {
				Node<T>* newNode = new Node<T>(value);
				newNode->setNext(p->getNext());
				p->setNext(newNode);
				count++;
			}
		}

		return true;
	}

	//DeleteFirst
	// Deletes the first node in the list and returns its data.
	// if succeeded return true otherwise, returns false

	bool DeleteFirst(T* data)
	{
		if (head)
		{
			if (head == tail) tail = nullptr;
			Node<T>* p = head->getNext();
			data = head->getItem();
			delete head;
			head = p;
			count--;
			return true;
		}
		return false;
	}

	//DeleteLast
	// Deletes the last node in the list and returns its data.
	// if succeeded return true otherwise, returns false

	bool DeleteLast(T* data)
	{
		if (tail)
		{
			if (head == tail) head = nullptr;
			Node<T>* p = tail->getNext();
			data = tail->getItem();
			delete tail;
			tail = p;
			count--;
			return true;
		}
		return false;
	}

	//DeleteNode
	//deletes the first node with the given value (if found) and returns the node deleted
	//if not found, returns nullptr

	Node<T>* DeleteNode(const T& data)
	{
		if (head == nullptr) return nullptr;
		if (head->getItem() == data)
		{
			DeleteFirst(data);
			Node<T>* n = new Node(data);
			return n;
		}
		if (tail->getItem() == data)
		{
			DeleteLast(data);
			Node<T>* n = new Node(data);
			return n;
		}

		Node<T>* p = head;
		Node<T>* next = p->getNext();

		while (next)
		{
			if (next->getItem() == data) {
				p->setNext(next->getNext());
				count--;
				return next;
			}
			p = next;
			next = p->getNext();
		}
		return nullptr;
	}

	// Getters

	Node<T>* getHead()
	{
		return head;
	}

	Node<T>* getTail()
	{
		return tail;
	}

	int getCount()
	{
		return count;
	}

};