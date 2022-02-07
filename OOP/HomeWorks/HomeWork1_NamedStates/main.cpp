#include <iostream>
#include <cstdint>
#include <cmath>

using namespace std;

class Power
{
public:
	void setFloat(float o, float t)
	{
		one = o;
		two = t;
	}
	void calculate()
	{
		cout << pow(one, two) << endl;
	}
private:
	float one = 3.0;
	float two = 2.0;
};


class RGBA
{
public:
	RGBA(uint8_t red = 0, uint8_t green = 0, uint8_t blue = 0, uint8_t alpha = 255)
	{
		//setRGBA(red, green, blue, alpha);
		m_red = red;
		m_green = green;
		m_blue = blue;
		m_alpha = alpha;
	}
	/*void setRGBA(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha)
	{
		m_red = red;
		m_green = green;
		m_blue = blue;
		m_alpha = alpha;
	}*/
	void print()
	{
		cout << static_cast<unsigned int>(m_red) << endl
			 << static_cast<unsigned int>(m_green) << endl
			 << static_cast<unsigned int>(m_blue) << endl
			 << static_cast<unsigned int>(m_alpha) << endl;
	}

private:
	uint8_t m_red, m_green, m_blue, m_alpha;
};


class Stack
{
public:
	void reset()
	{
		count = 0;
		for (int i = 0; i < 10; i++)
		{
			arr[i] = 0;
		}
	}
	bool push(int value)
	{
		if (count == 10)
		{
			return false;
		}
		arr[count++] = value;
		return true;
	}
	int pop()
	{
		if (count == 0)
		{
			cout << "is empty" << endl;
		}
		return arr[--count];
	}
	void print()
	{
		cout << "(";
		for (int i = 0; i < count; i++)
		{
			cout << arr[i] << ' ';
		}
		cout << ")" << endl;
	}

private:
	int arr[10];
	int count;
};





int main()
{
	//Power powNumbers;
	//powNumbers.calculate();

	//RGBA rgba;
	//rgba.print();

	Stack stack;
	stack.reset();
	stack.print();

	stack.push(3);
	stack.push(7);
	stack.push(5);
	stack.print();

	stack.pop();
	stack.print();

	stack.pop();
	stack.pop();
	stack.print();
	return 0;
}