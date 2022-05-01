#include "HeaderHW1.h"


ostream& operator<<(ostream& out, const Person& person)
{
	out << setw(12) << person.name << setw(12);
	if (person.patronymic.has_value())
	{
		out << person.patronymic.value();
	}
	out << setw(17) << person.surname << setw(10);
	return out;
}
bool operator<(const Person& p1, const Person& p2)
{
	return tie(p1.name, p1.patronymic, p1.surname) < tie(p2.name, p2.patronymic, p2.surname);
}
bool operator==(const Person& p1, const Person& p2)
{
	return tie(p1.name, p1.patronymic, p1.surname) == tie(p2.name, p2.patronymic, p2.surname);
}



ostream& operator<<(ostream& out, const PhoneNumber& phoneNum)
{
	out << " +" << phoneNum.codeCountry << "(" << phoneNum.codeCity << ")"
		<< phoneNum.phoneNumber << " ";
	if (phoneNum.additionalNum.has_value())
	{
		out << phoneNum.additionalNum.value();
	}
	return out;
}
bool operator<(const PhoneNumber& p1, const PhoneNumber& p2)
{
	return tie(p1.codeCountry, p1.codeCity, p1.phoneNumber, p1.additionalNum) < tie(p2.codeCountry, p2.codeCity, p2.phoneNumber, p2.additionalNum);
}
bool operator==(const PhoneNumber& p1, const PhoneNumber& p2)
{
	return tie(p1.codeCountry, p1.codeCity, p1.phoneNumber, p1.additionalNum) == tie(p2.codeCountry, p2.codeCity, p2.phoneNumber, p2.additionalNum);
}


PhoneBook::PhoneBook()
{
}


PhoneBook::PhoneBook(ifstream& fin)
{
	if (!fin)
	{
		cerr << "Not open!";
		exit(1);
	}
	Person per;
	PhoneNumber phNum;
	while (fin >> per.name >> per.patronymic.value() >> per.surname >> phNum.codeCountry >> phNum.codeCity >> phNum.phoneNumber >> phNum.additionalNum.value())
	{
		auto pair1 = make_pair(per, phNum);
		phoneBook.push_back(pair1);
	}
	fin.close();
}


ostream& operator<<(ostream& out, const PhoneBook& _phoneBook)
{
	for (auto& it : _phoneBook.phoneBook)
	{
		out << it.first << it.second << endl;
	}
	return out;
}

void PhoneBook::SortByName()
{
	sort(phoneBook.begin(), phoneBook.end(), [](const pair<Person, PhoneNumber>& p1, const pair<Person, PhoneNumber>& p2)
		{return p1.first < p2.first; });
}

void PhoneBook::SortByPhone()
{
	sort(phoneBook.begin(), phoneBook.end(), [](const pair<Person, PhoneNumber>& ph1, const pair<Person, PhoneNumber>& ph2)
		{return ph1.second < ph2.second; });
}

tuple<string, PhoneNumber> PhoneBook::GetPhoneNumber(const string& _name)
{
	int count = 0;
	for (auto& it : phoneBook)
	{
		if (it.first.name == _name)
		{
			count++;
		}
	}

	for (auto& it : phoneBook)
	{
		if (count == 0)
		{
			return { "not found", it.second };
		}
		if (count == 1 && it.first.name == _name)
		{
			return { "", it.second };
		}
		if (count > 1)
		{
			return { "found more then 1", it.second };
		}
	}
}

void PhoneBook::ChangePhoneNumber(const Person& p, const PhoneNumber& ph)
{
	for (auto& it : phoneBook)
	{
		if (it.first == p)
		{
			it.second = ph;
		}
	}
}


PhoneBook::~PhoneBook()
{
}


