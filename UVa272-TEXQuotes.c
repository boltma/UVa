#include<stdio.h>
#define LOCAL
int main()
{
#ifdef LOCAL
	freopen ("D:/in.txt", "r", stdin);
	freopen ("D:/out.txt", "w", stdout);
#endif
	int c, flag = 1;
	while ( (c = getchar()) != EOF)
	{
		if (c == '"')
		{
			printf ("%s", flag ? "``" : "''");
			flag = !flag;
		}
		else putchar (c);
	}
	return 0;
}