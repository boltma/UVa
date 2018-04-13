#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define LOCAL
int cmp (const void* a, const void* b)
{
	return * (int *) a - * (int *) b;
}
int main()
{
#ifdef LOCAL
	freopen ("D:/in.txt", "r", stdin);
	freopen ("D:/out.txt", "w", stdout);
#endif
	char a1[105], a2[105], *p;
	int count1[26], count2[26], flag, i;
	while (scanf ("%s%s", a1, a2) == 2)
	{
		memset (count1, 0, sizeof (count1));
		memset (count2, 0, sizeof (count2));
		p = a1;
		while (*p != '\0')
		{
			count1[*p - 'A']++;
			p++;
		}
		p = a2;
		while (*p != '\0')
		{
			count2[*p - 'A']++;
			p++;
		}
		qsort (count1, 26, sizeof (int), cmp);
		qsort (count2, 26, sizeof (int), cmp);
		flag = 1;
		for (i = 0; i <= 25; i++)
		{
			if (count1[i] != count2[i])
			{
				flag = 0;
				break;
			}
		}
		if (flag)
			printf ("YES\n");
		else
			printf ("NO\n");
	}
	return 0;
}