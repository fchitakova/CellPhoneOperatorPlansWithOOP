#ifndef PLAN_HEADER_H
#define PLAN_HEADER_H

#include "Date.h"


const unsigned MAX_NAMELEN = 100;

class Plan
{
public:
	Plan();
	Plan(const Plan&rhs);
	Plan&operator=(const Plan&rhs);
	~Plan();
	void setName(const char*n);
	void setMins(const unsigned m);
	void setSms(const unsigned s);
	void setMbs(const unsigned mb);
	void setStartDate(const Date&d);
	void setTerm(unsigned t);
	void setPrice(unsigned p);
	const char*getName()const;
	unsigned getMins()const;
	unsigned getSms()const;
	unsigned getMbs()const;
	unsigned getPrice()const;
	unsigned getTerm()const;
	Date getStartDate()const;

private:
	char*name;
	unsigned minutes;
	unsigned SMSs;
	unsigned MBs;
	unsigned price;
	Date StartDate;
	unsigned term;
	void Copy(const Plan&rhs);
	void Destroy();
};




#endif
