#include <iostream>
#include <cstdint>
#include <string>
#include <cmath>

using namespace std;

//============================================================================
// Task 1
//============================================================================
class Person
{
public:
	Person(string n = "Name", string s = "Male", int a = 17, int w = 50)
	{
		name = n;
		sex = s;
		age = a;
		weight = w;
	}
	void setName(string n)
	{
		name = n;
	}
	void setSex(string s)
	{
		sex = s;
	}
	void setAge(int a)
	{
		age = a;
	}
	void setWeight(int w)
	{
		weight = w;
	}
	static int count;
protected:
	string name, sex;
	int age, weight;
};


class Student : public Person
{
public:
	Student(string n = "Name", string s = "Male", int a = 17, int w = 50, int study = 2022)
	{
		count++;
		studyYear = study;
	}
	
	void setStudy(int study)
	{
		studyYear = study;
	}
	void print()
	{
		cout << "Name: " << name << endl
			<< "Sex: " << sex << endl
			<< "Age: " << age << endl
			<< "Weight: " << weight << endl
			<< "Year of study: " << studyYear << endl
			<< endl;
	}
private:
	int studyYear;
};
//============================================================================



//============================================================================
// Task 2
//============================================================================
class Fruit
{
public:
	Fruit(string c, string n)
	{
		setName(n);
		setColor(c);
	}
	void setName(string n)
	{
		name = n;
	}
	string getName()
	{
		return name;
	}
	void setColor(string c)
	{
		color = c;
	}
	string getColor()
	{
		return color;
	}
protected:
	string name, color;
};

class Apple : public Fruit
{
public:
	Apple(string c, string n = "apple") : Fruit(c, "apple")
	{
		setColor(c);
		setName(n);
	}
	void setName(string n)
	{
		name = n;
	}
	string getName()
	{
		return name;
	}
	void setColor(string c)
	{
		color = c;
	}
	string getColor()
	{
		return color;
	}
protected:
	string name, color;
};


class Banana : public Fruit
{
public:
	Banana(string c = "yellow", string n = "banana") : Fruit("yellow", "banana")
	{

	}
protected:
	
};


class GrannySmith : public Apple
{
public:
	GrannySmith(string c = "green", string n = "Granny Smith apple") : Apple("green", "Granny Smith apple")
	{

	}
	void setName(string n)
	{
		name = n;
	}
	string getName()
	{
		return name;
	}
	void setColor(string c)
	{
		color = c;
	}
	string getColor()
	{
		return color;
	}

private:
	
};

int Person::count;
//============================================================================


//============================================================================
// Task 3
//============================================================================

/*
* class Cards - карты,масти,значения
* class Player - игрок
* class Dealer - раздающий
* class BlackJack - основные принципы игры
*/


int main()
{
	//Task 1
	//======================================
	Student student1;
	student1.setName("Jon Bread");
	student1.setAge(19);
	student1.setWeight(70);
	student1.setStudy(2020);
	student1.print();

	Student student2;
	student2.setName("Jack Simpson");
	student2.setWeight(55);
	student2.setStudy(2019);
	student2.print();

	Student student3;
	student3.setName("Lisa Crow");
	student3.setAge(20);
	student3.setSex("Female");
	student3.setWeight(82);
	student3.setStudy(2015);
	student3.print();

	cout << "Students: " << Student::count << endl << endl;
	//=======================================

	//Task 2
	//======================================
	Apple a("red");
	Banana b;
	GrannySmith c;

	std::cout << "My " << a.getName() << " is " << a.getColor() << ".\n";
	std::cout << "My " << b.getName() << " is " << b.getColor() << ".\n";
	std::cout << "My " << c.getName() << " is " << c.getColor() << ".\n";
	//======================================
	
	
	return 0;
}