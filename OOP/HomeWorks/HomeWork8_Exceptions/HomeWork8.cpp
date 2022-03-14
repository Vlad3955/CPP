#include "HomeWork8.h"
#include <math.h>


//=======================================================
// Task 1
DivisionByZero::DivisionByZero(string e) : err(e) {}
string DivisionByZero::getDiv() const
{
	return err;
}
//=======================================================

//=======================================================
// Task 2
Ex::Ex(double a) : x(a) {}
double Ex::getx() const
{
	return x;
}

Bar::Bar()
{
	y = 0;
}

void Bar::set(double a)
{
	if (y + a > 100)
	{
		throw Ex(a * y);
	}
	y = a;
}
//=======================================================

//=======================================================
// Task 3
OffTheField::OffTheField(int posX, int posY, int newX, int newY) : currentPosX_(posX), currentPosY_(posY), newPosX_(newX), newPosY_(newY)
{
	getError(); 
}
void OffTheField::getError()
{
	/*if (newPosX_ < 1 || newPosX_ > 10)
		cout << endl << messageX << endl << "Imposible move from ( " << currentPosX_ << " : " << currentPosY_ << " ) to ( "
		<< newPosX_ << " : " << newPosY_ << " )" << endl;
	if (newPosY_ < 1 || newPosY_ > 10)
		cout << endl << messageY << endl << "Imposible move from ( " << currentPosX_ << " : " << currentPosY_ << " ) to ( "
		<< newPosX_ << " : " << newPosY_ << " )" << endl;*/

	if (newPosX_ < 1 || newPosX_ > 10)
		cout << endl << messageX << endl << "Imposible move from ( " << currentPosX_ << " ) to ( "
		<< newPosX_ << " )" << endl;
	if (newPosY_ < 1 || newPosY_ > 10)
		cout << endl << messageY << endl << "Imposible move from ( " << currentPosY_ << " ) to ( "
		<< newPosY_ << " )" << endl;
}

IllegalCommand::IllegalCommand(int curX, int curY, int nextX, int nextY) : currentX(curX), currentY(curY), newX(nextX), newY(nextY) 
{ 
	getError(); 
}
void IllegalCommand::getError()
{
	/*if (abs(currentX - newX) > 1)
		cout << endl << messageX << endl << "Imposible move from ( " << currentX << " : " << currentY << " ) to ( "
		<< newX << " : " << newY << " )" << endl;
	if (abs(currentY - newY) > 1)
		cout << std::endl << messageY << endl << "Imposible move from ( " << currentX << " : " << currentY << " ) to ( "
		<< newX << " : " << newY << " )" << endl;*/

	if (abs(currentX - newX) > 1)
		cout << endl << messageX << endl << "Imposible move from ( " << currentX << " ) to ( "
		<< newX  << " )" << endl;
	if (abs(currentY - newY) > 1)
		cout << std::endl << messageY << endl << "Imposible move from ( " << currentY << " ) to ( "
		<< newY << " )" << endl;
}

Robot::Robot(int x, int y) : pointX(x), pointY(y) 
{ 
	cout << "Current position: x = " << pointX << " y = " << pointY << endl;
}
void Robot::move(int offsetX, int offsetY)
{
	int newPosX = pointX + offsetX;
	int newPosY = pointY + offsetY;
	if (abs(offsetX) > 1 || abs(offsetY) > 1)
		throw IllegalCommand(pointX, pointY, newPosX, newPosY);
	else if (newPosX < 1 || newPosX > 10 || newPosY < 1 || newPosY > 10)
		throw OffTheField(pointX, pointY, newPosX, newPosY);

	cout << "Robot moved from ( " << pointX << " : " << pointY << " ) to ( " << newPosX << " : " << newPosY << " ) position" << endl;
	pointX = newPosX;
	pointY = newPosY;
}
//=======================================================