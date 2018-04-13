#include<stdio.h>
#include<string.h>
#define maxn 3100
int s[maxn], r1[maxn], r2[maxn];
int main()
{
	int a, b, i, j, k, integer, residue, period, flag;
	while (scanf ("%d%d", &a, &b) == 2)
	{
		integer = a / b;
		r2[0] = a % b;
		residue = (a % b) * 10;
		flag = 0;
		for (i = 1; i <= 3099; i++)
		{
			r1[i] = residue / b;
			r2[i] = residue %= b;
			for (j = 0; j < i; j++)
			{
				if (r2[j] == residue)
				{
					period = i - j;
					flag = 1;
					break;
				}
			}
			if (flag) break;
			residue *= 10;
		}
		printf ("%d/%d = %d.", a, b, integer);
		for (k = 1; k <= j; k++) printf ("%d", r1[k]);
		printf ("(");
		if (period <= 50) for (k = j + 1; k <= i; k++) printf ("%d", r1[k]);
		else
		{
			for (k = j + 1; k <= j + 50; k++) printf ("%d", r1[k]);
			printf ("...");
		}
		printf (")\n   %d = number of digits in repeating cycle\n\n", period);
	}
	return 0;
}