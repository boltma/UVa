#include <iostream>
#include <math.h>
using namespace std;

void eliminate(int **, int, int, int&);
void swap(int* &, int* &, int&);

int main()
{
	int n, cnt;
	while (cin >> n && n)
	{
		int** a = new int*[n], val = 1;
		cnt = 0;
		for (int i = 0; i < n; ++i)
			a[i] = new int[n];
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				cin >> a[i][j];
		for (int i = 0; i < n - 1; i++)
			eliminate(a, n, i, cnt);
		for (int i = 0; i < n; i++)
			val *= a[i][i];
		cout << (cnt % 2 ? -val : val) << endl;
		for (int i = 0; i < n; i++)
			delete []a[i];
		delete []a;
	}
	cout << "*" << endl;
}

void eliminate(int **a, int n, int m, int &cnt)
{
	int c, min, imin;
	if (!a[m][m])
	{
		int i = m + 1;
		while (i < n && !a[i][m]) ++i;
		if (i == n)
			return;
		swap(a[m], a[i], cnt);
	}
	min = a[m][m];
	//辗转相除
	while (true)
	{
		imin = -1;
		for (int i = m + 1; i < n; ++i)
		{
			c = a[i][m] / a[m][m];
			for (int j = 0; j < n; ++j)
				a[i][j] -= a[m][j] * c;
			if (a[i][m] && abs(a[i][m]) < abs(min))
			{
				min = a[i][m];
				imin = i;
			}
		}
		if (imin == -1)
			break;
		swap(a[imin], a[m], cnt);
	}
	return;
}

void swap(int* &a, int* &b, int &cnt)
{
	//直接交换行指针
	int *p;
	p = a;
	a = b;
	b = p;
	++cnt;
	return;
}