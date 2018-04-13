#include<stdio.h>
#include<string.h>
#define LOCAL
double C = 12.01, H = 1.008, O = 16.00, N = 14.01;
int num (char *s)
{
	int num = 0;
	while (*s >= '0' && *s <= '9')
	{
		num = num * 10 + *s - '0';
		s++;
	}
	return num;
}
double weight (char *s)
{
	double sum = 0;
	while (*s != '\0')
	{
		switch (*s)
		{
		case 'H':
			if (* (s + 1) >= '1' && * (s + 1) <= '9') sum += num (s + 1) * H;
			else sum += H;
			break;
		case 'C':
			if (* (s + 1) >= '1' && * (s + 1) <= '9') sum += num (s + 1) * C;
			else sum += C;
			break;
		case 'O':
			if (* (s + 1) >= '1' && * (s + 1) <= '9') sum += num (s + 1) * O;
			else sum += O;
			break;
		case 'N':
			if (* (s + 1) >= '1' && * (s + 1) <= '9') sum += num (s + 1) * N;
			else sum += N;
			break;
		}
		s++;
	}
	return sum;
}
int main()
{
	char s[85];
	int kase, i;
#ifdef LOCAL
	freopen ("D:\\in.txt", "r", stdin);
	freopen ("D:\\out.txt", "w", stdout);
#endif
	scanf ("%d", &kase);
	getchar();
	for (i = 1; i <= kase; i++)
	{
		fgets (s, 85, stdin);
		s[strlen (s) - 1] = '\0';
		printf ("%.3lf\n", weight (s));
	}
	return 0;
}