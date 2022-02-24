#include "BlackJack.h"
#include <iostream>

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

GenericPlayer::GenericPlayer(string n) : name(n) {}
bool GenericPlayer::isBoosted()
{
	if (getValue() > 21)
	{
		return true;
	}
	else
	{
		return false;
	}
}
void GenericPlayer::Bost()
{
	cout << name << " ";
	if (isBoosted())
	{
		cout << "boosted" << endl;
	}
}
//==================================================================================