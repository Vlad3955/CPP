#include "HelperClassesHeader.h"

Person::Person() {}
Person::Person(string _surname, string _name, optional<string> _patronymic = nullopt) : 
	surname(_surname), name(_name), patronymic(_patronymic) {}
ostream& operator<<(ostream& out, const Person& person)
{
	out << setw(12) << person.surname << setw(12);
	out << person.name << setw(17);
	if (person.patronymic.has_value())
	{
		out << person.patronymic.value() << setw(10);
	}
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


PhoneNumber::PhoneNumber() {}
PhoneNumber::PhoneNumber(int _codeCountry, int _codeCity, string _phoneNumber, optional<int> _additionalNum = nullopt) : 
	codeCountry(_codeCountry), codeCity(_codeCity), phoneNumber(_phoneNumber), additionalNum(_additionalNum) {}
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

//bool is_digit(ifstream &_fin) {
//	string num = "0123456789";
//	string s;
//	_fin >> s;
//	for (size_t i = 0; i < s.size(); i++)
//	{
//		for (size_t j = 0; j < num.size(); j++)
//		{
//			if (num[j] == s[i])
//			{
//				return true;
//			}
//		}
//	}
//	return false;
//}


optional<int> getInt(string& s)
{
	if (s == "")
		return nullopt;
	else
		return stoi(s);
}

optional<string> getStr(string& s)
{
	if (s == "")
		return nullopt;
	else
		return s;
}

PhoneBook::PhoneBook() {}

PhoneBook::PhoneBook(ifstream& file)
{

	if (!file)
	{
		cout << "Не удается открыть файл!" << endl;
		exit(-1);
	}
	if (file.peek() == file.eof())
	{
		cout << " Файл пустой." << endl;
		exit(-1);
	}

	string s;

	while (getline(file, s))   // читаем строку из файла
	{
		vector<std::string> tmp;
		stringstream str(s);

		for (string val; getline(str, val, ';'); )   // разбиваем строку на поля
		{
			tmp.push_back(val);
		}
		Person per(tmp[0], tmp[1], getStr(tmp[2]));
		PhoneNumber ph(stoi(tmp[3]), stoi(tmp[4]), tmp[5], getInt(tmp[6]));

		pair<Person, PhoneNumber> tp(per, ph);
		phoneBook.push_back(tp);
	}

	//======================================================
	/*if (!file)
	{
		cerr << "Not open!";
		exit(1);
	}
	Person per;
	PhoneNumber phNum;
	while (file >> per.surname >> per.name >> per.patronymic.value() >> phNum.codeCountry >> phNum.codeCity >> phNum.phoneNumber >> phNum.additionalNum.value())
	{
		auto pair1 = make_pair(per, phNum);
		phoneBook.push_back(pair1);
	}
	fin.close();*/
	//======================================================

	/*if (!fin)
	{
		cerr << "Not open!";
		exit(1);
	}
	Person per;
	PhoneNumber phNum;
	while (!fin.eof())
	{
		fin >> per.surname >> per.name;
		if (is_digit(file))
		{
			file >> phNum.codeCountry >> phNum.codeCity >> phNum.phoneNumber >> phNum.additionalNum.value();
		}
		else
		{
			file >> per.patronymic.value() >> phNum.codeCountry >> phNum.codeCity >> phNum.phoneNumber >> phNum.additionalNum.value();
		}
		auto pair1 = make_pair(per, phNum);
		phoneBook.push_back(pair1);
	}
	fin.close();*/
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
		{return p1.first.surname < p2.first.surname; });
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
		if (it.first.surname == _name)
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
		if (count == 1 && it.first.surname == _name)
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


PhoneBook::~PhoneBook() {}