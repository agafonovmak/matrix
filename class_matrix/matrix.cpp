#include"matrix.h"
#include<iostream>
matrix::matrix()
{
	int n = 0;
	int m = 0;
	arr = NULL;
}
matrix::matrix(int n1, int m1)
{
	n = n1;
	m = m1;
	arr = new int*[n];
	for (int i = 0; i < n; i++)
	{
		arr[i] = new int[m];
	}
}
matrix matrix::operator+(matrix l)
{
	matrix rez(n,m);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			rez.arr[i][j] = arr[i][j] + l.arr[i][j];
		}
	}
	return rez;
}
void matrix::input(int* arr1)
{
	int c = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			arr[i][j] = arr1[c];
			c++;
		}
	}
}
void matrix::print()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
}
matrix matrix::operator*(matrix &a)
{
	matrix c(n,a.m);
	c.zero();
	if (m != a.n)
		throw 1;
	for (int k = 0; k < n; k++)
	for (int i = 0; i < a.m; ++i)
	for (int j = 0; j < a.n; ++j)
		c.arr[k][i] += arr[k][j] * a.arr[i][j];
	return c;
}
void matrix::zero()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			arr[i][j] = 0;
		}
	}
}
int* matrix::operator[](int i)
{
	return arr[i];
}