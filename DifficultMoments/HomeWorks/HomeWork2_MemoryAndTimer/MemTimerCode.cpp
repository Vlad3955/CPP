#include "MemTimerHeader.h"

// Task 1
template<typename T>
void Swap(T* pY, T* pX)
{
	T temp = *pY;
	*pY = *pX;
	*pX = temp;
}

// Task 2
template<typename T>
void SortPointers(vector<T*>& vec)
{
	sort(vec.begin(), vec.end(), [](T* pY, T* pX)
		{
			return *pY < *pX;
		});
}

// Task3
string_view vowels("AaEeIiOoUu");

void WarAndPeace::countIfFind(const string_view& s)
{
	Timer timer("Count_if with Find");
	size_t count = count_if(s.begin(), s.end(), [&](char ch)
		{
			return vowels.find(ch) != string::npos;
		});
	cout << count << endl;
	timer.print();
}

void WarAndPeace::countIfFor(const string_view& s)
{
	Timer timer("Count_if with For");
	size_t count = count_if(s.begin(), s.end(), [&](char ch)
		{
			for (size_t i = 0; i < vowels.size(); i++)
			{
				if (vowels[i] == ch)
				{
					return true;
				}
			}
			return false;
		});
	cout << count << endl;
	timer.print();
}

void WarAndPeace::forFind(const string_view& s)
{
	int count = 0;
	Timer timer("For with Find");
	for (size_t i = 0; i < s.size(); i++)
	{
		if (vowels.find(s[i]) != string::npos)
		{
			count++;
		}
	}
	cout << count << endl;
	timer.print();
}

void WarAndPeace::forFor(const string_view& s)
{
	int count = 0;
	Timer timer("For with For");
	for (size_t i = 0; i < s.size(); i++)
	{
		for (size_t j = 0; j < vowels.size(); j++)
		{
			if (vowels[j] == s[i])
			{
				count++;
			}
		}
	}
	cout << count << endl;
	timer.print();
}


