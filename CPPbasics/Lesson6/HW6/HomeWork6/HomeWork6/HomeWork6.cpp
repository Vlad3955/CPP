#include <iostream>
#include <ctime>
#include <string>
#include <fstream>
using namespace std;

//=============================================================================
// Task 1
//=============================================================================


void task1()
{
	int* pMyArr;
	int n;
	cout << "Enter size of array: ";
	cin >> n;

	pMyArr = new int[n];


	for (int i = 0; i < n; i++)
	{
		pMyArr[i] = pow(2, i);
		
	}

	for (int i = 0; i < n; i++)
	{
		cout << pMyArr[i] << endl;
	}


	delete[] pMyArr;
}



//=================================================================================
// Task 2
//=================================================================================

void task2()
{
	int** pMyArr2;
	const int sizeA = 4;
	const int sizeB = 4;
	// ���������� ������� ���������� � ������� int
	pMyArr2 = new int *[sizeA];

	for (int i = 0; i < sizeA; i++)
	{
		pMyArr2[i] = new int[sizeB];
	}

	// ���������� �������
	srand(time(0));

	for (int i = 0; i < sizeA; i++)
	{
		for (int k = 0; k < sizeB; k++)
		{
			pMyArr2[i][k] = rand() % 100;
		}
	}

	// ����� �������
	for (int i = 0; i < sizeA; i++)
	{
		for (int k = 0; k < sizeB; k++)
		{
			cout << pMyArr2[i][k] << " ";
		}
		cout << endl;
	}

	// delete
	for (int i = 0; i < sizeA; i++)
	{
		delete[] pMyArr2[i];
	}

	delete[] pMyArr2;
	pMyArr2 = nullptr;
}



//=============================================================================
// Task 3 � 4
//=============================================================================
void task3_4()
{
	// ������ ������� �����.������ ����� �����: test.txt
	cout << "Enter fitst file name in txt format: ";
	string fileName1;
	cin >> fileName1;
	ofstream fout1(fileName1);
	fout1 << "Childe Harold was he hight but whence his name And lineage long, it suits me not to say Suffice it.";
	fout1.close();
	//=========================================================================

	// ������ ������� �����.������ ����� �����: test.txt
	cout << "Enter second file name in txt format: ";
	string fileName2;
	cin >> fileName2;
	ofstream fout2(fileName2);
	fout2 << "But one sad losel soils a name for aye,However mighty in the olden timeNor florid prose, nor honeyed lines of rhyme,Can blazon evil deeds, or consecrate a crime.";
	fout2.close();
	//=========================================================================


	//���� ����� ������������� �����.������ ����� �����: test.txt
	string buf3;
	cout << "Enter a third name for the merge file: ";
	string fileName3;
	cin >> fileName3;
	

	// ������ 1�� �����
	ifstream fin(fileName1);
	if (fin.is_open())
	{
	
		while (!fin.eof())
		{
			getline(fin, buf3);
		}
		fin.close();
	}
    //=========================================================================

	// ������ � ������������ ���� 1�� �����
	ofstream fout3(fileName3, ios::app);
	fout3 << buf3 << " ";
	//=========================================================================


	// ������ 2�� �����
	ifstream fin2(fileName2);
	if (fin2.is_open())
	{
		
		while (!fin2.eof())
		{
			getline(fin2, buf3);
		}
		fin2.close();
	}
    //==========================================================================
	

	// ������ � ������������ ���� 2�� �����
	ofstream fout4(fileName3, ios::app);
	fout3 << buf3;
	fout3.close();
	//==========================================================================


	// ������ ������������� ����� � ������� � �������
	ifstream fin3(fileName3);
	if (fin3.is_open())
	{
		while (!fin3.eof())
		{
			getline(fin3, buf3);
			cout << buf3;
		}
		fin3.close();
	}

}


void task5()
{
	// ������ ��� �����,��������: m.txt
	cout << "Enter file name in txt format : ";
	string fName;
	cin >> fName;
	string buf;


	// ������ ����,��� �� ������ cout �����������
	ifstream fin(fName);
	if (fin.is_open())
	{
		while (!fin.eof())
		{
			getline(fin, buf);
			cout << buf;
		}
		fin.close();
	}

	cout << "Enter word for search: ";
	string sWord;
	cin >> sWord;

	// ���� �����
	if (buf.find(sWord) != string::npos)
	{
		cout << "We found: " << sWord << endl;
	}
	else
	{
		cout << "We can not find: " << sWord << endl;
	}
}


int main()
{
	//task1();
	//task2();
	//task3_4();
	task5();
	
	return 0;
}