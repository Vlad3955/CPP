#pragma once
#include <iostream>
#include <string>
using namespace std;


//==============================
// Task 1
class DivisionByZero
{
public:
	DivisionByZero(string e);
	string getDiv() const;
private:
	string err;
};
//==============================

//==============================
// Task 2
class Ex
{
public:
	Ex(double a);
	double getx() const;
private:
	double x;
};

class Bar
{
public:
	Bar();
	void set(double a);
private:
	double y;
};
//==============================

//==============================
// Task 3
class OffTheField
{
	int currentPosX_;
	int currentPosY_;
	int newPosX_;
	int newPosY_;
	const string messageX = "Going out of field by X!";
	const string messageY = "Going out of field by Y!";
public:
	OffTheField(int curX, int curY, int nextX, int nextY);
	void getError();
};

class IllegalCommand
{
	int currentX;
	int currentY;
	int newX;
	int newY;
	const string messageX = "Wrong step by X!";
	const string messageY = "Wrong step by Y!";
public:
	IllegalCommand(int curX, int curY, int nextX, int nextY);
	void getError();
};

class Robot
{
	int pointX;
	int pointY;
public:
	Robot(int x, int y);
	void move(int offsetX, int offsetY);
};
//==============================