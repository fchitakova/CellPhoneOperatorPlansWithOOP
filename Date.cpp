#include "Date.h"


Date::Date()
{
	day = 1;
	month = 1;
	year = 2017;
}

void Date::Copy(const Date&rhs)
{
	setDay(rhs.day);
	setMonth(rhs.month);
	setYear(rhs.year);
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

Date& Date::operator=(const Date&rhs)
{
	if (this != &rhs && isValid(rhs))
	{
		Copy(rhs);
	}
	return *this;
}


void Date::setDay(short d)
{
   this-> day = d;
}

void Date::setMonth(short m)
{
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

bool Date::isValid(const Date&d)const
{
	if (d.day < 1 && (d.month <1 || d.month > 12) && (d.year<2000 || d.year>2025) &&
		(d.month == 2 && (d.day>29)) && ((d.month == 4 || d.month == 6 || d.month == 9 || d.month == 11) && d.day == 31))
		return false;
	return true;
}