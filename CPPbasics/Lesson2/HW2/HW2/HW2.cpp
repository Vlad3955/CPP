#include <iostream>

using namespace std;



int main() {
	// Task 1
	short int a = 5;
	int b = 350;
	long long c = 2000000;
	char d = 100;
	bool e = true;
	float f = 375.4f;
	double g = 577.9432;

	// Task 2
	enum CresticNolic
	{
		PUSTO,
		CRESTIC,
		NOLIC
	};

	// task 3
	//CresticNolic arr_crestNol[3][3] = { CRESTIC, NOLIC, PUSTO };
	// ниже 2й вариант.Не совсем понял условие
	//CresticNolic arr_crestNol[3][3] = { {CRESTIC, NOLIC, PUSTO}, {CRESTIC, NOLIC, PUSTO}, {CRESTIC, NOLIC, PUSTO}
	//};
	// И 3й вариант,как будто поле пустое.
	//CresticNolic arr_crestNol[3][3] = { {PUSTO, PUSTO, PUSTO}, {PUSTO, PUSTO, PUSTO}, {PUSTO, PUSTO, PUSTO} };


	// Task 4
	struct Player
	{
		char playerName1;// Имя игрока
		char gameItem;// чем играет 

	};


	struct Game
	{
		// array from Task 3
		CresticNolic arr_crestNol[3][3] = { {PUSTO, PUSTO, PUSTO}, {PUSTO, PUSTO, PUSTO}, {PUSTO, PUSTO, PUSTO} };
		bool isGameOver;
		bool whoWin;
		bool nobodyWin;
	};


	// Task 5
	union MyData
	{

		int one;
		float two;
		char three;
	};

	

	struct MyVariant
	{
		int isInt : 1;
		int isFloat : 1;
		int isChar : 1;



	};

	MyData too;
	too.two = 5;
	MyVariant foo;
	foo.isFloat = 1;
	foo.isChar = 0;
	foo.isInt = 0;
}