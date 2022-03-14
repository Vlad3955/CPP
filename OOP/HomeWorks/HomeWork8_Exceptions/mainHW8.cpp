#include <iostream>
#include "HomeWork8.h"


//==================================================================================
// Task 1
template<typename T>
T div(T a, T b)
{
	if (b == 0)
	{
		throw DivisionByZero("Division By Zero!");
	}
	return a / b;
}
//==================================================================================

//==================================================================================
// Task 2



//==================================================================================

//==================================================================================
// Task 3

//==================================================================================

int main()
{
	// Task1
	//==========================
	/*cout << " Task 1" << endl;
	int a, b;
	cout << "Enter dividend: ";
	cin >> a;
	cout << "Enter divider: ";
	cin >> b;
	try
	{
		cout << "Answer is: " << div<int>(a, b) << "." << endl;
	}
	catch (const DivisionByZero dbz)
	{
		cerr << dbz.getDiv() << endl;
	}*/
	//==========================

	// Task2
	//==========================
	/*cout << " Task 2" << endl;
	Bar bar;
	try
	{
		int n = 1;
		cout << "Enter the numbers(press zero for out):" << endl;
		while (n != 0)
		{
			cin >> n;
			bar.set(n);
		}
	}
	catch (const Ex& ex)
	{
		cout << ex.getx() << endl;
	}*/

	//==========================

	// Task3
	//==========================
	{
		cout  << " Task 3" << endl;
		srand(time(NULL));

		Robot r(rand() % 10 + 1, rand() % 10 + 1);
		int x;
		int y;
		while (true)
		{
			cout << "Enter offset for position: (for exit enter 0 : 0)" << endl << "Offset X = ";
			cin >> x;
			cout << "Offset Y = ";
			cin >> y;
			if (x == 0 && y == 0)
				break;
			try {
				r.move(x, y);
			}
			catch (IllegalCommand& err) { cout << endl; }
			catch (OffTheField& err) { cout << endl; }

		}
	}
	//==========================
	return 0;
}