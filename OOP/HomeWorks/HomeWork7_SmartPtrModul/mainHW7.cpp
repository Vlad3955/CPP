#include <iostream>
#include "BlackJack.h"
#include "HomeWork7.h"

using namespace std;

//==================================================================================
// Task 2
shared_ptr<Date> compareDate(shared_ptr<Date> date1, shared_ptr<Date> date2)
{
	if (date1->getDay() > date2->getDay() && date1->getMonth() >= date2->getMonth() && date1->getYear() >= date2->getYear())
	{
		return date1;
	}
	else
	{
		return date2;
	}
}

void swapDate(shared_ptr<Date> date1, shared_ptr<Date> date2)
{
	shared_ptr<Date> tmp(new Date);
	*tmp = *date1;
	*date1 = *date2;
	*date2 = *tmp;
}
//==================================================================================



int main()
{
	// Task1
	//==========================
	cout << "Task 1" << endl;
	unique_ptr<Date> today(new Date(9, 3, 2022));
	cout << today->getDay() << endl;
	cout << today->getMonth() << endl;
	cout << today->getYear() << endl;
	cout << *today << endl;
	unique_ptr<Date> date;
	date = move(today);
	cout << *date << endl << endl;
	//========================

	// Task2
	cout << "Task 2" << endl;
	shared_ptr<Date> Date1(new Date(11, 6, 2021));
	shared_ptr<Date> Date2(new Date(9, 3, 2022));
	cout << *(compareDate(Date1, Date2)) << endl << endl;

	cout << *Date1 << endl;
	cout << *Date2 << endl;
	cout << endl;
	swapDate(Date1, Date2);
	cout << *Date1 << endl;
	cout << *Date2 << endl;
	//=======================

	// BlackJack
	//==========================================
	//cout << "\t\tWelcom to Blackjack!\n\n";

	//int numPlayers = 0;
	//while (numPlayers < 1 || numPlayers > 7)
	//{
	//	cout << "How many players? (1 - 7): ";
	//	cin >> numPlayers;
	//}

	//vector<string> names;
	//string name;
	//for (int i = 0; i < numPlayers; ++i)
	//{
	//	cout << "Enter player name: ";
	//	cin >> name;
	//	names.push_back(name);
	//}
	//cout << endl;

	//// игровой цикл
	//Game aGame(names);
	//char again = 'y';
	//while (again != 'n' && again != 'N')
	//{
	//	aGame.Play();
	//	cout << "\nDo you want to play again? (Y/N): ";
	//	cin >> again;
	//}

	return 0;
}