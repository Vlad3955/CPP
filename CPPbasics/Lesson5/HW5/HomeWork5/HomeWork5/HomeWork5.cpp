#include <iostream>

using namespace std;


//================================================================================
// Task 1
//================================================================================


void task1(double arr[], const int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " " << endl;
	}
}


//===============================================================================
// Task 2
//===============================================================================


void task2(int arr[], const int size)
{
	cout << "До" << endl;
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " " << endl;
	}
	cout << "После" << endl;
	for (int i = 0; i < size; i++)
	{
		if (arr[i] == 1)
		{
			arr[i] = 0;
		}
		else
		{
			arr[i] = 1;
		}
	}
}


//================================================================================
// Task 3
//================================================================================


void task3(int arr[], const int size)
{
	int arrInit = 1;
	for (int i = 0; i < size; i++)
	{
		arr[i] = arrInit;
		arrInit += 3;
	}

	
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << endl;
	}
}


//================================================================================
// Task 4
//================================================================================


void task4(int arr[], const int size, int n)
{
	//int n;
	//cout << "Enter number: ";
	//cin >> n;

	int arrIndFirst = arr[0]; 
	int arrIndLast = arr[size - 1];

	for (int i = 0; i < size; i++)
	{
		arr[i] = i;
	}

	for (int i = 0; i < size; i++)
	{
		if (n > 0)
		{
			arrIndLast = arr[0];
		}
		//arr[i] + 1;
		if (n < 0)
		{
			arrIndFirst = arr[size - 1];
		}
		//arr[i] - 1;
	}

	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << endl;
	}

}



int main()
{
	setlocale(LC_ALL, "ru");
	// Task 1
	//==========================================================
	const int SIZE1 = 5;
	double myArr1[SIZE1]{1.1, 1.8, 9.99, 101.11, 55.8};
	//task1(myArr1, SIZE1);


	// Task 2
	//==========================================================
	const int SIZE2 = 10;
	int myArr2[SIZE2]{ 1, 1, 0, 0, 1, 0, 1, 1, 0, 0 };
	// Начальный вариант
	//task2(myArr2, SIZE2);
	// После преобразования
	//task2(myArr2, SIZE2);
   

	// Task 3
	//==========================================================
	const int SIZE3 = 8;
	int myArr3[SIZE3];
	//task3(myArr3, SIZE3);


	// Task 3
	//==========================================================
	const int SIZE4 = 6;
	int myArr4[SIZE4];
	task4(myArr4, SIZE4, 2);
}