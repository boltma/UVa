#include <stdio.h>
#include <string.h>
#define maxn 205

int main()
{
	int kase;
	char s[maxn];
	int cmp(char [], int, int, int);
	scanf("%d", &kase);
	getchar();
	while (kase--)
	{
		int len, min = 0, i;
		gets(s);
		len = strlen(s);
		for (i = 0; i < len; ++i)
			s[i + len] = s[i];
		s[2 * len] = '\0';
		for (i = 1; i < len; ++i)
			if (cmp(s, i, min, len))
				min = i;
		for (i = min; i < min + len; ++i)
			putchar(s[i]);
		putchar('\n');
	}
	return 0;
}

int cmp(char s[], int a, int b, int len)
{
	int i;
	for (i = 0; i < len; ++i)
	{
		if (s[a + i] < s[b + i])
			return 1;
		else if (s[a + i] > s[b + i])
			return 0;
	}
	return 0;
}