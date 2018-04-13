#include<stdio.h>
#include<string.h>
int main()
{
	int a[10] = {0}, kase, i, n, k, s, j;
	scanf ("%d", &kase);
	for (i = 1; i <= kase; i++)
	{
		memset (a, 0, sizeof (a));
		scanf ("%d", &n);
		for (k = 1; k <= n; k++)
		{
			s = k;
			while (s != 0)
			{
				a[s % 10]++;
				s /= 10;
			}
		}
		for (j = 0; j <= 9; j++)
		{
			if (j) printf (" ");
			printf ("%d", a[j]);
		}
		printf ("\n");
	}
	return 0;
}