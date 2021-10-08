#include <iostream>
#include <ctime>
#include <cmath>


using namespace std;

double foo(double p1, double p2)
{
	return 1 - pow(1 - (1 - p1) * p2, 2);
}

int main()
{
	srand(time(0));
	double p1, p2, P = 0.0;
	while (P <= 0.8)
	{
		p1 = (double)rand() / (double)RAND_MAX;
		p2 = (double)rand() / (double)RAND_MAX;
		P = foo(p1, p2);
		cout << "p1 = " << p1 << endl << "p2 = " << p2 << endl << "P = " << P << endl << endl;
	}

	system("pause");
}