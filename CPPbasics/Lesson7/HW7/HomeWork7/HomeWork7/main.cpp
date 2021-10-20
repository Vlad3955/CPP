#include <iostream>
#include <cmath>
#include "mylib.h"
#include <string>
#include <fstream>
#define OUT_LINE(str) cout << str << endl;
#define CHECK_NUM(a, b) ((a) >= 0 && (a) < (b) ? cout << "true" << endl : cout << "false" << endl);
#define ARRAY_SIZE 5
#define SwapINT(a, b, c) (c) = (a); (a) = (b); (b) = (c);

using namespace std;
using namespace MyNS;




int main()
{
	setlocale(LC_ALL, "ru");
	// Task 1 & 5
	//=========================

	//const int size = 10;
	//float arr1[size];
	//initArr(arr1, size);
	//showArr(arr1, size);
	//countElement(arr1, size);
	//=========================


	// Task 2
	//=========================

	//OUT_LINE("¬ведите 2 числa: ")
	//int num1, num2;
	//cin >> num1 >> num2;
	//CHECK_NUM(num1, num2)
	//==========================


	// Task 3
	//==========================

	/*cout << "«аполните массив\n\n";
	int initArr2 = 0;
	int arr2[ARRAY_SIZE] = { initArr2 };

	for (int i = 0; i < ARRAY_SIZE; i++)
	{
		cout << "¬ведите число номер: " << i + 1 << endl;
		cin >> initArr2;
		arr2[i] = initArr2;
	}
	cout << endl;

	showArr(arr2, ARRAY_SIZE);*/
	

	//cout << "Bubble sort in ascending(по возрастанию)\n\n";
	//ascend(arr2, ARRAY_SIZE);// обычный пузырек по возрастанию
	//showArr(arr2, ARRAY_SIZE);

	//cout << "Bubble sort in descending(по убыванию)\n\n";
	//descend(arr2, ARRAY_SIZE);// обычный пузырек по убыванию
	//descendDef(arr2, ARRAY_SIZE);// пузырек по убыванию через макрокоманду
	//showArr(arr2, ARRAY_SIZE);

	// Task 4
	//==========================

	/*#pragma pack(push, 1)
	struct Employee
	{
		long id;
		unsigned short age;
		double salary;
		double points;
		string firstName;
		string lastName;
	};
#pragma pack(pop)

	Employee* pEmpl = new Employee;
	
	pEmpl->id = 123456789;
	pEmpl->age = 30;
	pEmpl->salary = 2500;
	pEmpl->firstName = "Ivan";
	pEmpl->lastName = "Ivanov";
	pEmpl->points = 97.8;
	
	cout << sizeof(pEmpl) << endl;
	cout << pEmpl;

	ofstream fout;
	fout.open("Struct.txt");
	if (fout.is_open())
	{
		
		//fout << pEmpl->id << " " << pEmpl->age << " " << pEmpl->salary << " " << pEmpl->firstName << " " << pEmpl->lastName << " " << pEmpl->points;
		fout.close();
	}
	delete pEmpl;*/


#pragma pack(push, 1)
	struct Employee
	{
		long id;
		unsigned short age;
		double salary;
		double points;
		string firstName, lastName;
	};
#pragma pack(pop)

	Employee* pEmpl = new Employee;

	pEmpl->id = 123456789;
	pEmpl->age = 30;
	pEmpl->salary = 2500;
	pEmpl->firstName = "Ivan";
	pEmpl->lastName = "Ivanov";
	pEmpl->points = 97.8;

	cout << sizeof(pEmpl) << endl;
	cout << pEmpl;

	ofstream fout("Struct.txt", ios_base::binary);
	if (fout.is_open())
	{

		fout.write((char*)pEmpl, sizeof(*pEmpl));
		fout.close();
	}
	delete pEmpl;
    
    return 0;
}
