#include <iostream>
#include <cmath>
#include "mylib.h"
#define OUT_LINE(str) cout << str << endl;
#define CHECK_NUM(a, b) ((a) >= 0 && (a) < (b) ? cout << "true" << endl : cout << "false" << endl);
#define ARRAY_SIZE 5

using namespace std;
using namespace MyNS;

int main()
{
	setlocale(LC_ALL, "ru");
	// Task 1 & 5
	//=========================

	const int size = 10;
	double arr1[size];
	//initArr(arr1, size);
	//showArr(arr1, size);
	//countElement(arr1, size);
	//=========================


	// Task 2
	//=========================

	//OUT_LINE("Введите 2 числa: ")
	//int num1, num2;
	//cin >> num1 >> num2;
	//CHECK_NUM(num1, num2)
	//==========================


	// Task 3
	//==========================

	cout << "Заполните массив\n\n";
	int initArr2 = 0;
	
	int arr2[ARRAY_SIZE] = { initArr2 };
	for (int i = 0; i < ARRAY_SIZE; i++)
	{
		cout << "Введите число номер: " << i + 1 << endl;
		cin >> initArr2;
		arr2[i] = initArr2;
	}

	cout << endl;

	for (int i = 0; i < ARRAY_SIZE; i++)
	{
		cout << arr2[i] << endl;
	}

	cout << endl;

	cout << "Bubble sort\n\n";

	for (int i = 0; i < ARRAY_SIZE - 1; i++)
	{
		for (int j = (ARRAY_SIZE - 1); j > i; j--)
		{
			if (arr2[j - 1] > arr2[j])
			{
				int temp = arr2[j - 1];
				arr2[j - 1] = arr2[j];
				arr2[j] = temp;
			}
		}
	}
    
	cout << endl;

	for (int i = 0; i < ARRAY_SIZE; i++)
	{
		cout << arr2[i] << endl;
	}

	cout << endl;

	return 0;
}