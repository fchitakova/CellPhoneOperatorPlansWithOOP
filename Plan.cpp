#include "Plan.h"




Plan::Plan()
{
	price = 0;
	minutes = 0;
	SMSs = 0;
	MBs = 0;
	term = 0;
	name = new char[MAX_NAMELEN];
}

void Plan::Copy(const Plan&rhs)
{
	setName(rhs.name);
	setMbs(rhs.MBs);
	setMins(rhs.minutes);
	setSms(rhs.SMSs);
	setPrice(rhs.price);
	setTerm(rhs.term);
	setStartDate(rhs.StartDate);
}

void Plan::Destroy()
{
	delete[]this->name;
	name = 0;
}

Plan::Plan(const Plan&rhs)
{
	Copy(rhs);

}
Plan&Plan::operator=(const Plan&rhs)
{
	if (this != &rhs)
	{
		Copy(rhs);
	}
	return *this;
}

Plan::~Plan()
{
	Destroy();
}

void Plan::setName(const char*n)
{
	Destroy();
	size_t newlen = strlen(n) + 1;
	name = new char[newlen];
	strcpy_s(name, newlen, n);
}
void Plan::setMins(const unsigned m)
{
	minutes = m;
}
void Plan::setSms(const unsigned s)
{
	SMSs = s;
}
void Plan::setMbs(const unsigned mb)
{
	MBs = mb;
}
void Plan::setStartDate(const Date&d)
{
	StartDate = d;
}

void Plan ::setTerm(unsigned t)
{
	term = t;
}
void Plan::setPrice(unsigned p)
{
	price = p;
}
char*Plan::getName()const
{
	return this->name;
}
unsigned Plan::getMins()const
{
	return this->minutes;
}
unsigned Plan::getSms()const
{
	return this->SMSs;
}
unsigned Plan::getMbs()const
{
	return this->MBs;
}
unsigned Plan::getPrice()const
{
	return this->price;
}
unsigned Plan::getTerm()const
{
	return this->term;
}
Date Plan::getStartDate()const
{
	return this->StartDate;
}

