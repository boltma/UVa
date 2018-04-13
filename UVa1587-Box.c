#include<stdio.h>
int swap (int *a, int *b)
{
	int t;
	t = *a;
	*a = *b;
	*b = t;
}
int main()
{
	int a[6][2], i, j, m, n, t;
	freopen ("D:\\in.txt", "r", stdin);
	freopen ("D:\\out.txt", "w", stdout);
	while (1)
	{
		for (i = 0; i <= 5; i++)
		{
			if (scanf ("%d%d", &m, &n) != EOF);
			else return 0;
			if (m < n) swap (&m, &n);
			a[i][0] = m;
			a[i][1] = n;
		}
		for (i = 0; i <= 5; i++)
		{
			for (j = i + 1; j <= 5; j++)
			{
				if (a[i][0] < a[j][0] || a[i][0] == a[j][0] && a[i][1] < a[j][1])
				{
					swap (a[i], a[j]);
					swap (a[i] + 1, a[j] + 1);
				}
			}
		}
		if (a[0][0] == a[1][0] && a[0][1] == a[1][1] && a[0][0] == a[2][0] && a[2][0] == a[3][0] && a[2][1] == a[3][1] && a[2][1] == a[4][1] && a[4][0] == a[5][0] && a[4][1] == a[5][1] && a[4][0] == a[0][1])
			printf ("POSSIBLE\n");
		else printf ("IMPOSSIBLE\n");
	}
	return 0;
}