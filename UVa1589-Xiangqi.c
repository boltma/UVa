/*注意本题中开始时对将红不输！*/

#include <math.h>
#include <stdio.h>
#include <string.h>
#define BIG 100
/*#define LOCAL*/
char s[15][15], s2[15][15];
int u, v, u1, v1, r[10];

/* return 1 checked by c, return 0 not check*/
int judge (char c, int r)
{
	int a, b, i, count = 0;
	a = r / BIG;
	b = r % BIG;
	switch (c)
	{
	case 'K':
		return 0;
	case 'G':
		if (v1 == b)
		{
			for (i = a - 1; i > u1; i--)
				if (s2[i][b] != 0)
					return 0;
			return 1;
		}
		return 0;
	case 'R':
		if (v1 == b || u1 == a)
		{
			if (v1 == b)
			{
				if (u1 < a)
				{
					for (i = a - 1; i > u1; i--)
						if (s2[i][b] != 0)
							return 0;
				}
				else
				{
					for (i = u1 - 1; i > a; i--)
						if (s2[i][b] != 0)
							return 0;
				}
				return 1;
			}
			if (u1 == a)
			{
				if (v1 < b)
				{
					for (i = b - 1; i > v1; i--)
						if (s2[a][i] != 0)
							return 0;
				}
				else
				{
					for (i = v1 - 1; i > b; i--)
						if (s2[a][i] != 0)
							return 0;
				}
				return 1;
			}
		}
		return 0;
	case 'C':
		if (v1 == b || u1 == a)
		{
			if (v1 == b)
			{
				if (u1 < a)
				{
					for (i = a - 1; i > u1; i--)
						if (s2[i][b] != 0)
							count++;
				}
				else
				{
					for (i = u1 - 1; i > a; i--)
						if (s2[i][b] != 0)
							count++;
				}
			}
			if (u1 == a)
			{
				if (v1 < b)
				{
					for (i = b - 1; i > v1; i--)
						if (s2[a][i] != 0)
							count++;
				}
				else
				{
					for (i = v1 - 1; i > b; i--)
						if (s2[a][i] != 0)
							count++;
				}
			}
			if (count == 1)
				return 1;
			else
				return 0;
		}
		return 0;
	case 'H':
		if (u1 == a - 2 && abs (v1 - b) == 1)
		{
			if (s2[a - 1][b] == 0)
				return 1;
			else
				return 0;
		}
		if (u1 == a + 2 && abs (v1 - b) == 1)
		{
			if (s2[a + 1][b] == 0)
				return 1;
			else
				return 0;
		}
		if (v1 == b - 2 && abs (u1 - a) == 1)
		{
			if (s2[a][b - 1] == 0)
				return 1;
			else
				return 0;
		}
		if (v1 == b + 2 && abs (u1 - a) == 1)
		{
			if (s2[a][b + 1] == 0)
				return 1;
			else
				return 0;
		}
		return 0;
	}
	return 0;
}

/* return 1 check or can't go, return 0 not check */
int simulate (int a, int b)
{
	int i;
	char c;
	u1 = u + a;
	v1 = v + b;
	memcpy (s2, s, sizeof (s2));
	if (u1 < 1 || u1 > 3)
		return 1;
	if (v1 < 4 || v1 > 6)
		return 1;
	s2[u][v] = 0;
	s2[u1][v1] = 'K';
	for (i = 0; r[i] != 0; i++)
	{
		c = s2[r[i] / BIG][r[i] % BIG];
		if (judge (c, r[i]))
			return 1;
	}
	return 0;
}

int main()
{
#ifdef LOCAL
	freopen ("D:/in.txt", "r", stdin);
	freopen ("D:/out.txt", "w", stdout);
#endif
	int n, a, b, i;
	char c;
	while (scanf ("%d%d%d", &n, &u, &v) == 3 && n)
	{
		memset (s, 0, sizeof (s));
		memset (r, 0, sizeof (r));
		s[u][v] = 'K';
		for (i = 0; i < n; i++)
		{
			do
			{
				scanf ("%c", &c);
			}
			while (c != 'H' && c != 'R' && c != 'C' && c != 'G');
			scanf ("%d%d", &a, &b);
			s[a][b] = c;
			/*if (c == 'G')
			{
				x = a;
				y = b;
			}*/
			r[i] = BIG * a + b;
		}
		/*flag = 1;*/
		/*if (v == y)
		{
			for (i = a - 1; i > u1; i--)
				if (s2[i][b] != 0)
				{
					flag = 0;
					break;
				}
		}
		else
			flag = 0;
		if (flag)
			printf ("NO\n");
		else
		{*/
		if (simulate (0, 1) && simulate (0, -1) && simulate (1, 0) && simulate (-1, 0))
			printf ("YES\n");
		else
			printf ("NO\n");
		/*}*/
	}
	return 0;
}