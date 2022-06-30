#include "Serial_Deserial_Header.h"


// Class FullName
//=================================================
FullName::FullName() {}

FullName::FullName(string _surname, string _name, string _patronymic)
	: surname(_surname), name(_name), patronymic(_patronymic) {}

string FullName::getName() const
{
	return name;
}
string FullName::getPatronymic() const
{
	return patronymic;
}
string FullName::getSurname() const
{
	return surname;
}

FullName::~FullName() {}
//=================================================

// Class Student
//=================================================
Student::Student() { gpa = 0; }

Student::Student(int _grade)
{
	gpa = 0;
	grade.push_back(_grade);
}

Student::Student(FullName _fullName, int _grade)
	: fullName(_fullName), gpa(0)
{
	grade.push_back(_grade);
}

void Student::setGrade(int _grade)
{
	grade.push_back(_grade);
}

vector<int> Student::getGrade()
{
	return grade;
}

FullName Student::getFullName() const
{
	return fullName;
}

double Student::getGPA() const
{
	double sum = 0;
	for (auto& it : grade)
	{
		sum += it;
	}
	return sum / grade.size();
}


Student::~Student() {}
//=================================================

// Class StudenGroup
//=================================================
StudenGroup::StudenGroup() {}

StudenGroup::StudenGroup(Student &_student)
{
	students.push_back(_student);
}

void StudenGroup::addStudent(Student& _student)
{
	students.push_back(_student);
}



void StudenGroup::Open()
{
	/*string temp;
	for_each(students.begin(), students.end(), [&](Student& s)
	{
		temp += reinterpret_cast<char*>(&s);
	});
	ofstream out("data.txt", ios_base::binary);
	auto size = students.size();
	out.write(reinterpret_cast<char*>(&temp), sizeof(size));
	out.close();*/


	//ofstream out("data.bin", ios_base::binary);
	//for_each(students.begin(), students.end(), [&]( Student& s)
	//{
	//	//ofstream out("data.bin", ios_base::app);
	//	auto size = students.size();
	//	out.write(reinterpret_cast<char*>(&s), sizeof(size));
	//});
	//out.close();

	ofstream out("data.bin", ios_base::binary);
	auto size = students.size();
	for_each(students.begin(), students.end(), [&]( Student& s)
	{
		//ofstream out("data.bin", ios_base::app);
		auto size = students.size();
		out.write(reinterpret_cast<char*>(&s), sizeof(size));
	});
	out.close();
}
void StudenGroup::Save()
{
	/*std::ifstream in("data.bin", std::ios_base::binary);
	size_t size = 0;
	
	while (size--)
	{
		Student s;
		in.read(reinterpret_cast<char*>(), sizeof(size));
		students.push_back(std::move(s));
	}
	in.close();*/
}

double StudenGroup::GetAverageScore(const FullName& name)
{
	for (auto& it : students)
	{
		if (it.getFullName().getSurname() == name.getSurname() && it.getFullName().getName() 
			== name.getName() && it.getFullName().getPatronymic() == name.getPatronymic())
		{
			return it.getGPA();
		}
	}
	return 0.0;
}
string StudenGroup::GetAllInfo(const FullName& name)
{
	vector<Student>::iterator it1;
	vector<Student>::iterator it;
	for (it1 = students.begin(); it1 < students.end(); it1++)
	{
		if (it1->getFullName().getSurname() == name.getSurname() && it1->getFullName().getName()
			== name.getName() && it1->getFullName().getPatronymic() == name.getPatronymic())
		{
		    it = it1;
		}
	}
	

	string tmp = "Name: " + it->getFullName().getSurname() + ' ' + it->getFullName().getName() + ' ' + it->getFullName().getPatronymic() + '\n';
	tmp += "Grade: ";
	for (int i = 0; i < it->getGrade().size(); ++i)
	{
		tmp += to_string(it->getGrade()[i]) + "; ";
	}
	tmp += '\n';
	tmp += "GPA: " + to_string(it->getGPA()) + "\n\n";



	/*auto it = find_if(students.begin(), students.end(), [&](const Student& s)
		{
			if (s.getFullName().getSurname() == name.getSurname() && s.getFullName().getName()
				== name.getName() && s.getFullName().getPatronymic() == name.getPatronymic())
			{
				return s.getFullName().getSurname() + ' ' + s.getFullName().getName() + ' ' + s.getFullName().getPatronymic();
			}
		});
	if (it == students.end())
	{
		return {};
	}
	string tmp = "Имя: " + it->getFullName().getSurname() + ' ' + it->getFullName().getName() + ' ' + it->getFullName().getPatronymic() + '\n';
	tmp += "Оценки: ";
	for (int i = 0; i < it->getGrade().size(); ++i)
	{
		tmp += std::to_string(it->getGrade()[i]) + "; ";
	}
	tmp += '\n';
	tmp += "Средний балл: " + std::to_string(it->getGPA()) + "\n\n";*/

	return tmp;
}
string StudenGroup::GetAllInfo()
{
	std::string temp;

	std::for_each(students.begin(), students.end(), [&](const Student& s)
		{
			temp += GetAllInfo(s.getFullName());
		});

	return temp;
}


StudenGroup::~StudenGroup() {}
//=================================================
