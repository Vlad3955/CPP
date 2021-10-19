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
			arr[i] = static_cast<float> (rand()) / (static_cast<float> (RAND_MAX / (2 * a))) - a;// ������ ������������ �� float(��������� ������������)
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
		cout << "������������� �����: " << count2 << endl;
		cout << "������������� �����: " << count1 << endl;
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

	// ������� ������� �� �����������
	void ascend(int arr[], const int size)
	{
		for (int i = 0; i < size - 1; i++)
		{
			for (int j = (size - 1); j > i; j--)
			{
				if (arr[j - 1] > arr[j])// ������ ���� > �� < �������� �� �������� 
				{
					int temp = arr[j - 1];
					arr[j - 1] = arr[j];
					arr[j] = temp;
				}
			}
		}
		cout << endl;
	}


	//������� ������� �� ��������
	void descend(int arr[], const int size)
	{
		for (int i = 0; i < size - 1; i++)
		{
			for (int j = 0; j < size - 1; j++)
			{
				if (arr[j] < arr[j + 1])// ������ ���� < �� > �������� �� �����������
				{
					int temp = arr[j];
					arr[j] = arr[j + 1];
					arr[j + 1] = temp;
				}
			}
		}
		cout << endl;
	}

	// ������� �� �������� ����� ������������
	void descendDef(int arr[], const int size)
	{
		for (int i = 0; i < size - 1; i++)
		{
			for (int j = 0; j < size - 1; j++)
			{
				if (arr[j] < arr[j + 1])// ������ ���� < �� > �������� �� �����������
				{
					int temp;
					SwapINT(arr[j], arr[j + 1], temp)
				}
			}
		}
		cout << endl;
	}
}




