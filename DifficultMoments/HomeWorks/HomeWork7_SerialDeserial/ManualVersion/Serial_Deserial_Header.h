#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <tuple>
#include <iomanip>

using namespace std;



class FullName
{
public:
	FullName();
	FullName(string _surname, string _name, string _patronymic);
	string getName() const;
	string getPatronymic() const;
	string getSurname() const;
	~FullName();
private:
	string name, patronymic, surname;
};

class Student
{
public:
	Student();
	Student(int _grade);
	Student(FullName _fullName, int _grade);
	void setGrade(int _grade);
	vector<int> getGrade();
	FullName getFullName() const;
	double getGPA() const;
	~Student();
private:
	FullName fullName;
	vector<int> grade;
	double gpa;
};

class IRepository {
public:
	virtual void Open() = 0; // бинарная десериализация в файл
	virtual void Save() = 0; // бинарная сериализация в файл
	virtual ~IRepository() {};
};

class IMethods {
public:
	virtual double GetAverageScore(const FullName& name) = 0;
	virtual string GetAllInfo(const FullName& name) = 0;
	virtual string GetAllInfo() = 0;
	virtual ~IMethods() {};
};

class StudenGroup : public IRepository, public IMethods
{
public:
	StudenGroup();
	StudenGroup(Student &_student);
	void addStudent(Student& _student);
	virtual void Open();
	virtual void Save();
	virtual double GetAverageScore(const FullName& name);
	virtual string GetAllInfo(const FullName& name);
	virtual string GetAllInfo();
	~StudenGroup();
private:
	vector<Student> students;
};