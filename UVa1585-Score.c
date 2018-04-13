#include<stdio.h>
int main()
{
	char a[100][85], *p;
	int s, sum, kase, i;
	scanf ("%d", &kase);
	getchar();
	for (i = 1; i <= kase; i++) fgets (a[i - 1], 85, stdin);
	for (i = 1; i <= kase; i++)
	{
		s = sum = 0;
		for (p = a[i - 1]; *p != '\n'; p++)
		{
			if (*p == 'O') s++;
			else s = 0;
			sum += s;
		}
		printf ("%d\n", sum);
	}
	return 0;
}