#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;
void Create(int** a, const int rowCount, const int colCount, const int Low,
	const int High);
void Print(int** a, const int rowCount, const int colCount);
void Sort(int** a, const int rowCount, const int colCount);
void Change(int** a, const int row1, const int row2, const int colCount);
void Calc(int** a, const int rowCount, const int colCount, int& S, int& k);
int main()
{
	srand((unsigned)time(NULL));
	int Low = -6;
	int High = 31;
	int rowCount = 7;
	int colCount = 5;
	int** a = new int* [rowCount];
	for (int i = 0; i < rowCount; i++)
		a[i] = new int[colCount];
	Create(a, rowCount, colCount, Low, High);
	Print(a, rowCount, colCount);
	Sort(a, rowCount, colCount);
	Print(a, rowCount, colCount);
	for (int i = 0; i < rowCount; i++)
		delete[] a[i];
	delete[] a;
	return 0;
}
void Create(int** a, const int rowCount, const int colCount, const int Low,
	const int High)
{
	for (int i = 0; i < rowCount; i++)
		for (int j = 0; j < colCount; j++)
			a[i][j] = Low + rand() % (High - Low + 1);
}
void Print(int** a, const int rowCount, const int colCount)
{
	cout << endl;
	for (int i = 0; i < rowCount; i++)
	{
		for (int j = 0; j < colCount; j++)
			cout << setw(4) << a[i][j];
		cout << endl;
	}
	cout << endl;
}
void Sort(int** a, const int rowCount, const int colCount)
{
	for (int i0 = 0; i0 < colCount - 1; i0++)
		for (int i1 = 0; i1 < colCount - i0 - 1; i1++)
			if ((a[0][i1] > a[0][i1 + 1]) // зростання
				||
				(a[0][i1] == a[0][i1 + 1] &&
					a[1][i1] > a[1][i1 + 1]) // зростання
				||
				(a[0][i1] == a[0][i1 + 1] &&
					a[1][i1] == a[1][i1 + 1] &&
					a[3][i1] < a[3][i1 + 1])) // спадання
				Change(a, i1, i1 + 1, rowCount);
}
void Change(int** a, const int col1, const int col2, const int rowCount)
{
	int tmp;
	for (int j = 0; j < rowCount; j++)
	{
		tmp = a[j][col1];
		a[j][col1] = a[j][col2];
		a[j][col2] = tmp;
	}
}
