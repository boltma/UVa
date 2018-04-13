#include<stdio.h>
#include<string.h>
#include<math.h>
#define LOCAL
int main()
{
	long long e, n, list1[15][35] = {{0}};
	double m, list2[15][35] = {{0}}, x, t;
	int i, j;
	char s[30], *p;
#ifdef LOCAL
	freopen ("D:/in.txt", "r", stdin);
	freopen ("D:/out.txt", "w", stdout);
#endif
	for (i = 0; i <= 9; i++)
	{
		m = 1 - pow (0.5, i + 1);
		m = log10 (m);
		for (j = 1; j <= 30; j++)
		{
			e = (1 << j) - 1;
			x = m + e * log10 (2);
			list1[i][j] = (long long) x;
			list2[i][j] = pow (10, x - list1[i][j]);
		}
	}
	while (1)
	{
		scanf ("%s", s);
		if (strcmp (s, "0e0") == 0)
			return 0;
		x = s[0] - '0';
		p = s + 2;
		t = 1;
		n = 0;
		while (*p != 'e')
		{
			t *= 0.1;
			x += t * (*p - '0');
			p++;
		}
		while (* (++p) != '\0')
		{
			n = 10 * n + (*p - '0');
		}
		while (x < 1)
		{
			x *= 10;
			n--;
		}
		for (i = 0; i <= 9; i++)
		{
			for (j = 1; j <= 30; j++)
			{
				if (n == list1[i][j] && fabs (x - list2[i][j]) < 0.0001)
				{
					printf ("%d %d\n", i, j);
					break;
				}
			}
		}
	}
	return 0;
}