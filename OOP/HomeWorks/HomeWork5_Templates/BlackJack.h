#pragma once
#include <cstdint>
#include <string>
#include <cmath>
#include <vector>

using namespace std;



//==================================================================================
// Task 4
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
protected:
	vector<Cards*> cards;
};

class GenericPlayer : public Hand
{
public:
	GenericPlayer(string n);
	virtual bool isHitting() = 0;
	bool isBoosted();
	void Bost();
protected:
	string name;
};
//==================================================================================

