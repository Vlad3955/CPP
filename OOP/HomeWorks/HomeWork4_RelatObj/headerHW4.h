#pragma once
#include <cstdint>
#include <string>
#include <cmath>
#include <vector>
#include <set>
#include <cassert>

using namespace std;

//==================================================================================
// Task 1
//==================================================================================
class ArrayInt
{
public:
	ArrayInt();
	ArrayInt(int length);
	~ArrayInt();
	void erase();
	int& operator[](int index);
	void resize(int newLength);
	void at(int index, int data);
	void push_back(int value);
	void pop_back();
	void pop_front();
	void fill();
	void print();
	void Sort();

private:
	int m_length;
	int* m_data;
	void swapInt(int* a, int* b);
	int median(int* a, int* b, int* c);
	void qsf(int* arr, int first, int last);
};
//==================================================================================

//==================================================================================
// Task 3
//==================================================================================

enum Suit
{
	Diamonds,
	Hearts,
	Clubs,
	Spades
};

enum Value
{
	two = 2,
	three = 3,
	four = 4,
	five = 5,
	six = 6,
	seven = 7,
	eight = 8,
	nine = 9,
	ten = 10,
	Jack = 10,
	Queen = 10,
	King = 10,
	Ace = 1
};

class Cards
{
public:
	Cards(Suit s, Value v);
	bool flip();
	int getValue();
protected:
	Suit suit;
	Value value;
	bool cardStatus = true;
};

class Hand
{
public:
	Hand();
	void Add(Cards* nCard);
	void Clear();
	int getValue();
private:
	vector<Cards*> cards;
};
//==================================================================================