#include "SequentContHeader.h"


// Task 2
Matrix::Matrix()
{
	n = 0;
}

Matrix::Matrix(int _n) : n(_n), vec(_n, vector<float>(_n))
{
	srand(time(NULL));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			vec[i][j] = rand() % 15;
		}
	}
}

int Matrix::col_max(vector<vector<float>>& _vec, int col, int _n)
{
	float max = abs(_vec[col][col]);
	int maxPos = col;
	for (int i = col + 1; i < _n; i++)
	{
		int element = abs(_vec[i][col]);
		if (element > max)
		{
			max = element;
			maxPos = i;
		}
	}
	return maxPos;
}

int Matrix::triangulation(vector<vector<float>>& _vec, int _n)
{
	int swapCount = 0;
	for (int i = 0; i < n - 1; i++)
	{
		int imax = col_max(_vec, i, n);
		if (i != imax)
		{
			swap(_vec[i], _vec[imax]);
			++swapCount;
		}
		for (int j = i + 1; j < n; j++)
		{
			float mul = -_vec[j][i] / _vec[i][i];
			for (int k = i; k < n; k++)
			{
				_vec[j][k] += _vec[i][k] * mul;
			}
		}
	}
	return swapCount;

	/*int swapCount = 0;
	if (0 == n)
	{
		return swapCount;
	}
	const int num_cols = _vec[0].size();
	for (int i = 0; i < n - 1; i++)
	{
		int imax = col_max(_vec, i, n);
		if (i != imax)
		{
			swap(_vec[i], _vec[imax]);
			++swapCount;
		}

		for (int j = i + 1; j < n; j++)
		{
			float mul = -_vec[j][i] / _vec[i][i];
			for (int k = i; k < num_cols; k++)
			{
				_vec[j][k] += _vec[i][k] * mul;
			}
		}
	}
	return swapCount;*/
}

void  Matrix::determinant()
{
	if (n == 1)
	{
		cout << vec[0][0];
	}
	else if (n == 2)
	{
		int sum = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				sum = (vec[0][0] * vec[1][1]) - (vec[1][0] * vec[0][1]);
			}
		}
		cout << "Detrminant of matrix size 2x2: " << sum << endl;
	}
	else
	{
		int swapCount = triangulation(vec, n);
		int determinanit = 1;
		if (swapCount % 2 == 1)
		{
			determinanit = -1;
		}
		for (int i = 0; i < n; i++)
		{
			determinanit *= vec[i][i];
		}
		cout << "Detrminant of matrix size 2x2: " << determinanit << endl;
	}
}

void Matrix::printMatrix()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << vec[i][j] << " ";
		}
		cout << "\n";
	}
}

Matrix::~Matrix()
{
}
