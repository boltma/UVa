#include<stdio.h>
#define N 100000
#define LOCAL
int main()
{
	int s[10][2], t[10][2], n, kase = 1, i, j, a, flag1, flag2, flag3, count1, count2;
#ifdef LOCAL
	freopen ("D:/in.txt", "r", stdin);
	freopen ("D:/out.txt", "w", stdout);
#endif
	while (scanf ("%d", &n) && n)
	{
		flag3 = 0;
		for (i = 0; i < n; i++)
		{
			scanf ("%d%d%d", &s[i][0], &s[i][1], &a);
			if (a <= s[i][0])
			{
				t[i][0] = 1;
				t[i][1] = a;
			}
			else
			{
				t[i][0] = 0;
				t[i][1] = a - s[i][0];
			}
		}
		for (i = 1; i <= N; i++)
		{
			for (j = 0; j < n; j++)
				if (!t[j][0])
				{
					flag2 = 0;
					break;
				}
			if (flag2)
			{
				flag3 = 1;
				break;
			}
			count1 = count2 = 0;
			for (j = 0; j < n; j++)
			{
				if (t[j][0])
					count1++;
				else
					count2++;
			}
			if (count2 > count1)
				flag1 = 1;
			else
				flag1 = 0;
			for (j = 0; j < n; j++)
			{
				flag2 = 1;
				t[j][1]++;
				if ( (t[j][1] == s[j][0] + 1 && t[j][0] == 1) || (t[j][1] == s[j][1] + 1 && t[j][0] == 0))
				{
					if (t[j][1] == s[j][0] + 1 && t[j][0] == 1 && !flag1)
						t[j][0] = 1;
					else
						t[j][0] = !t[j][0];
					t[j][1] = 1;
				}
			}
		}
		printf ("Case %d: ", kase++);
		if (flag3)
			printf ("%d\n", i);
		else
			printf ("-1\n");
	}
	return 0;
}