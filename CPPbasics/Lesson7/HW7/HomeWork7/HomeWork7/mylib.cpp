#include <iostream>
#include <ctime>

using namespace std;

//============================================================================
// Task 1 & 5
//============================================================================
namespace MyNS
{
	void initArr(double arr[], const int size)
	{
		srand(time(0));
		for (int i = 0; i < size; i++)
		{
			arr[i] = rand() % 100 - 50;
		}
	}

	void showArr(double arr[], const int size)
	{
		for (int i = 0; i < size; i++)
		{
			cout << arr[i] << endl;
		}
	}

	void countElement(double arr[], const int size)
	{
		double count1 = 0.0;
		double count2 = 0.0;
		for (int i = 0; i < size; i++)
		{
			if (arr[i] >= 0)
			{
				++count1;
			}
			else
			{
				++count2;
			}
		}
		cout << "Отрицательные числа: " << count2 << endl;
		cout << "Положительные числа: " << count1 << endl;
	}
}


//============================================================================
// Task 3
//============================================================================




/*void task3(int arr[], const int size, int initArr)
{
	for (int i = 0; i < size; i++)
	{
		cout << "Введите число номер: " << i + 1 << endl;
		cin >> initArr;
		arr[i] = initArr;
	}

	cout << endl;
} */