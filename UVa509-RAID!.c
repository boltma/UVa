#include<stdio.h>
#include<string.h>
#define maxn 6500
#define LOCAL
char t[6][maxn];
int d, s, b, type;

int repair()
{
	int i, j, k, sum, flag;
	for (i = 0; i < s * b; i++)
	{
		sum = flag = 0;
		for (j = 0; j < d; j++)
		{
			if (t[j][i] != 'x')
				sum ^= t[j][i] - '0';
			else
			{
				if (flag)
					return 0;
				else
				{
					flag = 1;
					k = j;
				}
			}
		}
		if (flag)
			t[k][i] = type ^ sum + '0';
		else
		{
			if ( (sum ^ type) == 1)
				return 0;
		}
	}
	return 1;
}

int main()
{
	int i, j, k, kase = 1, count, num;
	char c;
#ifdef LOCAL
	freopen ("D:/in.txt", "r", stdin);
	freopen ("D:/out.txt", "w", stdout);
#endif
	while (scanf ("%d%d%d\n", &d, &s, &b) == 3  && d)
	{
		scanf ("%[OE]%*c", &c);
		type = c == 'E' ? 0 : 1;
		for (i = 0; i < d; i++)
			scanf ("%s", t[i]);
		printf ("Disk set %d is ", kase++);
		if (!repair())
			printf ("invalid.\n");
		else
		{
			printf ("valid, contents are: ");
			num = count = 0;
			for (j = 0; j < b; j++)
			{
				for (i = 0; i < d; i++)
				{
					if (j % d != i)
					{
						for (k = 0; k < s; k++)
						{
							num = (num << 1) + t[i][j * s + k] - '0';
							count++;
							if (count == 4)
							{
								printf ("%X", num);
								num = count = 0;
							}
						}
					}
				}
			}
			while (count % 4 != 0)
			{
				num = num << 1;
				count++;
			}
			if (count) printf ("%X", num);
			printf ("\n");
		}
	}
	return 0;
}