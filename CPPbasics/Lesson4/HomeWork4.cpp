#include <iostream>

using namespace std;


//============================================================
//Task 1
//============================================================

void task1()
{
	int num;
	cout << "Введите число: " << endl;
	cin >> num;
	if (num >= 10 && num <= 20) 
	{
		cout << "true" << endl;
	} 
	else
	{
		cout << "false" << endl;
	}
}


//============================================================
//Task 2
//============================================================

void task2()
{
	const int NUM1 = 10, NUM2 = 10;
	
	
	if (NUM1 == 10 && NUM2 == 10 || NUM1 + NUM2 == 10)
	{
		cout << "true" << endl;
	}
	else
	{
		cout << "false" << endl;
	}
}



int main()
{
	setlocale(LC_ALL, "Russian");

	//task1();
	task2();


	return 0;
}