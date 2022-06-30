#include "Serial_Deserial_Header.h"


//Task 2
//=======================================================
//template<typename T>
//void ser(T data)
//{
//	ofstream WF("classes.txt", ios::binary);
//	char* D = (char*)&data;
//	WF.write(D, sizeof(T));
//	WF.close();
//}
//
//template<typename T>
//void deser(T &data)
//{
//	ifstream RF("classes.txt", ios::binary);
//	RF.read(reinterpret_cast<char*>(&data), sizeof(T));
//	RF.close();
//}

void ser(FullName data)
{
	ofstream WF("classes.bin", ios::binary);
	char* D = (char*)&data;
	WF.write(D, sizeof(FullName));
	WF.close();
}


void deser(FullName& data)
{
	ifstream RF("classes.txt", ios::binary);
	RF.read(reinterpret_cast<char*>(&data), sizeof(FullName));
	RF.close();
}

//void deser(FullName& data)
//{
//	ifstream RF("classes.bin", ios::binary);
//	string tmp = (char*)&data;
//	cout << tmp.data();
//	tmp.resize(1024);
//	//RF.read(reinterpret_cast<char*>(&data), sizeof(FullName));
//	RF.read(tmp.data(), tmp.size());
//	tmp.resize(RF.gcount());
//	RF.close();
//}
//=======================================================

int main()
{
	//Task 2
	//=======================================================
	FullName fullName("Aaa", "Bbb", "Ccc");
	Student student(fullName, 5);
	
	FullName fullName1("Vvv", "Ddd", "Uuu");
	Student student1(fullName1, 3);

	FullName fullName2("Lll", "Eee", "Kkk");
	Student student2(fullName2, 9);

	FullName fullName5("Ll", "Eee", "Kkk");
	Student student5(fullName5, 9);

	ser(fullName);
	FullName fullName11;
	deser(fullName11);
	cout << "And: " << fullName11.getName();

	//=======================================================

	//Task 3
	//=======================================================
	student.setGrade(5);
	student.setGrade(5);
	student.setGrade(7);
	student.setGrade(7);

	student1.setGrade(4);
	student1.setGrade(8);
	student1.setGrade(2);
	student1.setGrade(5);
	student1.setGrade(3);

	student2.setGrade(4);
	student2.setGrade(8);
	student2.setGrade(2);

	StudenGroup studentGroup(student);
	studentGroup.addStudent(student1);
	studentGroup.addStudent(student2);
	/*studentGroup.Open();

	StudenGroup studentGroup1;
	studentGroup1.Save();
	cout << studentGroup1.GetAllInfo(fullName);*/
	////cout << studentGroup.GetAllInfo(fullName5);
	//cout << studentGroup.GetAllInfo();
	//=======================================================
	return 0;
}