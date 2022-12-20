#include <iostream>
#include <fstream>
using namespace std;

int Add_Matrix(int x, int y, int matrix[100][100])
{
	ifstream in("input.txt");
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			in >> matrix[i][j];
		}
	}
	in.close();
	return matrix[x][y];
}

bool Equal_Lines(int x, int y, int matrix[100][100])
{
	int count = 0;
	for (int i = 0; i < y - 1; i++)
	{
		for (int k = 1; k < y; k++)
		{
			count = 0;
			for (int j = 0; j < x; j++)
			{
				if (matrix[i][j] != matrix[i + k][j])
				{
					continue;
				}
				else
				{
					count++;
				}
			}
			if (count == x)
			{
				return true;
			}
		}
	}
	return false;
}

bool is_Prime(int x)
{
		for (int i = 1; i < sqrt(x); i++)
		{
			if (i > 1)
			{
				if (x % i == 0)
				{
					return false;
				}
			}
		}
	return true;
}

int Max_Prime(int x, int y, int matrix[100][100])
{
	int max = INT_MIN;
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			if (is_Prime(matrix[i][j]))
			{
				if (matrix[i][j] > max)
				{
					max = matrix[i][j];
				}
			}
		}
	}
	return max;
}

void Changing_Elements(int x, int y, int matrix[100][100])
{
	int* min_numbers[100];
	int min = INT_MAX;
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			if (matrix[j][i] < min)
			{
				min = matrix[j][i];
				min_numbers[i] = &matrix[j][i];
			}
		}
		min = INT_MAX;
	}

	for (int i = 0; i < y; i++)
	{
		int temp = Max_Prime(x, y, matrix);
		*min_numbers[i] = temp;
	}
}

int main()
{
	setlocale(LC_ALL, "rus");
	int matrix[100][100];
	int x, y;
	cin >> x;
	cin >> y;

	Add_Matrix(x, y, matrix);

	if (Equal_Lines(x, y, matrix))
	{
		Changing_Elements(x, y, matrix);
	}
	else
	{
		cout << "false" << endl;
	}

	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
}

/*
int plus(int a, int b)
	{
		return a + b;
	}
	double plus(double a, double b)
	{
		return a + b;
	}
	int plus(int a, int b, int z)
	{
		return a + b + z;
	}
	

void plus1(int x)
{
	x += 10;
}
void plus2(int& x);
{
	x = x + 10;
}
*/
