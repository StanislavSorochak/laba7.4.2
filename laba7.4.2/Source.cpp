// Lab_7_4_2.cpp
// < Сорочак Станіслав >
// Лабораторна робота № 7.4.2
//Рекурсивний спосіб, Завдання 2
// Варіант 24
#include <iostream>
#include <Windows.h>
#include <iomanip>

void Create(int** a, const int rowCount, const int colCount, int i, int j);
void Print(int** a, const int rowCount, const int colCount, int i, int j);
void Sidlova(int** a, const int rowCount, const int colCount, int i, int j, int* masuv_min, int min);
void Sidlova1(int** a, const int rowCount, const int colCount, int i, int j, int* masuv_max, int max);
void Sidlova2(int** a, const int rowCount, const int colCount, int i, int j, int* masuv_min, int* masuv_max);

int main(void)
{
	srand((unsigned)time(NULL));

	using std::cout;
	using std::endl;
	using std::cin;

	int rowCount = 2;
	int colCount = 2;

	int** a = new int* [rowCount];
	for (int i = 0; i < rowCount; i++)
		a[i] = new int[colCount];

	Create(a, rowCount, colCount, 0, 0);
	Print(a, rowCount, colCount, 0, 0);
	cout << endl << endl;

	int* masuv_min = new int[rowCount];
	int* masuv_max = new int[colCount];

	Sidlova(a, rowCount, colCount, 0, 1, masuv_min, a[0][0]);
	Sidlova1(a, rowCount, colCount, 1, 0, masuv_max, a[0][0]);
	Sidlova2(a, rowCount, colCount, 0, 0, masuv_min, masuv_max);

	delete[] a;
	delete[] masuv_min;
	delete[] masuv_max;

	return 0;
}

void Create(int** a, const int rowCount, const int colCount, int i, int j)
{
	using std::cout;
	using std::endl;
	using std::cin;
	cout << "a[" << i << "][" << j << "] = ";
	cin >> a[i][j];
	if (j < colCount - 1)
		Create(a, rowCount, colCount, i, j + 1);
	else
		if (i < rowCount - 1)
		{
			cout << endl;
			Create(a, rowCount, colCount, i + 1, 0);
		}
		else
			cout << endl;
}

void Print(int** a, const int rowCount, const int colCount, int i, int j)
{
	using std::cout;
	using std::endl;
	cout << std::setw(4) << a[i][j];
	if (j < colCount - 1)
		Print(a, rowCount, colCount, i, j + 1);
	else
		if (i < rowCount - 1)
		{
			cout << endl;
			Print(a, rowCount, colCount, i + 1, 0);
		}
}

void Sidlova(int** a, const int rowCount, const int colCount, int i, int j, int* masuv_min, int min)
{
	using std::cout;
	using std::endl;

	if ((i == 0 || i == 1 || i == 2) && j == 1)
		masuv_min[i] = a[i][0];

	if (min > a[i][j])
	{
		min = a[i][j];
		masuv_min[i] = a[i][j];
	}

	if (j < colCount - 1)
		Sidlova(a, rowCount, colCount, i, j + 1, masuv_min, min);
	else
		if (i < rowCount - 1)
			Sidlova(a, rowCount, colCount, i + 1, 1, masuv_min, a[i + 1][0]);
		else;
}
void Sidlova1(int** a, const int rowCount, const int colCount, int i, int j, int* masuv_max, int max)
{
	if ((j == 0 || j == 1 || j == 2) && i == 1)
		masuv_max[j] = a[0][j];

	if (max < a[i][j])
	{
		max = a[i][j];
		masuv_max[j] = a[i][j];
	}

	if (i < colCount - 1)
		Sidlova1(a, rowCount, colCount, i + 1, j, masuv_max, max);
	else
		if (j < rowCount - 1)
			Sidlova1(a, rowCount, colCount, 1, j + 1, masuv_max, a[0][j + 1]);
		else;
}
void Sidlova2(int** a, const int rowCount, const int colCount, int i, int j, int* masuv_min, int* masuv_max)
{
	using std::cout;
	using std::endl;

	if (masuv_min[i] == masuv_max[j])
	{
		cout << "S_point:" << masuv_min[i] << endl;
		a[i][j] = 0; //Для юніт-тесту.
	}
	else;

	if (j < colCount - 1)
		Sidlova2(a, rowCount, colCount, i, j + 1, masuv_min, masuv_max);
	else
		if (i < rowCount - 1)
			Sidlova2(a, rowCount, colCount, i + 1, 0, masuv_min, masuv_max);
		else;
}
