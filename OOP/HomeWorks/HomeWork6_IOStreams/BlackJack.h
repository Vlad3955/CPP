#pragma once
#include <cstdint>
#include <string>
#include <cmath>
#include <vector>

using namespace std;

// class Cards
//==================================================================================
class Cards
{
public:
	enum Suit
	{
		DIAMONDS,
		HEARTS,
		CLUBS,
		SPADES
	};

	enum cardValue
	{
		ACE = 1,
		TWO,
		THREE,
		FOUR,
		FIVE,
		SIX,
		SEVEN,
		EIGHT,
		NINE,
		TEN,
		JACK,
		QUEEN,
		KING
	};
	Cards(cardValue v = ACE, Suit s = SPADES, bool cardSt = true);
	void flip();
	int getValue() const;
	friend ostream& operator<< (ostream& out, const Cards& cards);
protected:
	Suit suit;
	cardValue cValue;
	bool cardStatus;
};
//==================================================================================

// class Hand
//==================================================================================
class Hand
{
public:
	Hand();
	virtual ~Hand();
	void Add(Cards* nCard);
	void Clear();
	int getTotal() const;
protected:
	vector<Cards*> cards;
};
//==================================================================================

// class GenericPlayer
//==================================================================================
class GenericPlayer : public Hand
{
	friend ostream& operator<< (ostream& out, const GenericPlayer &genPlayer);
public:
	GenericPlayer(const string& name = "");
	virtual ~GenericPlayer();
	virtual bool isHitting() = 0;
	bool isBusted() const;
	void Bust() const;
protected:
	string name;
};
//==================================================================================

// class Player
//==================================================================================
class Player : public GenericPlayer
{
public:
	Player(const string& name = "");
	virtual bool IsHitting() const;
	void Win() const;
	void Lose() const;
	void Push() const;
};
//==================================================================================

// class House
//==================================================================================
class House : public GenericPlayer
{
public:
	House(const string& name = "House");
	virtual ~House();
	virtual bool IsHitting() const;
	void FlipFirstCard();
};
//==================================================================================


