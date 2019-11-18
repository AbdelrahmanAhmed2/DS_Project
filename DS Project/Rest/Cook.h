#pragma once

#include "..\Defs.h"

#pragma once
class Cook
{
	int ID;
	ORD_TYPE type;	//for each order type there is a corresponding type (VIP, Normal, Vegan)
	int speed;		//dishes it can prepare in one clock tick (in one timestep)
	STATUS status;     // Added: is the cook free or not
	int n;           // Added: number of consecutive orders after which the cook takes a break.

public:
	Cook();
	Cook(int id, ORD_TYPE t, int r_speed, STATUS s, int n);

	int GetID() const;
	ORD_TYPE GetType() const;
	int getSpeed() const;     // Added
	bool isFree() const;      // Added: checks if cook is free.
	int getN() const;

	void setID(int);
	void setType(ORD_TYPE) ;
	void setSpeed(int s);
	void setStatus(STATUS s);
	void setN(int N);

	virtual ~Cook();
};
