#pragma once
#ifndef __PriorityNode_H_
#define __PriorityNode_H_

template < typename T>
class PriorityNode
{
private: 
	T item;
	int priority;
	PriorityNode<T>* next;  // Pointer to next node

public:

	// Constructors
	PriorityNode();
	PriorityNode(T r_item, int p);
	PriorityNode(T r_item, int p, PriorityNode<T>* nextNodePtr);

	// Setters and getters
	void setItem(T r_item);
	void setPriority(int p);
	void setNext(PriorityNode<T>* nextNodePtr);
	T getItem() const;
	int getPriority() const;
	PriorityNode<T>* getNext() const;
}; 

template <typename T>
PriorityNode<T>::PriorityNode()
{
	next = nullptr;
}

template <typename T>
PriorityNode<T>::PriorityNode(T r_item, int p)
{
	item = r_item;
	priority = p;
	next = nullptr;
}

template <typename T>
PriorityNode<T>::PriorityNode(T r_item, int p, PriorityNode<T>* nextNodePtr)
{
	item = r_item;
	priority = p;
	next = nextNodePtr;
}

template <typename T>
void PriorityNode<T>::setItem(T r_item)
{
	item = r_item;
}

template <typename T>
void PriorityNode<T>::setPriority(int p)
{
	priority = p;
}

template <typename T>
void PriorityNode<T>::setNext(PriorityNode<T>* nextNodePtr)
{
	next = nextNodePtr;
}

template <typename T>
T PriorityNode<T>::getItem() const
{
	return item;
}

template <typename T>
int PriorityNode<T>::getPriority() const
{
	return priority;
}

template <typename T>
PriorityNode<T>* PriorityNode<T>::getNext() const
{
	return next;
}

#endif // end Priority Node
