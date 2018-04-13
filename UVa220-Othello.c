#include<stdio.h>
#include<string.h>
#define LOCAL
char s[10][10] = {{0}};
int s2[10][10];
int dx[] = {0, 0, -1, 1, -1, 1, -1, 1};
int dy[] = {1, -1, 0, 0, 1, 1, -1, -1};

int jud (int player, int x, int y, int i)
{
	int player1 = 2;
	x += dx[i];
	y += dy[i];
	if (! (x >= 1 && x <= 8 && y >= 1 && y <= 8))
		return 0;
	else
	{
		if (s[x][y] == 'W')
			player1 = 0;
		else if (s[x][y] == 'B')
			player1 = 1;
		if (player == player1 || player1 == 2)
			return 0;
	}
	while (x >= 1 && x <= 8 && y >= 1 && y <= 8)
	{
		x += dx[i];
		y += dy[i];
		if (! (x >= 1 && x <= 8 && y >= 1 && y <= 8))
			return 0;
		else
		{
			player1 = 2;
			if (s[x][y] == 'W')
				player1 = 0;
			else if (s[x][y] == 'B')
				player1 = 1;
			if (player == player1)
				return 1;
			if (player1 == 2)
				return 0;
		}
	}
	return 0;
}

int judge (int player, int x, int y)
{
	int i;
	if (s[x][y] != '-')
		return 0;
	for (i = 0; i < 8; i++)
	{
		if (jud (player, x, y, i) == 1)
			return 1;
	}
	return 0;
}

void judgewhole()
{
	int i, j;
	memset (s2, 0, sizeof (s2));
	for (i = 1; i <= 8; i++)
	{
		for (j = 1; j <= 8; j++)
		{
			if (judge (0, i, j))
				s2[i][j] += 10;
			if (judge (1, i, j))
				s2[i][j]++;
		}
	}
	return;
}

void move (int *player, int x, int y)
{
	int i, x1, y1;
	if ( (*player == 0 && s2[x][y] / 10 != 1) || (*player == 1 && s2[x][y] % 10 != 1))
		*player = !*player;
	if (*player == 0)
		s[x][y] = 'W';
	else
		s[x][y] = 'B';
	for (i = 0; i < 8; i++)
	{
		x1 = x + dx[i];
		y1 = y + dy[i];
		if (jud (*player, x, y, i) == 0)
			continue;
		else
		{
			while ( (*player == 0 && s[x1][y1] != 'W') || (*player == 1 && s[x1][y1] != 'B'))
			{
				if (*player == 0)
					s[x1][y1] = 'W';
				else
					s[x1][y1] = 'B';
				x1 += dx[i];
				y1 += dy[i];
			}
		}
	}
	*player = !*player;
	return;
}

void print (int player)
{
	int i, j, flag = 1, first = 1;
	for (i = 1; i <= 8; i++)
		for (j = 1; j <= 8; j++)
			if ( (player == 0 && s2[i][j] / 10 == 1) || (player == 1 && s2[i][j] % 10 == 1))
			{
				if (!first)
					printf (" ");
				else
					first = 0;
				printf ("(%d,%d)", i, j);
				flag = 0;
			}
	if (flag)
		printf ("No legal move.");
	printf ("\n");
	return;
}

int main()
{
	int n, i, j, x, y, player, count0, count1;
	char t[5];
#ifdef LOCAL
	freopen ("D:/in.txt", "r", stdin);
	freopen ("D:/out.txt", "w", stdout);
#endif
	scanf ("%d%*c", &n);
	while (n--)
	{
		for (i = 1; i <= 8; i++)
			scanf ("%s", &s[i][1]);
		scanf ("%s", t);
		if (t[0] == 'W')
			player = 0;
		else
			player = 1;
		while (scanf ("%s", t))
		{
			if (t[0] == 'Q')
			{
				for (i = 1; i <= 8; i++)
					printf ("%s\n", s[i] + 1);
				break;
			}
			else if (t[0] == 'L')
			{
				judgewhole();
				print (player);
			}
			else
			{
				count0 = count1 = 0;
				x = t[1] - '0';
				y = t[2] - '0';
				judgewhole();
				move (&player, x, y);
				for (i = 1; i <= 8; i++)
					for (j = 1; j <= 8; j++)
					{
						if (s[i][j] == 'W')
							count0++;
						if (s[i][j] == 'B')
							count1++;
					}
				printf ("Black - %2d White - %2d\n", count1, count0);
			}
		}
		if (n)
			printf ("\n");
	}
	return 0;
}