#include "Cook.h"


Cook::Cook()
{
}

Cook::Cook(int id, ORD_TYPE t, int r_speed, STATUS s, int N)
{
	this->setID(id);
	this->setType(t);
	this->setSpeed(r_speed);
	this->setStatus(s);
	n = N;
}

int Cook::GetID() const
{
	return ID;
}


ORD_TYPE Cook::GetType() const
{
	return type;
}

int Cook::getSpeed() const
{
	return speed;
}

bool Cook::isFree() const
{
	return (status == FREE);
}

int Cook::getN() const {
	return n;
}

void Cook::setID(int id)
{
	ID = id;
}

void Cook::setType(ORD_TYPE t)
{
	type = t;
}

void Cook::setSpeed(int r_speed)
{
	speed = r_speed > 0 ? r_speed : 0;
}

void Cook::setStatus(STATUS s)
{
	if (s == FREE || s == BUSY)
		status = s;
	else
		status = FREE;
}

void Cook::setN(int N) {
	n = N;
}

Cook::~Cook()
{
}