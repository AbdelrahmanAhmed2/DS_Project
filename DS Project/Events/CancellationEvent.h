#pragma once
#include "Event.h"

// Cancelling a normal order class
class CancellationEvent : public Event
{
public:
	CancellationEvent(int eTime, int oID);
	~CancellationEvent();

	virtual void Execute(Restaurant* pRest);       //override execute function

};