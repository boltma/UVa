#include<stdio.h>
#include<string.h>
#include<ctype.h>
//#define LOCAL
const char* rev = "A   3  HIL JM O   2TUVWXY51SE Z  8 ";
const char* msg[] = {"is not a palindrome", "is a regular palindrome", "is a mirrored string", "is a mirrored palindrome"};
char reverse (char c)
{
	if (isalpha (c))
		return rev[c - 'A'];
	if (isdigit (c))
		return rev[25 + c - '0'];
	return '\0';
}
int main()
{
#ifdef LOCAL
	freopen ("D:/in.txt", "r", stdin);
	freopen ("D:/out.txt", "w", stdout);
#endif
	char s[1000];
	int mir, pal, i;
	while (scanf ("%s", s) == 1)
	{
		mir = pal = 1;
		for (i = 0; i <= strlen (s) - 1; i++)
		{
			if (s[i] != s[strlen (s) - 1 - i]) pal = 0;
			if (s[i] != reverse (s[strlen (s) - 1 - i])) mir = 0;
		}
		printf ("%s -- %s.\n\n", s, msg[mir * 2 + pal]);
	}
	return 0;
}