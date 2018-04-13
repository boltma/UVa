#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct text
{
	char plain[85];
	char cipher[500];
} s[100];

char d[128][10], code[100];
int n;

int cmp (const void *a, const void *b)
{
	return strcmp ( (* (struct text *) a).plain, (* (struct text *) b).plain);
}

int count (char **p)
{
	int num = 0, i;
	for (i = 0; i < n; i++)
		if (!strcmp (s[i].cipher, code))
		{
			if (!num)
				*p = s[i].plain;
			num++;
		}
	return num;
}

void search (char **p)
{
	char *q, *r;
	int flag, i, min = 10000, a;
	*p = s[0].plain;
	for (i = 0; i < n; i++)
	{
		flag = 1;
		q = code;
		r = s[i].cipher;
		while (*q != '\0' && *r != '\0')
		{
			if (* (q++) != * (r++))
			{
				flag = 0;
				break;
			}
		}
		if (flag)
		{
			if (strlen (code) > strlen (s[i].cipher))
				a = strlen (code) - strlen (s[i].cipher);
			else
				a = strlen (s[i].cipher) - strlen (code);
			if (a < min)
			{
				*p = s[i].plain;
				min = a;
			}
		}
	}
	return;
}

int main()
{
	char c, *p, *q, *r;
	int i = 0;
	while ( (c = getchar()) != '*')
		scanf ("%s%*c", d[ (int) c]);
	while (scanf ("%s", s[i].plain) && s[i].plain[0] != '*')
	{
		p = s[i].plain;
		r = s[i].cipher;
		while (*p != '\0')
		{
			q = d[ (int) * p];
			while (*q != '\0')
				* (r++) = * (q++);
			p++;
		}
		i++;
	}
	n = i;
	qsort (s, n, sizeof (s[0]), cmp);
	while (scanf ("%s", code) && code[0] != '*')
	{
		i = count (&p);
		if (i)
		{
			printf ("%s", p);
			if (i != 1)
				printf ("!");
			printf ("\n");
		}
		else
		{
			search (&p);
			printf ("%s?\n", p);
		}
	}
	return 0;
}