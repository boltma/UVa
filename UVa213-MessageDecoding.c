#include<stdio.h>
#include<string.h>
//#define LOCAL

char readchar()
{
	char c;
	for (;;)
	{
		c = getchar();
		if (c != '\n' && c != '\r')
			return c;
	}
}

int readint (int n)
{
	int sum = 0;
	while (n--)
	{
		sum = sum * 2 + readchar() - '0';
	}
	return sum;
}

char code[8][1 << 8];

int readcodes()
{
	int len, i;
	char c;
	memset (code, '\0', sizeof (code));
	code[1][0] = readchar();
	for (len = 2; len <= 7; len++)
	{
		for (i = 0; i < (1 << len) - 1; i++)
		{
			c = getchar();
			if (c == EOF) return 0;
			if (c == '\n' || c == '\r') return 1;
			code[len][i] = c;
		}
	}
	return 1;
}

void printcodes()
{
	int len, i;
	for (len = 1; len <= 7; len++)
	{
		for (i = 0; i < (1 << len) - 1; i++)
		{
			if (code[len][i] == 0) return;
			printf ("code[%d][%d] = %c\n", len, i, code[len][i]);
		}
	}
}

int main()
{
#ifdef LOCAL
	freopen ("D:/in.txt", "r", stdin);
	freopen ("D:/out.txt", "w", stdout);
#endif
	int len, v;
	while (readcodes())
	{
		//printcodes();
		for (;;)
		{
			len = readint (3);
			if (len == 0)
				break;
			for (;;)
			{
				v = readint (len);
				if (v == (1 << len) - 1)
					break;
				putchar (code[len][v]);
			}
		}
		putchar ('\n');
	}
	return 0;
}