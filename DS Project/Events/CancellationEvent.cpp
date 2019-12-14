#include "CancellationEvent.h"
#include "..\Rest\Restaurant.h"

CancellationEvent::CancellationEvent(int eTime, int oID) :Event(eTime, oID)
{

}

CancellationEvent::~CancellationEvent()
{

}

void CancellationEvent::Execute(Restaurant* pRest)
{
	// search for order .. delete it
}


