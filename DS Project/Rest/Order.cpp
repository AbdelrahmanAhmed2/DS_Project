#include "Order.h"

Order::Order(int id, ORD_TYPE r_Type, int r_dishes, double p, int arrTime)
{
	ID = (id>0&&id<1000)?id:0;	//1<ID<999
	type = r_Type;
	SetPrice(p);
	SetDishes(r_dishes);
	ArrTime = arrTime;
	status = WAIT;
}

Order::~Order()
{
}

void Order::SetID(int id)
{
	ID = (id > 0 && id < 1000) ? id : 0;
}

int Order::GetID() const
{
	return ID;
}

void Order::SetType(ORD_TYPE r_type)
{
	type = r_type;
}

ORD_TYPE Order::GetType() const
{
	return type;
}


void Order::SetDishes(int d)
{
	dishes = d>0?d:0;
}

int Order::GetDishes() const
{
	return dishes;
}

void Order::SetPrice(double p)
{
	price = (p >= 0) ? p : 0;
}

double Order::GetPrice() const
{
	return price;
}

void Order::setStatus(ORD_STATUS s)
{
	status = s;
}

ORD_STATUS Order::getStatus() const
{
	return status;
}

void Order::SetArrTime(int AT)
{
	ArrTime = AT >= 0 ? AT : 0;
}

int Order::GetArrTime() const
{
	return ArrTime;
}

void Order::SetServTime(int ST)
{
	ServTime = ST > 0 ? ST : 0;
}

int Order::GetServTime() const
{
	return ServTime;
}

void Order::SetFinishTime(int FT)
{
	FinishTime = FT > 0 ? FT : 0;
}

int Order::GetFinishTime() const
{
	return FinishTime;
}

void Order::SetWaitingTime(int WT)
{
	WaitTime = WT;
}

int Order::GetWaitingTime() const
{
	return WaitTime;
}

