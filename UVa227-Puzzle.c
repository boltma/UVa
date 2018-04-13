#include<stdio.h>
#include<string.h>
#define maxn 1000000
char command[maxn];
void swap (char *a, char *b)
{
	char t;
	t = *a;
	*a = *b;
	*b = t;
	return;
}
int main()
{
	char puzzle[5][8], command;
	int i, j, x, y, kase = 0, flag;
	//freopen ("D:\\in.txt", "r", stdin);
	//freopen ("D:\\out.txt", "w", stdout);
	while (1)
	{
		memset (puzzle, 0, sizeof (puzzle));
		fgets (puzzle[0], sizeof (puzzle[0]), stdin);
		if (strcmp (puzzle[0], "Z") == 0 || strcmp (puzzle[0], "Z\n") == 0)
			return 0;
		if (kase)
			printf ("\n");
		kase++;
		flag = 1;
		i = j = 5;
		fgets (puzzle[1], sizeof (puzzle[1]), stdin);
		fgets (puzzle[2], sizeof (puzzle[2]), stdin);
		fgets (puzzle[3], sizeof (puzzle[3]), stdin);
		fgets (puzzle[4], sizeof (puzzle[4]), stdin);
		for (i = 0; i <= 4; i++)
		{
			if (strlen (puzzle[i]) == 5)
				puzzle[i][4] = ' ';
		}
		for (i = 0; i <= 4; i++)
		{
			for (j = 0; j <= 4; j++)
			{
				if (puzzle[i][j] == ' ')
				{
					x = i;
					y = j;
				}
			}
		}
		while ( (command = getchar()) != '0')
		{
			if (command != 'A' && command != 'B' && command != 'L' && command != 'R' && command != '\n')
				flag = 0;
			switch (command)
			{
			case 'A':
				if (x == 0)
				{
					flag = 0;
					break;
				}
				else
				{
					swap (&puzzle[x][y], &puzzle[x - 1][y]);
					x--;
				}
				break;
			case 'B':
				if (x == 4)
				{
					flag = 0;
					break;
				}
				else
				{
					swap (&puzzle[x][y], &puzzle[x + 1][y]);
					x++;
				}
				break;
			case 'L':
				if (y == 0)
				{
					flag = 0;
					break;
				}
				else
				{
					swap (&puzzle[x][y], &puzzle[x][y - 1]);
					y--;
				}
				break;
			case 'R':
				if (y == 4)
				{
					flag = 0;
					break;
				}
				else
				{
					swap (&puzzle[x][y], &puzzle[x][y + 1]);
					y++;
				}
				break;
			}
		}
		printf ("Puzzle #%d:\n", kase);
		if (!flag) printf ("This puzzle has no final configuration.\n");
		else
		{
			for (i = 0; i <= 4; i++)
			{
				for (j = 0; j <= 4; j++)
				{
					printf ("%c", puzzle[i][j]);
					if (j != 4) printf (" ");
					else printf ("\n");
				}
			}
		}
		getchar();
	}
	return 0;
}