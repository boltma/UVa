#include<stdio.h>
#include<string.h>
int main()
{
	int l1, l2, i, j, min, flag, s;
	char a[105], b[105];
	freopen ("D:\\in.txt", "r", stdin);
	freopen ("D:\\out.txt", "w", stdout);
	while (scanf ("%s%s", a, b) != EOF)
	{
		l1 = strlen (a);
		l2 = strlen (b);
		min = l1 + l2;
		for (i = - l1 + 1; i <= l2 - 1; i++)
		{
			if (i < 0 && l1 + i <= l2) s = l2 - i;
			else if (i < 0 && l1 + i > l2) s = l1;
			else if (i >= 0 && i < l2 - l1) s = l2;
			else s = l1 + i;
			if (min <= s) continue;
			flag = 1;
			for (j = 0; j <= l2 - 1; j++)
				if (j + 1 >= i && j <= i + l1 && b[j] == '2' && a[j - i] == '2')
				{
					flag = 0;
					break;
				}
			if (!flag) continue;
			if (min > s) min = s;
		}
		printf ("%d\n", min);
	}
	return 0;
}