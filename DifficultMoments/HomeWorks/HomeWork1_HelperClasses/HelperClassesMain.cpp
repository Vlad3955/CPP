#include "HelperClassesHeader.h"

int main()
{
	setlocale(LC_ALL, "ru");
	ifstream file("PhoneBook2.txt"); // ïóòü ê ôàéëó PhoneBook.txt
	PhoneBook book(file);
	cout << book;

	cout << "------SortByPhone-------" << endl;
	book.SortByPhone();
	cout << book;

	cout << "------SortByName--------" << endl;
	book.SortByName();
	cout << book;


	auto print_phone_number = [&book](const string& surname) {
		cout << surname << "\t";
		auto answer = book.GetPhoneNumber(surname);
		if (get<0>(answer).empty())
			cout << get<1>(answer);
		else
			cout << get<0>(answer);
		cout << endl;
	};

	print_phone_number("Titova");
	print_phone_number("Petrov");

	cout << "----ChangePhoneNumber----" << endl;
	book.ChangePhoneNumber(Person{ "Markelov", "Dmitrii", "Vadimovich" },
		PhoneNumber{ 7, 123, "15344458", nullopt});
	book.ChangePhoneNumber(Person{ "Mironova", "Margarita", "Vladimirovna" },
		PhoneNumber{ 16, 465, "9155448", 13 });
	cout << book;

	return 0;
}