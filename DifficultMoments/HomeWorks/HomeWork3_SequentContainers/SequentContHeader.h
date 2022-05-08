#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <cmath>
#include <time.h>
#include <list>
#include <algorithm>

using namespace std;

// Task 2
class Matrix
{
public:
	Matrix();
	Matrix(int _n);
	void printMatrix();
	void determinant();
	~Matrix();
private:
	int col_max(vector<vector<float>>& _vec, int col, int _n);
	int triangulation(vector<vector<float>>& _vec, int _n);
	int n;
	vector<vector<float>> vec;
};



