#include<stdio.h>
#include<string.h>
#define maxn 1005
#define LOCAL
int s[maxn][32];

void read (char t[], int k)
{
	void trans (int, int*);
	char *p = t;
	int i, a;
	for (i = 1; i <= 4; i++)
	{
		a = 0;
		while (*p != '.' && *p != '\0')
		{
			a = a * 10 + *p - '0';
			p++;
		}
		trans (a, s[k] + 8 * i - 1);
		p++;
	}
	return;
}

void trans (int a, int *p)
{
	int i;
	for (i = 0; i < 8; i++)
	{
		*p = a % 2;
		a /= 2;
		p--;
	}
	return;
}

void rev (int u[], int v[])
{
	int a, i, j;
	for (i = 0; i < 4; i++)
	{
		a = 0;
		for (j = 0; j < 8; j++)
		{
			a = a * 2 + u[8 * i + j];
		}
		v[i] = a;
	}
	return;
}

int main()
{
	int n, i, j, k, flag, u[32], v[4];
	char t[40];
#ifdef LOCAL
	freopen ("D:/in.txt", "r", stdin);
	freopen ("D:/out.txt", "w", stdout);
#endif
	while (scanf ("%d", &n) != EOF && n)
	{
		memset (t, '\0', sizeof (t));
		for (i = 0; i < n; i++)
		{
			scanf ("%s", t);
			read (t, i);
		}
		k = 32;
		for (i = 0; i < 32; i++)
		{
			flag = 1;
			for (j = 1; j < n; j++)
			{
				if (s[j][i] != s[0][i])
				{
					flag = 0;
					k = i;
					break;
				}
			}
			if (flag)
				continue;
			else
				break;
		}
		memset (u, 0, sizeof (u));
		for (i = 0; i < k; i++)
			u[i] = s[0][i];
		rev (u, v);
		printf ("%d.%d.%d.%d\n", v[0], v[1], v[2], v[3]);
		memset (u, 0, sizeof (u));
		for (i = 0; i < k; i++)
			u[i] = 1;
		rev (u, v);
		printf ("%d.%d.%d.%d\n", v[0], v[1], v[2], v[3]);
	}
	return 0;
}