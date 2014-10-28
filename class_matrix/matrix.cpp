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
float matrix::determiner()
{
	float**tempmat = new float*[n];
	for (int i = 0; i < n; i++) tempmat[i] = new float[m];
	for (int i = 0; i < n; i++)
	for (int j = 0; j < m; j++)
		tempmat[i][j] = arr[i][j];

	if (n != m) throw 2;
	for (int k = 0; k < n; k++)
	{		//обнуляем элементы под главной диагональю матрицы mat
		float z = tempmat[k][k];
		for (int i = k; i < n; i++)
		{
			float num = tempmat[i][k];
			for (int j = k; j < n; j++)
			if (i != k)  tempmat[i][j] -= tempmat[k][j] * (num / z);
		}
	}
	float det = 1;								//вычисляем определитель
	for (int i = 0; i < n; i++) det *= tempmat[i][i];
	for (int i = 0; i < n; i++) delete tempmat[i];
	delete[]tempmat;
	return det;
}