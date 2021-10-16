#include <iostream>
#include <cmath>
#include "mylib.h"
#define OUT_LINE(str) cout << str << endl;
#define CHECK_NUM(a, b) ((a) >= 0 && (a) < (b) ? cout << "true" << endl : cout << "false" << endl);

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
	OUT_LINE("¬ведите 2 числa: ")
	int num1, num2;
	cin >> num1 >> num2;
	CHECK_NUM(num1, num2)
	return 0;
	//==========================
}