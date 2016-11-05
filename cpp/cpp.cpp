#include "stdafx.h"
#include <stdio.h>
#include <Windows.h>
#include <omp.h>
#include <iostream>
using namespace std;
#define N 5
int a[N][N];
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int x, y;
	cout << "количество строк - ";
	cin >> x;
	cout << "количество столбцов - ";
	cin >> y;
	int i, j, k;
	double t1, t2;

	for (i = 0; i <= x; i++)
		for (j = 0; j <= y; j++)
			a[i][j] = rand() % 100;
	t1 = omp_get_wtime();

	std::cout << "massiv:";
	for (i = 0; i < x; i++)
	{
		std::cout << "\n";
		for (j = 0; j < y; j++)       //вывод исходного массива
			std::cout << a[i][j] << " ";;
	}
	int min = a[0][0];
	int max = a[0][0];
#pragma omp for
	for (i = 0; i < x; ++i)
	{
		for (int j = 0; j < y; j++)
		{
			if (a[i][j] <= min) min = a[i][j];
			if (a[i][j] > max) max = a[i][j];
		}
	}
	cout << "\nmin - " << min;
	cout << "\nmax - " << max << "\n";
}

