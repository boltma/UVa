#include <cctype>
#include <cstring>
#include <iostream>
#include <string>
#define LOCAL
using namespace std;

int m[4000005][11]; //字典树，m[k][10]表斐波那契数的下标，m[k][i] i<10表明下一个结点的行下标

int search(string s)
{
	int i = 0, u = 0;
	for (auto it = s.begin(); it != s.end() && i < 40; ++it, ++i)
	{
		int k = *it - '0';
		if (!isdigit(*it))
			return -1;
		if (!i)
			u = k;
		else
			u = m[u][k];
		if (u == -1)
			return -1;
	}
	return m[u][10];
}

void set(string s, const int n, int &end)
{
	int i = 0, u;
	for (auto it = s.rbegin(); it != s.rend() && i < 40; ++it, ++i)
	{
		int k = *it - '0';
		if (!isdigit(*it))
			return;
		if (!i)
		{
			u = k;
			if (m[u][10] == -1)
				m[u][10] = n;
		}
		else
		{
			if (m[u][k] == -1)
			{
				m[u][k] = ++end;
				m[end][10] = n;
			}
			u = m[u][k];
		}
	}
	return;
}

void add(string &a, string &b)
{
	int k = 0;
	a.append(b.length() - a.length(), '0');
	for (int i = 0; i < a.length(); ++i)
	{
		int n = a[i] + b[i] + k - 2 * '0';
		k = n / 10;
		a[i] = n % 10 + '0';
	}
	if (k == 1)
		a.push_back('1');
	return;
}

int main()
{
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int kase, end = 9;
	string a = "1", b = "1";
	memset(m, -1, sizeof(m));
	set(a, 0, end);
	set(a, 1, end);
	for (int i = 2; i < 100000; ++i)
	{
		if (i % 2)
		{
			add(b, a);
			set(b, i, end);
		}
		else
		{
			add(a, b);
			set(a, i, end);
		}
	}
	cin >> kase;
	for (int i = 1; i <= kase; ++i)
	{
		string s;
		cin >> s;
		cout << "Case #" << i << ": " << search(s) << endl;
	}
	return 0;
}