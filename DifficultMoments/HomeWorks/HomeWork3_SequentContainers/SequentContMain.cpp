#include "SequentContHeader.h"

// Task 1
void listFlAverage(list<float>& lFl)
{
	float sum = 0, average = 0;
	for (auto& it : lFl)
	{
		sum += it;
	}
	average = sum / lFl.size();
	lFl.push_back(average);
}

// Task 3
template<typename T>
class MyIter
{
public:
	MyIter() {}
	MyIter(T& val)
	{
		Ptr = &val;
	}
	void operator=(T val)
	{
		*Ptr = val;
	}
	T operator*()
	{
		return *Ptr;
	}
	void operator++()
	{
		Ptr++;
	}
	~MyIter() {}
private:
	T* Ptr;
};



int main()
{
	// Task 1
	/*list<float> listFloat = { 23, 44 , 53.2, 100 };
	for (auto& it : listFloat)
	{
		cout << it << " ";
	}
	cout << endl;
	listFlAverage(listFloat);
	for (auto& it : listFloat)
	{
		cout << it << " ";
	}
	cout << endl;*/

	// Task 2
	Matrix matrix(3);
	matrix.printMatrix();
	matrix.determinant();

	// Task 3
	/*vector<int> vec2 = { 9, 11, 44, 123, 56 };
	for (MyIter<int> it : vec2)
	{

		cout << *it << " ";
	}*/
	return 0;
}