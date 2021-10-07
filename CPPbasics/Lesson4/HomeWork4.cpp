#include <iostream>
#include <cmath>
#include <string>
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


//============================================================
//Task 3
//============================================================

void task3()
{
    
	cout << "Your numbers: ";
	 for (int i = 1; i <= 50; i = i + 2)
	 {
		 
			 
		 
		 cout << i << " ";
	 }
	 cout << endl;
}


//============================================================
//Task 4
//============================================================

void task4(int num)
{
	
	string result = "true";

	if (num > 1)
	{
		for (int i = 2; i < num; i++)
		{
			if (num % i == 0)
			{
				result = "false";
			}
		}
	}
	else
	{
		result = "false";
	}

	cout << result << endl;
}


//============================================================
//Task 5
//============================================================

void task5()
{
	cout << ": ";

	for (int i = 1; i <= 50; i = i + 2)
	{



		cout << i << " ";
	}
	cout << endl;
}



int main()
{
	setlocale(LC_ALL, "Russian");

	int num = 5;

	//task1();
	//task2();
	task3();
	task4(num);
	

	return 0;
}