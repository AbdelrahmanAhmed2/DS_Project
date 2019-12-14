#include "PromotionEvent.h"
#include "..\Rest\Restaurant.h"

PromotionEvent::PromotionEvent(int eTime, int oID, double eMoney) :Event(eTime, oID)
{
	extraMoney = eMoney;
}

PromotionEvent::~PromotionEvent()
{

}

double PromotionEvent::getExtraMoney() const
{
	return extraMoney;
}

void PromotionEvent::Execute(Restaurant* pRest)
{
	// Search .. increase price .. change type
	// remove from normal .. add to vip
}