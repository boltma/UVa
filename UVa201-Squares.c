#include<stdio.h>
#include<string.h>
#define LOCAL
char h[10][10], v[10][10];

int judge_horizontal (int a, int b, int len)
{
	int i, flag = 1;
	for (i = b; i < b + len; i++)
		if (h[a][i] == 0)
		{
			flag = 0;
			break;
		}
	return flag;
}

int judge_vertical (int a, int b, int len)
{
	int i, flag = 1;
	for (i = a; i < a + len; i++)
		if (v[i][b] == 0)
		{
			flag = 0;
			break;
		}
	return flag;
}

int judge_square (int a, int b, int len)
{
	return (judge_horizontal (a, b, len) && judge_horizontal (a + len, b, len) && judge_vertical (a, b, len) && judge_vertical (a, b + len, len));
}

int main()
{
	int n, m, kase = 0, i, j, a, b, len, count, flag;
	char c;
#ifdef LOCAL
	freopen ("D:/in.txt", "r", stdin);
	freopen ("D:/out.txt", "w", stdout);
#endif
	while (scanf ("%d", &n) != EOF)
	{
		scanf ("%d", &m);
		memset (h, 0, sizeof (h));
		memset (v, 0, sizeof (v));
		flag = 0;
		getchar();
		for (i = 1; i <= m; i++)
		{
			scanf ("%c%d%d", &c, &a, &b);
			switch (c)
			{
			case 'H':
				h[a][b] = 1;
				break;
			case 'V':
				v[b][a] = 1;
				break;
			}
			getchar();
		}
		if (kase++)
			printf ("\n**********************************\n\n");
		printf ("Problem #%d\n\n", kase);
		for (len = 1; len < n; len++)
		{
			count = 0;
			for (i = 1; i <= n - len; i++)
				for (j = 1; j <= n - len; j++)
				{
					if (judge_square (i, j, len))
					{
						flag = 1;
						count++;
					}
				}
			if (count)
				printf ("%d square (s) of size %d\n", count, len);
		}
		if (!flag)
			printf ("No completed squares can be found.\n");
	}
	return 0;
}