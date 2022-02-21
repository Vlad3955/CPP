#include "headerHW4.h"
#include <iostream>

//==================================================================================
// Task 1
//==================================================================================
ArrayInt::ArrayInt() : m_length(0), m_data(nullptr) {}

ArrayInt::ArrayInt(int length) : m_length(length)
{
	//assert(length >= 0);
	if (length > 0)
	{
		m_data = new int[length];
	}
	else
	{
		m_data = nullptr;
	}
}

ArrayInt::~ArrayInt()
{
	delete[] m_data;
}

void ArrayInt::erase()
{
	delete[] m_data;
	m_length = 0;
	m_data = nullptr;
}

int& ArrayInt::operator[](int index)
{
	return m_data[index];
}

void ArrayInt::resize(int newLength)
{
	if (newLength <= 0)
	{
		erase();
		return;
	}
	int* newData = new int[newLength] {0};
	int copyElements = 0;
	if (newLength > m_length)
	{
		copyElements = m_length;
	}
	else
	{
		copyElements = newLength;
	}
	for (int i = 0; i < copyElements; i++)
	{
		newData[i] = m_data[i];
	}
	delete[] m_data;
	m_data = newData;
	m_length = newLength;
}

void ArrayInt::at(int index, int data)
{
	if (index >= 0 && index < m_length)
	{
		m_data[index] = data;
	}
}

void ArrayInt::push_back(int value)
{
	int* newData = new int[m_length + 1] {0};
	int copyElements = m_length;
	for (int i = 0; i < copyElements; i++)
	{
		newData[i] = m_data[i];
	}
	newData[m_length] = value;
	delete[] m_data;
	m_data = newData;
	m_length++;
}

void ArrayInt::pop_back()
{
	m_length--;
	int* newData = new int[m_length] {0};
	int copyElements = m_length;
	for (int i = 0; i < copyElements; i++)
	{
		newData[i] = m_data[i];
	}
	delete[] m_data;
	m_data = newData;
}
void ArrayInt::pop_front()
{

	int* newData = new int[m_length] {0};
	int copyElements = m_length;
	for (int i = 1; i < copyElements; i++)
	{
		newData[i - 1] = m_data[i];
	}
	delete[] m_data;
	m_data = newData;
	m_length--;
}

void ArrayInt::fill()
{
	cout << "Enter whole numbers: " << endl;
	for (int i = 0; i < m_length; i++)
	{
		cin >> m_data[i];
	}
}

void ArrayInt::print()
{
	for (int i = 0; i < m_length; i++)
	{
		cout << m_data[i] << ", ";
	}
	cout << endl;
}

void ArrayInt::Sort()
{
	qsf(m_data, 0, m_length - 1);
}


    void ArrayInt::swapInt(int* a, int* b) {
		int t = *a;
		*a = *b;
		*b = t;
	}

	int ArrayInt::median(int* a, int* b, int* c)
	{

		if (*a > *b)
		{
			int t = *a;
			*a = *b;
			*b = t;
		}
		if (*b > *c)
		{
			int t = *b;
			*b = *c;
			*c = t;
		}
		if (*a > *b)
		{
			int t = *a;
			*a = *b;
			*b = t;
		}
		return *b;
	}

	void ArrayInt::qsf(int* arr, int first, int last)
	{
		if (last > 10)
		{
			int i = first;
			int j = last;
			int x = median(&arr[first], &arr[(first + last) / 2], &arr[last]);

			do {
				while (arr[i] < x)
				{
					i++;
				}
				while (arr[j] > x)
				{
					j--;
				}
				if (i <= j)
				{
					swapInt(&arr[i], &arr[j]);
					i++;
					j--;
				}
			} while (i <= j);

			if (i < last)
			{
				qsf(arr, i, last);
			}
			if (first < j)
			{
				qsf(arr, first, j);
			}
		}
		else
		{
			int temp, pos;
			for (int i = first; i <= last; ++i)
			{
				temp = arr[i];
				pos = i - 1;
				while (pos >= 0 && arr[pos] > temp)
				{
					arr[pos + 1] = arr[pos];
					pos--;
				}
				arr[pos + 1] = temp;
			}
		}

	}
//==================================================================================

//==================================================================================
// Task 3
//==================================================================================

		Cards::Cards(Suit s, Value v)
		{
			suit = s;
			value = v;
		}
		bool Cards::flip()
		{
			return true;
		}
		int Cards::getValue()
		{
			return value;
		}

		Hand::Hand()
		{

		}
		void Hand::Add(Cards* nCard)
		{
			cards.push_back(nCard);
		}
		void Hand::Clear()
		{
			cards.clear();
		}
		int Hand::getValue()
		{
			int sum = 0;
			for (auto it : cards)
			{
				if (it->getValue() == Ace && (sum += 11) <= 21)
				{
					sum += 10;
				}
				sum += it->getValue();
			}
			return sum;
		}
//==================================================================================