#include <iostream>
#include <cstdint>
#include <iomanip>
#include <string>

using namespace std;

//==================================================================================
// Task 2
ostream& endll(ostream& stream)
{
	stream << "\n\n";
	stream.flush();
	return stream;
}
//==================================================================================


int main()
{

	// Task1
	//==========================
	int num;
	while (1)
	{
		cout << "Enter the number: ";
		cin >> num;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(32767, '\n');
			continue;
		}

		cin.ignore(32767, '\n');
		if (cin.gcount() > 1)
		{
			continue;
		}
		break;
	}

	cout << "You entered: " << num << endl;
	//========================

	// Task2
	//cout << "ghghgh" << endll;
	//=======================

	
	return 0;
}