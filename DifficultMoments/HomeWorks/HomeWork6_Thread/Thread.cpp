#include <iostream>
#include <algorithm>
#include <ctime>
#include <condition_variable>
#include <vector>
#include <string>
#include <thread>
#include <mutex>
#include <queue>
#include <chrono>


using namespace std;


// Task 1
//========================================================
mutex mtx_cout;

mutex sm;
condition_variable prime_plus;
queue<size_t> data_i;

mutex things;

class pcout
{
private:
	lock_guard<mutex> lg;
public:
	pcout() : lg(lock_guard<mutex>(mtx_cout))
	{
	}

	template<typename T>
	pcout& operator<<(const T& data)
	{
		cout << data;
		return *this;
	}

	pcout& operator<<(ostream& (*fp)(ostream&))               
	{                                                                   
		cout << fp;                                               
		return *this;                                                  
	}                                                                    
};

void doSomething(int number)
{
	pcout() << "start thread " << number << endl;
	pcout() << "stop thread " << number << endl;
}
//========================================================

// Task 2
//========================================================
void progress(size_t n)
{
	size_t t = 0;
	while (t < n)   //прогресс нахождения простого числа
	{
		std::unique_lock<std::mutex> lk(sm);
		prime_plus.wait(lk, [] { return !data_i.empty(); });
		size_t tmp = data_i.front();
		data_i.pop();
		if (t < tmp)
		{
			t = tmp;
			std::cout << (t * 100 / static_cast<double>(n)) << "%\t";
		}
		lk.unlock();
	}
}

size_t isPrime(size_t n)   //массив простых чисел и номер простого числа, которое нужно найти
{
	size_t num = n;   // число элементов для массива чисел
	size_t* numbers = new size_t[num];   // массив для чисел
	size_t* primes = new size_t[n+1];   //массив простых чисел

	for (size_t i = 0; i < num; ++i)
		numbers[i] = i;

	primes[0] = 2;   // первое простое число
	size_t ind = 0;   // индекс текущего простого числа

	while (ind < n) {
		size_t p = primes[ind++];   // запоминаем текущее простое число
		std::lock_guard<std::mutex> lk(sm);
		data_i.push(ind + 1);

		for (size_t j = p * 2; j < num; j += p)
			numbers[j] = 0;   // обнуляем все кратные ему числа в массиве

		while (numbers[p + 1] == 0)
			p++; // ищем следующее ненулевое число

		prime_plus.notify_all();

		if (p + 1 >= num)   // если выйдем за границы, расширяем массив
		{
			size_t* tmp = new size_t[num * 2];

			for (size_t k = 0; k < num; k++)
				tmp[k] = numbers[k];

			delete[] numbers;

			num *= 2;
			numbers = tmp;

			for (size_t j = num / 2; j < num; j++)   // заполняем новую часть массива числами
				numbers[j] = j;

			ind = 0;   // возвращаемся к начальной стадии просеивания
		}
		else
		{
			primes[ind] = p + 1;   // запоминаем новое простое число
		}

	}
	size_t res = primes[n - 1];
	delete[] numbers;
	delete[] primes;
	return res;
}
//========================================================

// Task 3
//========================================================
void fillVec(vector<int> &v)
{
	srand(time(NULL));
	generate(v.begin(), v.end(), [&]() {return rand() % 1000; });
}


void putThing(vector<int>& vec)
{
	while (!vec.empty())
	{
		this_thread::sleep_for(chrono::milliseconds(1000));

		srand(time(NULL));

		lock_guard lkt(things);
		vec.push_back(rand() % 1000);
		cout << endl << "Owner put " << *(vec.end() - 1) << endl;
		ostream_iterator<int> o_it = { cout, " | " };
		copy(vec.begin(), vec.end(), o_it);
		cout << endl;
	}
	exit(0);
}


void takeThing(vector<int>& vec)
{
	while (!vec.empty())
	{
		this_thread::sleep_for(chrono::milliseconds(500));

		lock_guard lkt(things);
		auto it = max_element(vec.begin(), vec.end());
		cout << endl << "Thief took " << *it << endl;
		vec.erase(it);
		ostream_iterator<int> o_it = { cout, " | " };
		copy(vec.begin(), vec.end(), o_it);
		cout << endl;
	}
	exit(0);
}
//========================================================

int main()
{
	// Task 1
	//======================================================================
	/*thread th1(doSomething, 1);
	thread th2(doSomething, 2);
	thread th3(doSomething, 3);
	th1.join();
	th2.join();
	th3.join();*/
	//======================================================================

	// Task 2
	//======================================================================
	/*size_t n;
	cout << "Enter number of prime number: ";
	cin >> n;
	size_t result = 0;
	thread primeNum([&] { result = isPrime(n); });

	thread main(progress, n);


	primeNum.join();
	main.join();
	cout << endl << "This prime number is " << result << endl;*/
	//=======================================================================

	// Task 
	//======================================================================
	vector<int> vec(10);
	ostream_iterator<int> o_it = { cout, " | " };
	fillVec(vec);
	copy(vec.begin(), vec.end(), o_it);


	

	thread owner(putThing, ref(vec));
	thread thief(takeThing, ref(vec));
	owner.join();
	thief.join();
	//=======================================================================
	return 0;
}