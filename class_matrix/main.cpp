#include"matrix.h"
#include<iostream>
int main()
{
	matrix a(2,2);
	matrix b(2, 2);
	matrix c(2,2);
	int arr[4] = { 1, 2, 3, 4 };
	int arr2[4] = { 5, 6, 7, 8 };
	a.input(arr);
	b.input(arr2);
	//a.print();
	//b.print();
	c = a*b;
	//c.print();
	printf("%d", a[1][1]);
}