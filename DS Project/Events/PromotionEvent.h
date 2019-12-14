#pragma once
#include "Event.h"

class PromotionEvent : public Event
{
private:
	double extraMoney;

public:
	PromotionEvent(int eTime, int oID, double eMoney);
	~PromotionEvent();
	virtual void Execute(Restaurant* pRest);       //override execute function
	double getExtraMoney() const;
};
