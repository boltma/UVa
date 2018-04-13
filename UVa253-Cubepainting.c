#include <stdio.h>
#include <string.h>
#define LOCAL
char s1[7], s2[7], temp[6];
int r[6];
const int t[] = {3, 2, 4, 5}, m[5][6] = {{6, 5, 3, 4, 2, 1}, {5, 1, 3, 4, 6, 2}, {4, 2, 1, 6, 5, 3}, {3, 2, 6, 1, 5, 4}, {2, 6, 3, 4, 1, 5}};

void spin()
{
	int i;
	memcpy (temp, s2, sizeof (temp));
	for (i = 0; i <= 3; i++)
		s2[t[ (i + 1) % 4] - 1] = temp[t[i] - 1];
	return;
}

void rotate (int i)
{
	if (i)
		memcpy (r, m[i - 1], sizeof (r));
	else
		return;
	memcpy (temp, s2, sizeof (temp));
	for (i = 0; i <= 5; i++)
		s2[i] = temp[r[i] - 1];
	return;
}

int main()
{
	char a[15];
	int i, j, flag;
#ifdef LOCAL
	freopen ("D:/in.txt", "r", stdin);
	freopen ("D:/out.txt", "w", stdout);
#endif
	s1[6] = s2[6] = '\0';
	while (scanf ("%s", a) == 1)
	{
		flag = 0;
		memcpy (s1, a, sizeof (s1) - sizeof (char));
		memcpy (s2, a + 6, sizeof (s2) - sizeof (char));
		for (i = 0; i <= 5; i++)
		{
			memcpy (s2, a + 6, sizeof (s2) - sizeof (char));
			rotate (i);
			for (j = 0; j <= 3; j++)
			{
				spin();
				if (strcmp (s1, s2) == 0)
				{
					flag = 1;
					break;
				}
			}
			if (flag)
				break;
		}
		if (flag)
			printf ("TRUE\n");
		else
			printf ("FALSE\n");
	}
	return 0;
}