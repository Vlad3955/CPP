#include <iostream>
#include <cstdint>
#include <string>
#include <cmath>

using namespace std;

//==================================================================================
// Task 1
//==================================================================================
class Figure
{
public:
	Figure(double s, double h) 
	{
		setSide(s);
		setHeight(h);
	}
	virtual double area() = 0;
	void setSide(double s)
	{
		side = s;
	}
	void setHeight(double h)
	{
		height = h;
	}
	void print()
	{
		cout << "The area is " << area() << " cm." << endl;
	}
protected:
	double side, height;
};

class Parallelogram : public Figure
{
public:
	Parallelogram(double s, double h) : Figure(s, h) {}
	virtual double area() override
	{
		return side * height;
	}
};

class Circle : public Figure
{
public:
	Circle(double s) : Figure(s, 0.0) {}
	virtual double area() override
	{
		return 3.14 * (side * side);
	}
};

class Rectangle : public Parallelogram
{
public:
	Rectangle(double s, double h) : Parallelogram(s, h) {}
	virtual double area() override
	{
		return side * height;
	}
};

class Square : public Parallelogram
{
public:
	Square(double s) : Parallelogram(s, 0.0) {}
	virtual double area() override
	{
		return side * side;
	}
};

class Rhombus : public Parallelogram
{
public:
	Rhombus(double s, double h) :Parallelogram(s, h) {}
	virtual double area() override
	{
		return side * height;;
	}
};
//==================================================================================


//==================================================================================
// Task 2
//==================================================================================
class Car
{
public:
	Car()
	{
		cout << __FUNCTION__ << endl;
	}
protected:
	string company, model;
};

class PassengerCar : virtual public Car
{
public:
	PassengerCar()
	{
		cout << __FUNCTION__ << endl;
	}
};

class Bus : virtual public Car
{
public:
	Bus()
	{
		cout << __FUNCTION__ << endl;
	}
};

class Minivan : public PassengerCar, public Bus
{
public:
	Minivan()
	{
		cout << __FUNCTION__ << endl;
	}
};
//==================================================================================

//==================================================================================
// Task 3
//==================================================================================
class Fraction
{
public:
	// конструктор дл€ переменной plus/minus/multiply/divide (constructor for plus/minus/multiply/divide)
	Fraction()
	{
		numerator = 0;// выскакивали предупреждени€ без инициализации(offers appeared without initialization)
		denomerator = 0;
	}
	Fraction(int numer, int denom)
	{
		setNumer(numer);
		setDenom(denom);
	}
	
	void setNumer(int numer)
	{
		numerator = numer;
	}
	
	void setDenom(int denom)
	{
		try
		{
			denomerator = denom;
			if (denomerator == 0)
			{
				throw exception(0);
			}
		}
		catch (exception& ex)
		{
			cerr << "Denomerator cannot be 0: " << ex.what() << endl;
		}
		
	}

	Fraction operator +(const Fraction& other)
	{
		// „ужой вариант кода(someone else code)
		//=============================================
		/*int num, den;
		if (denomerator == other.denomerator)
		{
			num = numerator + other.numerator;
			den = denomerator;
		}
		else
		{
			num = numerator * other.denomerator + other.numerator * denomerator;
			den = denomerator * other.denomerator;
		}
		return Fraction(num, den);*/
		//===============================================
		
		
		// ћой вариант кода(my vwrsion of the code)
		Fraction plus;
		if (denomerator == other.denomerator)
		{
			plus.numerator = numerator + other.numerator;
			plus.denomerator = denomerator;
		}
		else
		{
			plus.numerator = numerator * other.denomerator + other.numerator * denomerator;
			plus.denomerator = denomerator * other.denomerator;
		}
		return plus;
	}

	Fraction operator -(const Fraction& other)
	{
		Fraction minus;
		if (denomerator == other.denomerator)
		{
			minus.numerator = numerator - other.numerator;
			minus.denomerator = denomerator;
		}
		else
		{
			minus.numerator = numerator * other.denomerator - other.numerator * denomerator;
			minus.denomerator = denomerator * other.denomerator;
		}
		return minus;
	}

	Fraction operator *(const Fraction& other)
	{
		Fraction multiply;
		multiply.numerator = numerator * other.numerator;
		multiply.denomerator = denomerator * other.denomerator;
		return multiply;
	}

	Fraction operator /(const Fraction& other)
	{
		Fraction divide;
		divide.numerator = numerator * other.denomerator;
		divide.denomerator = denomerator * other.numerator;
		return divide;
	}

	Fraction operator -()
	{
		return Fraction(- numerator, denomerator);
	}

	void printBool(bool res)
	{
		if (res == 1)
		{
			cout << "true" << endl;
		}
		else
		{
			cout << "false" << endl;
		}
	}
	
	void print()
	{
		try
		{
			if (denomerator == 0)
			{
				throw exception(0);
			}
			else
			{
				cout << numerator << "/" << denomerator << endl;
			}
		}
		catch (exception& ex)
		{
			cerr << "Denomerator cannot be 0: " << ex.what() << endl;
		}
	}

	bool operator == (const Fraction& other)
	{
		return numerator == other.numerator && denomerator == other.denomerator;
	}

	bool operator != (const Fraction& other)
	{
		return !(numerator == other.numerator && denomerator == other.denomerator);
	}

	bool operator > (const Fraction& other)
	{
		return (numerator * other.denomerator) > (other.numerator * denomerator);
	}

	bool operator < (const Fraction& other)
	{
		return (numerator * other.denomerator) < (other.numerator * denomerator);
	}

	bool operator >= (const Fraction& other)
	{
		return ((*this < other) ? false : true);
	}

	bool operator <= (const Fraction& other)
	{
		//return (numerator * other.denomerator) <= (other.numerator * denomerator);
		return ((*this > other) ? false : true);
	}

private:
	int numerator, denomerator;
};
//==================================================================================


//==================================================================================
// Task 4
//==================================================================================

enum Suit
{
	Diamonds,
	Hearts,
	Clubs,
	Spades
};

enum Value
{
	two = 2,
	three = 3,
	four = 4,
	five = 5,
	six = 6,
	seven = 7,
	eight = 8,
	nine = 9,
	ten = 10,
	Jack = 10,
	Queen = 10,
	King = 10,
	Ace = 1
};

class Cards
{
public:
	Cards(Suit s, Value v) 
	{
		suit = s;
		value = v;
	}
	bool flip()
	{

	}
	int getValue()
	{
		return value;
	}
protected:
	Suit suit;
	Value value;
	bool cardStatus = true;
};
//==================================================================================

int main()
{

	// Task3
	//==========================
	Fraction a(2, 0);
	Fraction b(2, 4);
	Fraction c;
	c = a + b;
	c.print();
	c = a - b;
	c.print();
	c = a * b;
	c.print();
	c = a / b;
	c.print();
	
	cout << "a <= b is ";
	bool result = a <= b;
	c.printBool(result);
	cout << "a >= b is ";
	result = a >= b;
	c.printBool(result);
	cout << "a == b is ";
	result = a == b;
	c.printBool(result);
	cout << "a != b is ";
	result = a != b;
	c.printBool(result);
	cout << "a < b is ";
	result = a < b;
	c.printBool(result);
	cout << "a > b is ";
	result = a > b;
	c.printBool(result);
	//========================

	// Task2
	Parallelogram par(7, 10);
	par.print();

	Circle circle(3);
	circle.print();

	Rectangle rect(7, 10);
	rect.print();

	Square square(4);
	square.print();

	Rhombus rhombus(2, 2);
	rhombus.print();
	//=======================

	// Task 3
	//=======================
	PassengerCar car;
	Bus bus;
	Minivan mini;
	//=======================
	return 0;
}