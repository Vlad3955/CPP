#include <iostream>
#include <ctime>

using namespace std;

//=============================================================================
// Task 1
//=============================================================================


void task1()
{
	int* pMyArr;
	int n;
	cout << "Enter size of array: ";
	cin >> n;

	pMyArr = new int[n];


	for (int i = 0; i < n; i++)
	{
		pMyArr[i] = pow(2, i);
		
	}

	for (int i = 0; i < n; i++)
	{
		cout << pMyArr[i] << endl;
	}


	delete[] pMyArr;
}



//=================================================================================
// Task 2
//=================================================================================

void task2()
{
	int** pMyArr2;
	const int sizeA = 4;
	const int sizeB = 4;
	// объявление массива указвтелей и массива int
	pMyArr2 = new int *[sizeA];

	for (int i = 0; i < sizeA; i++)
	{
		pMyArr2[i] = new int[sizeB];
	}

	// заполнение массива
	srand(time(0));

	for (int i = 0; i < sizeA; i++)
	{
		for (int k = 0; k < sizeB; k++)
		{
			pMyArr2[i][k] = rand() % 100;
		}
	}

	// вывод массива
	for (int i = 0; i < sizeA; i++)
	{
		for (int k = 0; k < sizeB; k++)
		{
			cout << pMyArr2[i][k] << " ";
		}
		cout << endl;
	}

	// delete
	for (int i = 0; i < sizeA; i++)
	{
		delete[] pMyArr2[i];
	}

	delete[] pMyArr2;
	pMyArr2 = nullptr;
}




int main()
{
	//task1();
	task2();
	return 0;
}