#include <iostream>
#include "MemTimerHeader.h"



int main()
{
	////Task 1
	//int x = 10;
	//int y = 20;
	//int* pY;
	//pY = &y;
	//int* pX;
	//pX = &x;
	//cout << "pY: " << pY << " = " << *pY << " pX: " << pX << " = " << *pX << endl;
	//Swap(&pY, &pX);
	//cout << "pY: " << pY << " = " << *pY << " pX: " << pX << " = " << *pX << endl;

	////Task 2
	//int a = 11;
	//int b = 2;
	//int c = 64;
	//int* pA = &a;
	//int* pB = &b;
	//int* pC = &c;
	//vector<int*> pVec = {pY, pX, pC, pB, pA};
	//for (auto& it : pVec)
	//{
	//	cout << *it << " ";
	//}
	//cout << endl;
	//SortPointers(pVec);
	//for (auto& it : pVec)
	//{
	//	cout << *it << " ";
	//}
	//cout << endl;

	// Task 3
	ifstream file("WarAndPeace.txt");
	file.seekg(0, ios::end);
	size_t size = file.tellg();
	file.seekg(0);
	string s(size, ' ');
	file.read(&s[0], size);

	WarAndPeace::countIfFind(s); // Debug: 174.042 ms; Release: 27.5817 ms;
	WarAndPeace::countIfFor(s); // Debug: 713.827 ms; Release: 23.0144 ms;
	WarAndPeace::forFind(s); // Debug: 213.086 ms; Release: 27.7145 ms;
	WarAndPeace::forFor(s); // Debug: 1104.74 ms; Release: 19.0317 ms;         

	return 0;
}