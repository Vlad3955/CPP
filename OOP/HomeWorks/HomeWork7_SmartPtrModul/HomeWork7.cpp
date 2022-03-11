#include <iostream>
#include "HomeWork7.h"

Date::Date() {}
Date::Date(int d, int m, int y) : day(d), month(m), year(y) {}
Date::~Date() {}
int Date::getDay()
{
	return day;
}
int Date::getMonth()
{
	return month;
}
int Date::getYear()
{
	return year;
}
ostream& operator<<(ostream& out, const Date date)
{
	out << date.day << "." << date.month << "." << date.year;
	return out;
}