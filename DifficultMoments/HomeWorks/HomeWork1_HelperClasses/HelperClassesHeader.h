#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <optional>
#include <tuple>
#include <vector>
#include <cstdlib>
#include <sstream>
#include <algorithm>
#include <iomanip>
#include <functional>

using namespace std;


//struct Person
//{
//	string name, surname;
//	optional<string> patronymic = "";
//	friend ostream& operator<<(ostream& out, const Person& person);
//	friend bool operator<(const Person& p1, const Person& p2);
//	friend bool operator==(const Person& p1, const Person& p2);
//};
//
//struct PhoneNumber
//{
//	int codeCountry = 0, codeCity = 0;
//	string phoneNumber = "";
//	optional<int> additionalNum = -1;
//	friend ostream& operator<<(ostream& out, const PhoneNumber& phoneNum);
//	friend bool operator<(const PhoneNumber& p1, const PhoneNumber& p2);
//	friend bool operator==(const PhoneNumber& p1, const PhoneNumber& p2);
//};

struct Person
{
	Person();
	Person(string _surname, string _name, optional<string> _patronymic);
	string name, surname;
	optional<string> patronymic;
	friend ostream& operator<<(ostream& out, const Person& person);
	friend bool operator<(const Person& p1, const Person& p2);
	friend bool operator==(const Person& p1, const Person& p2);
};

struct PhoneNumber
{
	PhoneNumber();
	PhoneNumber(int _codeCountry, int _codeCity, string _phoneNumber, optional<int> _additionalNum);
	int codeCountry = 0, codeCity = 0;
	string phoneNumber = "";
	optional<int> additionalNum;
	friend ostream& operator<<(ostream& out, const PhoneNumber& phoneNum);
	friend bool operator<(const PhoneNumber& p1, const PhoneNumber& p2);
	friend bool operator==(const PhoneNumber& p1, const PhoneNumber& p2);
};

class PhoneBook
{
public:
	PhoneBook();
	PhoneBook(ifstream& file);
	void SortByName();
	void SortByPhone();
	tuple<string, PhoneNumber> GetPhoneNumber(const string& _surname);
	void ChangePhoneNumber(const Person& p, const PhoneNumber& ph);
	friend ostream& operator<<(ostream& out, const PhoneBook& _phoneBook);
	~PhoneBook();
private:
	vector<pair<Person, PhoneNumber>> phoneBook;
};



