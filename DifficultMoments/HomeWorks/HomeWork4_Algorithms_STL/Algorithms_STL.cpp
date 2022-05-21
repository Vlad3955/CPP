#include <iostream>
#include <ctime>
#include <cmath>
#include <string>
#include <vector>
#include <forward_list>
#include <list>
#include <array>
#include <algorithm>


using namespace std;

// Task 1
//========================================================
template<typename T, typename Container>
void insert_sorted(Container & arr, T num)
{
	auto it = lower_bound(arr.begin(), arr.end(), num);
	arr.insert(it, num);
}
//========================================================

// Task 2
//========================================================

//========================================================


int main()
{
	// Task 1
	//======================================================================
	/*vector<double> array1 = { 4, 8, 34, 2, 11, 1 };
	sort(array1.begin(), array1.end(), [](int n, int m) {return n < m; });
	for_each(array1.begin(), array1.end(), [](auto i) { cout << i << " "; });
	cout << endl;
	insert_sorted(array1, 2.2);
	for_each(array1.begin(), array1.end(), [](auto i) { cout << i << " "; });*/

	/*list<int> array2 = { 4, 8, 34, 2, 11, 1 };
	array2.sort();
	for_each(array2.begin(), array2.end(), [](auto i) { cout << i << " "; });
	cout << endl;
	insert_sorted(array2, 6);
	for_each(array2.begin(), array2.end(), [](auto i) { cout << i << " "; });*/
	//======================================================================

	// Task 2
	//======================================================================
	srand(time(NULL));
	vector<double> a(100);
	generate(a.begin(), a.end(), []() {return (rand() % 901 + 100) / 100.0;});
	cout << "Analog signal: " << endl;
	copy(a.begin(), a.end(), ostream_iterator<double>(cout, "|"));
	cout << endl << endl;
	// Variant with second vetor
	//===============================================================
	/*vector<int> b;
	copy(a.begin(), a.end(), back_inserter(b));
	cout << "Digital signal: " << endl;
	copy(b.begin(), b.end(), ostream_iterator<double>(cout, "|"));*/
	//===============================================================
	cout << "Digital signal: " << endl;
	copy(a.begin(), a.end(), ostream_iterator<int>(cout, "|"));
	cout << endl << endl;
	double error = 0;
	for_each(a.begin(), a.end(), [&](auto i) { error += pow(i - static_cast<int>(i), 2);});
	cout << "Error: " << error << endl;
	//======================================================================
	return 0;
}