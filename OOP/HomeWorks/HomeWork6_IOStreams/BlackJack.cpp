#include "BlackJack.h"
#include <iostream>

// class Cards
//==================================================================================
Cards::Cards(cardValue v, Suit s, bool cardSt) : cValue(v), suit(s), cardStatus(cardSt) {}
void Cards::flip()
{
	cardStatus = !(cardStatus);
}
int Cards::getValue() const
{
	int value = 0;
	if (cardStatus)
	{
		value = cValue;
	}
	return value;
}

// Task 5.1
ostream& operator<< (ostream& out, const Cards& cards)
{
	const string cardVal[] = { "0", "A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K" };
	const string cardSuits[] = { "c", "d", "h", "s" };
	if (cards.cardStatus)
	{
		out << cardVal[cards.cValue] << " " << cardSuits[cards.suit];
	}
	else
	{
		out << "XX";
	}
	return out;
}
//==================================================================================

// class Hand
//==================================================================================
Hand::Hand()
{
	cards.reserve(7);
}
Hand::~Hand()
{
	Clear();
}
void Hand::Add(Cards* nCard)
{
	cards.push_back(nCard);
}
void Hand::Clear()
{
	vector<Cards*>::iterator it = cards.begin();
	for (it = cards.begin(); it != cards.end(); it++)
	{
		delete *it;
		*it = 0;
	}
	cards.clear();
}
int Hand::getTotal() const
{
	if (cards.empty())
	{
		return 0;
	}
	
	if (cards[0]->getValue() == 0)
	{
		return 0;
	}

	int total = 0;

	vector<Cards*>::const_iterator it;
	for (it = cards.begin(); it != cards.end(); it++)
	{
		total += (*it)->getValue();
	}

	bool isAce = false;
	for (it = cards.begin(); it != cards.end(); it++)
	{
		if ((*it)->getValue() == Cards::ACE)
		{
			isAce = true;
		}
	}

	if (isAce && total <= 11)
	{
		total += 10;
	}

	return total;
}
//==================================================================================

// class GenericPlayer
//==================================================================================
GenericPlayer::GenericPlayer(const string &n) : name(n) {}
GenericPlayer::~GenericPlayer() {}
bool GenericPlayer::isBusted() const
{
	return (getTotal() > 21);
}
void GenericPlayer::Bust() const
{
	cout << name << " busts" << endl;
}

// Task 5.2
ostream& operator<< (ostream& out, const GenericPlayer& genPlayer)
{
	out << genPlayer.name << ":\t";
	vector<Cards*>::const_iterator pCard;
	if (!genPlayer.cards.empty())
	{
		for (pCard = genPlayer.cards.begin(); pCard != genPlayer.cards.end(); ++pCard)
		{
			out << *(*pCard) << "\t";
		}

		if (genPlayer.getTotal() != 0)
		{
			cout << "(" << genPlayer.getTotal() << ")";
		}
	}
	else
	{
		out << "<empty>";
	}
	return out;
}
//==================================================================================

//Task 3
// class Player
//==================================================================================
Player::Player(const string& n) {}
bool Player::IsHitting() const 
{
	char y;
	cout << "Click 'y' if you need a card, else 'n', and click enter: " << endl;
	cin >> y;
	return (y == 'y' || y == 'Y');
}
void Player::Win() const 
{
	cout << "Player " << this->name << "wins!" << endl;
}
void Player::Lose() const 
{
	cout << "Player " << this->name << "loses!" << endl;
}
void Player::Push() const 
{
	cout << "Player " << this->name << "pushes!" << endl;
}
//==================================================================================

//Task 4
// class House
//==================================================================================
House::House(const string& n) {}
House::~House() {}
bool House::IsHitting() const
{
	return (getTotal() <= 16);
}
void House::FlipFirstCard()
{
	if (!(cards.empty()))
	{
		cards[0]->flip();
	}
	else
	{
		cout << "No card to flip!\n";
	}
}
//==================================================================================