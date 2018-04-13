#include<stdio.h>
#include<string.h>
#define maxn 100000
char s[maxn], t[maxn];
int main()
{
	int flag;
	char *p, *q;
	freopen ("D:\\in.txt", "r", stdin);
	freopen ("D:\\out.txt", "w", stdout);
	while (scanf ("%s%s", s, t) != EOF)
	{
		flag = 1;
		p = s;
		q = t;
		while (*p != '\0')
		{
			while (*q != '\0')
			{
				if (*q == *p) break;
				q++;
			}
			if (*q == '\0')
			{
				flag = 0;
				break;
			}
			p++;
			q++;
		}
		if (flag) printf ("Yes\n");
		else printf ("No\n");
	}
	return 0;
}