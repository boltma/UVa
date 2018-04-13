#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#define LOCAL
#define maxn 1000
int s[maxn];

int cmp (const void* a, const void* b)
{
	return * (int *) a - * (int *) b;
}

int main()
{
	int m, n, i, k, kase = 1, flag;
	long x, u, v;
	double a, b;
#ifdef LOCAL
	freopen ("D:/in.txt", "r", stdin);
	freopen ("D:/out.txt", "w", stdout);
#endif
	while (scanf ("%d%d", &m, &n) == 2 && m)
	{
		memset (s, 0, sizeof (s));
		u = v = flag = 0;
		for (i = 0; i < m * n; i++)
		{
			scanf ("%d", &s[i]);
		}
		scanf ("%ld", &x);
		qsort (s, m * n, sizeof (int), cmp);
		for (i = 0; i < m * n; i++)
		{
			v = u;
			u += i * 100 * s[i];
			if (i)
				u -= i * 100 * s[i - 1];
			if (u >= x)
			{
				k = i;
				x -= v;
				flag = 1;
				break;
			}
		}
		if (!flag)
		{
			k = m * n;
			x -= u;
		}
		a = (double) 100 * k / (m * n);
		b = (double) x / (100 * k) + s[k - 1];
		printf ("Region %d\nWater level is %.2lf meters.\n%.2lf percent of the region is under water.\n\n", kase++, b, a);
	}
	return 0;
}