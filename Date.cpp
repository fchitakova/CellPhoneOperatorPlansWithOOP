#include "Date.h"


Date::Date()
{
	day = 1;
	month = 1;
	year = 2017;
}


Date::Date(short d,short m,int y)
{
	setDay(d);
	setMonth(m);
	setYear(y);
}

Date::~Date()
{
	//
}


void Date::setDay(short d)
{
	if (d>=1 && d<=31)
   this-> day = d;
}

void Date::setMonth(short m)
{
	if (m>=1 && m<=12)
	this->month = m;
}

void Date::setYear(int y)
{
	this->year = y;
}

short Date::getDay()const
{
	return this->day;
}
short Date::getMonth()const
{
	return this->month;
}

int Date::getYear()const
{
	return this->year;
}

void Date::readDate()
{
	char c;
	std::cin >>day >> c>>month >> c >> year;
}



void Date::printDate()const
{
	std::cout << day << '.' << month << '.' << year << '\n';
}

