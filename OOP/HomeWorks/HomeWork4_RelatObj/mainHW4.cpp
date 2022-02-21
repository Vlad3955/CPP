#include "headerHW4.h"
#include <iostream>
int main()
{

	// Task1
	//==========================
	ArrayInt AI(15);
	AI.fill();
	AI.print();
	AI.Sort();
	AI.print();
	AI.push_back(14);
	AI.print();
	AI.pop_back();
	AI.pop_back();
	AI.pop_back();
	AI.pop_back();
	AI.print();
	AI.pop_front();
	AI.print();
	//========================

	// Task2
	vector<int> myVector = { 1, 1, 4, 7, 8, 4, 11, 19, 1 };
	set<int> mySet;
	cout << endl <<  "Elements in vector: ";
	for (vector<int>::iterator i = myVector.begin(); i != myVector.end(); i++)
	{
		cout << *i << ", ";
		mySet.insert(*i);
	}
	cout << endl;
	cout << "Number of unique items: " << mySet.size() << endl;
	cout << "Elements in set: ";
	for (set<int>::iterator i = mySet.begin(); i != mySet.end(); i++)
	{
		cout << *i << ", ";
	}
	cout << endl;
	//=======================
	return 0;
}