#include <iostream>
#include <ctime>
#define SwapINT(a, b, c) (c) = (a); (a) = (b); (b) = (c);

using namespace std;

//============================================================================
// Task 1 & 5
//============================================================================
namespace MyNS
{
	void initArr(float arr[], const int size)
	{
		srand(time(0));
		float a = 100;
		for (int i = 0; i < size; i++)
		{
			arr[i] = static_cast<float> (rand()) / (static_cast<float> (RAND_MAX / (2 * a))) - a;// рандом переведенный во float(подсказал одногруппник)
		}
	}

	void showArr(float arr[], const int size)
	{
		for (int i = 0; i < size; i++)
		{
			cout << arr[i] << endl;
		}
	}

	void countElement(float arr[], const int size)
	{
		float count1 = 0.0f;
		float count2 = 0.0f;
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


	//============================================================================
// Task 3
//============================================================================

	void showArr(int arr[], const int size)
	{
		for (int i = 0; i < size; i++)
		{
			cout << arr[i] << endl;
		}
		cout << endl;
	}

	// обычный пузырек по возрастанию
	void ascend(int arr[], const int size)
	{
		for (int i = 0; i < size - 1; i++)
		{
			for (int j = (size - 1); j > i; j--)
			{
				if (arr[j - 1] > arr[j])// сменив знак > на < получаем по убыванию 
				{
					int temp = arr[j - 1];
					arr[j - 1] = arr[j];
					arr[j] = temp;
				}
			}
		}
		cout << endl;
	}


	//обычный пузырек по убыванию
	void descend(int arr[], const int size)
	{
		for (int i = 0; i < size - 1; i++)
		{
			for (int j = 0; j < size - 1; j++)
			{
				if (arr[j] < arr[j + 1])// сменив знак < на > получаем по возрастанию
				{
					int temp = arr[j];
					arr[j] = arr[j + 1];
					arr[j + 1] = temp;
				}
			}
		}
		cout << endl;
	}

	// пузырек по убыванию через макрокоманду
	void descendDef(int arr[], const int size)
	{
		for (int i = 0; i < size - 1; i++)
		{
			for (int j = 0; j < size - 1; j++)
			{
				if (arr[j] < arr[j + 1])// сменив знак < на > получаем по возрастанию
				{
					int temp;
					SwapINT(arr[j], arr[j + 1], temp)
				}
			}
		}
		cout << endl;
	}
}




