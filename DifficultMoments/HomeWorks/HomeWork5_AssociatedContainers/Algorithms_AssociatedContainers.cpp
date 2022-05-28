#include <iostream>
#include <ctime>
#include <cmath>
#include <string>
#include <vector>
#include <set>
#include <unordered_set>
#include <list>
#include <algorithm>


using namespace std;

// Task 1
//========================================================
template<typename Iter>
void uniqueWords(const Iter& itBegin, const Iter& itEnd)
{
	unordered_set<string> uWords(itBegin, itEnd);
	copy(uWords.begin(), uWords.end(), ostream_iterator<string>(cout, ", "));
}
//========================================================

// Task 2
//========================================================
void countSentence(std::string& str)
{
	struct compare
	{
		bool operator()(const std::pair<std::string, int>& p1, const std::pair<std::string, int>& p2) const
		{
			if (p1.second == p2.second)
				return p1.first < p2.first;
			else
				return p1.second < p2.second;
		}
	};

	const std::string punctuation{ ".?!" };
	std::set< std::pair<std::string, int>, compare> sentences;
	std::string tempStr;
	int count = 1;

	for (const char& c : str)
	{
		if (punctuation.find(c) != std::string::npos)
		{
			tempStr += c;
			sentences.insert({ tempStr, count });
			tempStr = "";
			count = 1;
		}
		else
		{
			if (c == ' ' && !tempStr.empty())
			{
				count++;
			}
			else if (c == ' ' && tempStr.empty())
				continue;
			tempStr += c;
		}

	}

	for (auto [str, c] : sentences)
	{
		std::cout << str << "  - " << c << std::endl;
	}
}

//========================================================


int main()
{
	// Task 1
	//======================================================================
	/*vector<string> vecWords{ "one", "two", "three", "one", "four", "two", "one", "five" };
	cout << "Original:" << endl;
	copy(vecWords.begin(), vecWords.end(), ostream_iterator<string>(cout, ", "));
	cout << "\nVector:" << endl;
	uniqueWords(vecWords.begin(), vecWords.end());
	list<string> listWords{ "one", "two", "three", "one", "four", "two", "one", "five" };
	cout << "\nList:" << endl;
	uniqueWords(listWords.begin(), listWords.end());*/
	//======================================================================

	// Task 2
	//======================================================================
	cout << endl << "Task 2" << endl;

	string inputStr = "I have English on Monday, Wednesday and Thursday. English is usually the second lesson.At the English lesson we speak, readand write.We speak about school, pupilsand teachers, about lessons, animalsand nature, about our friends, sportsand games. ";
	/*cout << "Enter text:" << endl;
	getline(cin, inputStr);*/
	countSentence(inputStr);
	cout << endl;

	cout << inputStr << endl;
	//======================================================================
	return 0;
}