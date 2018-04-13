#include<stdio.h>
#include<string.h>
#define maxn 1005
#define maxm 55
char dna[maxm][maxn];
char s[] = "ACGT";
int main()
{
	int kase, i, j, k, m, n, count[4], max, t, sum;
	freopen ("D:\\in.txt", "r", stdin);
	freopen ("D:\\out.txt", "w", stdout);
	scanf ("%d", &kase);
	for (i = 1; i <= kase; i++)
	{
		sum = 0;
		scanf ("%d%d", &m, &n);
		for (j = 0; j <= m - 1; j++)
			scanf ("%s", dna[j]);
		for (j = 0; j <= n - 1; j++)
		{
			memset (count, 0, sizeof (count));
			max = 0;
			for (k = 0; k <= m - 1; k++)
			{
				switch (dna[k][j])
				{
				case 'A':
					count[0]++;
					break;
				case 'C':
					count[1]++;
					break;
				case 'G':
					count[2]++;
					break;
				case 'T':
					count[3]++;
					break;
				}
			}
			max = count[0];
			t = 0;
			for (k = 1; k <= 3; k++)
			{
				if (count[k] > max)
				{
					max = count[k];
					t = k;
				}
			}
			sum += m - max;
			printf ("%c", s[t]);
		}
		printf ("\n%d\n", sum);
	}
	return 0;
}