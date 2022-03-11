#pragma once
#include <iostream>
#include <memory>

using namespace std;

class Date
{
public:
	Date();
	Date(int d, int m, int y);
	~Date();
	int getDay();
	int getMonth();
	int getYear();
    friend ostream& operator<<(ostream& out, const Date date);
private:
	int day, month, year;
};
