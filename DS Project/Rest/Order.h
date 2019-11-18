#pragma once

#include "..\Defs.h"

class Order
{

protected:
	int ID;         //Each order has a unique ID (from 1 --> 999 )
	ORD_TYPE type;		//order type: Normal, Vegan, VIP
	ORD_STATUS status;	//waiting, in-service, done
	int dishes;	//The number of dishes in that order                 
	double price;	//price

	int ArrTime, ServTime, FinishTime, WaitTime;	//arrival, service start, and finish times
	
	
	//
	// TODO: Add More Data Members As Needed
	//

public:
	Order(int ID, ORD_TYPE r_Type, int r_dishes, double p, int arrTime);
	virtual ~Order();

	void SetID(int r_ID);                  // added
	int GetID() const;                     // added

	void SetType(ORD_TYPE r_type);         // added
	ORD_TYPE GetType() const;

	void SetDishes(int d);
	int GetDishes() const;

	void SetPrice(double);                 // added
	double GetPrice() const;                     // added

	void setStatus(ORD_STATUS s);
	ORD_STATUS getStatus() const;
	
	// added: 
	void SetArrTime(int AT);
	int GetArrTime() const;

	void SetServTime(int ST);
	int GetServTime() const;

	void SetFinishTime(int FT);
	int GetFinishTime() const;

	void SetWaitingTime(int WT);
	int GetWaitingTime() const;

	//
	// TODO: Add More Member Functions As Needed
	//

};
