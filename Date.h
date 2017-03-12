#ifndef DATE_H
#define DATE_H

#include <iostream>


class Date
{
public:
	Date();
	Date(short d, short m, int y);
	~Date();
	Date&operator=(const Date&rhs);
	void setDay(short d);
	void setMonth(short m);
	void setYear(int y);
	short getDay()const;
	short getMonth()const;
	int getYear()const;
	void readDate();
	void printDate()const;
	bool isValid(const Date&d)const;
private:
	short day;
	short month;
	int year;
	void Copy(const Date&rhs);
};
#endif