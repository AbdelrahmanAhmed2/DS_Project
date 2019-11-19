#include "ArrivalEvent.h"
#include "..\Rest\Restaurant.h"


ArrivalEvent::ArrivalEvent(int eTime, int oID, ORD_TYPE oType):Event(eTime, oID)
{
	OrdType = oType;
}

ArrivalEvent::ArrivalEvent(int eTime, int oID, int oDishes, double oPrice, ORD_TYPE oType) : Event(eTime, oID)
{
	OrdType = oType;
	OrdDishes = oDishes;
	OrdMoney = oPrice;
}
void ArrivalEvent::Execute(Restaurant* pRest)
{
	//This function should create an order and fills its data 
	// Then adds it to normal, vegan, or VIP order lists that you will create in phase1

	Order* pOrd = new Order(OrderID, OrdType, OrdDishes, OrdMoney, EventTime);
	pRest->AddOrders(pOrd);

}
