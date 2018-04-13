#include<stdio.h>
#include<string.h>
int check (char *s, int t)
{
	while (* (s + t) != '\0')
	{
		if (*s != * (s + t)) return 0;
		else s++;
	}
	return 1;
}
int main()
{
	char s[85];
	int kase, i, period;
	freopen ("D:\\in.txt", "r", stdin);
	freopen ("D:\\out.txt", "w", stdout);
	scanf ("%d", &kase);
	getchar();
	getchar();
	for (i = 1; i <= kase; i++)
	{
		fgets (s, 85, stdin);
		s[strlen (s) - 1] = '\0';
		for (period = 1; period <= 80; period++)
		{
			if (! (strlen (s) % period) && check (s, period))
			{
				printf ("%d", period);
				if (i != kase) printf ("\n\n");
				break;
			}
		}
		if (i != kase) getchar();
	}
	printf ("\n");
	return 0;
}