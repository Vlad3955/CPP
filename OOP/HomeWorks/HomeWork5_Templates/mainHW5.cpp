#include <iostream>
#include <cstdint>
#include <string>

using namespace std;

//==================================================================================
// Task 1
//==================================================================================
template<typename T>
class Pair1
{
public:
	Pair1(T n1, T n2) : num1(n1), num2(n2) {}
	T first() const
	{
		return num1;
	}
	T second() const
	{
		return num2;
	}

	T first()
	{
		return num1;
	}
	T second()
	{
		return num2;
	}
private:
	T num1;
	T num2;
};
//==================================================================================

//==================================================================================
// Task 2
//==================================================================================
template<typename T1, typename T2>
class Pair
{
public:
	Pair(T1 n1, T2 n2) : num1(n1), num2(n2) {}
	T1 first() const
	{
		return num1;
	}
	T2  second() const
	{
		return num2;
	}

	T1 first()
	{
		return num1;
	}
	T2 second()
	{
		return num2;
	}
protected:
	T1 num1;
	T2 num2;
};

//==================================================================================
// Task 3
//==================================================================================
template<typename T>
class StringValuePair : public Pair<string, T>
{
public:
	StringValuePair(string s, T num) : Pair<string, T> (s, num) {}

};

int main()
{

	// Task1
	//==========================
	/*Pair1<int> p1(6, 9);
	cout << "Pair: " << p1.first() << ' ' << p1.second() << '\n';

	const Pair1<double> p2(3.4, 7.8);
	cout << "Pair: " << p2.first() << ' ' << p2.second() << '\n';*/
	//========================

	// Task2
	/*Pair<int, double> p1(6, 7.8);
	cout << "Pair: " << p1.first() << ' ' << p1.second() << '\n';

	const Pair<double, int> p2(3.4, 5);
	cout << "Pair: " << p2.first() << ' ' << p2.second() << '\n';*/
	//=======================

	StringValuePair<int> svp("Amazing", 7);
	std::cout << "Pair: " << svp.first() << ' ' << svp.second() << '\n';
	return 0;
}