#include <stdio.h>
#define maxn 1000000
int s[maxn];

int f (long long n)
{
	if (n == 1)
		return 1;
	if (n % 2 == 0)
	{
		if (n / 2 - 1 < maxn && s[n / 2 - 1])
		{
			if (n < maxn)
				s[n - 1] = s[n / 2 - 1] + 1;
			else
				return s[n / 2 - 1] + 1;
		}
		else
		{
			if (n < maxn)
				s[n - 1] = f (n / 2) + 1;
			else
				return f (n / 2) + 1;
		}
	}
	else
	{
		if (3 * n + 1 < maxn && s[3 * n])
		{
			if (n < maxn)
				s[n - 1] = s[3 * n] + 1;
			else
				return s[3 * n] + 1;
		}
		else
		{
			if (n < maxn)
				s[n - 1] = f (3 * n + 1) + 1;
			else
				return f (3 * n + 1) + 1;
		}
	}
	return s[n - 1];
}

int main()
{
	int i, j, max, k, flag;
	long long a;
	for (a = 0; a < maxn; a++)
		s[a] = f (a + 1);
	while (scanf ("%d%d", &i, &j) == 2)
	{
		flag = 0;
		if (i > j)
		{
			k = i;
			i = j;
			j = k;
			flag = 1;
		}
		max = s[i - 1];
		for (k = i; k <= j; k++)
			if (s[k - 1] > max)
				max = s[k - 1];
		if (flag)
			printf ("%d %d %d\n", j, i, max);
		else
			printf ("%d %d %d\n", i, j, max);
	}
	return 0;
}