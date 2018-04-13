#include<stdio.h>
#include<string.h>
#define LOCAL
int main()
{
	int kase = 0, i, j, count, r, c, n;
	char a[15][15], (*p) [15], *q;
	struct point
	{
		int x, y, across, down;
	};
	struct point s[105];
#ifdef LOCAL
	freopen ("D:/in.txt", "r", stdin);
	freopen ("D:/out.txt", "w", stdout);
#endif
	while (scanf ("%d%d", &r, &c) == 2)
	{
		if (kase)
			printf ("\n");
		kase++;
		memset (a, '\0', sizeof (a));
		count = 0;
		for (i = 0; i <= r - 1; i++)
			scanf ("%s", a[i]);
		for (i = 0; i <= r - 1; i++)
		{
			for (j = 0; j <= c - 1; j++)
			{
				if ( ( (i == 0 || a[i - 1][j] == '*') || (j == 0 || a[i][j - 1] == '*')) && a[i][j] != '*')
				{
					s[count].x = i;
					s[count].y = j;
					if (j == 0 || a[i][j - 1] == '*') s[count].across = 1;
					else s[count].across = 0;
					if (i == 0 || a[i - 1][j] == '*') s[count].down = 1;
					else s[count].down = 0;
					count++;
				}
			}
		}
		n = --count;
		printf ("puzzle #%d:\n", kase);
		printf ("Across\n");
		for (i = 0; i <= n; i++)
		{
			if (s[i].across)
			{
				if (i + 1 < 10)
					printf ("  %d.", i + 1);
				else
					printf (" %d.", i + 1);
				p = a + s[i].x;
				q = *p + s[i].y;
				while (*q != '*' && *q != '\0')
				{
					printf ("%c", *q);
					q++;
				}
				printf ("\n");
			}
		}
		printf ("Down\n");
		for (i = 0; i <= n; i++)
		{
			if (s[i].down)
			{
				if (i + 1 < 10)
					printf ("  %d.", i + 1);
				else
					printf (" %d.", i + 1);
				p = a + s[i].x;
				q = *p + s[i].y;
				while (*q != '*' && *q != '\0')
				{
					printf ("%c", *q);
					p++;
					q = *p + s[i].y;
				}
				printf ("\n");
			}
		}
	}
	return 0;
}