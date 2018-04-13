#include<stdio.h>
#include<string.h>
#include<time.h>
#define maxn 100
#define BIG 10000
#define LOCAL
int r, c, n, d[maxn][maxn], com[maxn];

void add (char flag)
{
	int n, a, i, j, count, s = 0;
	memset (com, 0, sizeof (com));
	scanf ("%d", &n);
	for (i = 1; i <= n; i++)
		scanf ("%d", &com[i]);
	while (n--)
	{
		count = 0;
		for (i = 1; i <= s; i++)
			if (com[i] < com[s + 1])
				count++;
		a = com[s + 1] + count;
		if (flag == 'R')
		{
			for (i = 1; i <= r; i++)
				for (j = 1; j <= c; j++)
					if (d[i][j] && d[i][j] / BIG >= a)
						d[i][j] += BIG;
		}
		if (flag == 'C')
		{
			for (i = 1; i <= r; i++)
				for (j = 1; j <= c; j++)
					if (d[i][j] && d[i][j] % BIG >= a)
						d[i][j]++;
		}
		s++;
	}
	return;
}

void del (char flag)
{
	int n, a, i, j, s = 0, count;
	memset (com, 0, sizeof (com));
	scanf ("%d", &n);
	for (i = 1; i <= n; i++)
		scanf ("%d", &com[i]);
	while (n--)
	{
		count = 0;
		for (i = 1; i <= s; i++)
			if (com[i] < com[s + 1])
				count++;
		a = com[s + 1] - count;
		if (flag == 'R')
		{
			for (i = 1; i <= r; i++)
				for (j = 1; j <= c; j++)
				{
					if (d[i][j] && d[i][j] / BIG >= a + 1)
						d[i][j] -= BIG;
					else if (d[i][j] && d[i][j] / BIG == a)
						d[i][j] = 0;
				}
		}
		if (flag == 'C')
		{
			for (i = 1; i <= r; i++)
				for (j = 1; j <= c; j++)
				{
					if (d[i][j] && d[i][j] % BIG >= a + 1)
						d[i][j]--;
					else if (d[i][j] && d[i][j] % BIG == a)
						d[i][j] = 0;
				}
		}
		s++;
	}
	return;
}

void swap()
{
	int r1, c1, r2, c2, i1, j1, i2, j2, i, j;
	scanf ("%d%d%d%d", &r1, &c1, &r2, &c2);
	i1 = i2 = j1 = j2 = 0;
	for (i = 1; i <= r; i++)
	{
		for (j = 1; j <= c; j++)
		{
			if (d[i][j] == r1 * BIG + c1)
			{
				i1 = i;
				j1 = j;
			}
		}
	}
	for (i = 1; i <= r; i++)
	{
		for (j = 1; j <= c; j++)
		{
			if (d[i][j] == r2 * BIG + c2)
			{
				i2 = i;
				j2 = j;
			}
		}
	}
	d[i1][j1] = r2 * BIG + c2;
	d[i2][j2] = r1 * BIG + c1;
	return;
}

void command()
{
	char c;
	for (;;)
	{
		c = getchar();
		if (c == 'E')
		{
			getchar();
			swap();
			return;
		}
		if (c == 'D')
		{
			c = getchar();
			del (c);
			return;
		}
		if (c == 'I')
		{
			c = getchar();
			add (c);
			return;
		}
	}
}

int main()
{
	int kase = 0, i, j, q;
#ifdef LOCAL
	freopen ("D:/in.txt", "r", stdin);
	freopen ("D:/out.txt", "w", stdout);
#endif
	while (scanf ("%d%d", &r, &c) == 2 && r)
	{
		scanf ("%d", &n);
		if (kase++)
			printf ("\n");
		printf ("Spreadsheet #%d\n", kase);
		memset (d, 0, sizeof (d));
		for (i = 1; i <= r; i++)
			for (j = 1; j <= c; j++)
				d[i][j] = i * BIG + j;
		while (n--)
			command();
		scanf ("%d", &q);
		while (q--)
		{
			scanf ("%d%d", &i, &j);
			printf ("Cell data in (%d,%d) ", i, j);
			if (d[i][j])
				printf ("moved to (%d,%d)\n", d[i][j] / BIG, d[i][j] % BIG);
			else
				printf ("GONE\n");
		}
	}
	printf ("%lf", (double) clock() / CLOCKS_PER_SEC);
	return 0;
}