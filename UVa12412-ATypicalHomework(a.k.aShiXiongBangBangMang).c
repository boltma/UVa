#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define maxn 1000
#define maxl 100
#define EPS 1e-5
//#define LOCAL

int  cid[maxn], score[maxn][5], removed[maxn] = {0}, n = 0;
char sid[maxn][11], name[maxn][21];
const char *course[] = {"Chinese", "Mathematics", "English", "Programming"};

void print_menu()
{
	printf (
	    "Welcome to Student Performance Management System (SPMS).\n"
	    "\n"
	    "1 - Add\n"
	    "2 - Remove\n"
	    "3 - Query\n"
	    "4 - Show ranking\n"
	    "5 - Show Statistics\n"
	    "0 - Exit\n"
	    "\n"
	);
	return;
}

void add()
{
	int judge (int k);
	for (;;)
	{
		printf ("Please enter the SID, CID, name and four scores. Enter 0 to finish.\n");
		scanf ("%s", sid[n]);
		if (strcmp (sid[n], "0") == 0)
			break;
		scanf ("%d%s%d%d%d%d", &cid[n], name[n], score[n], score[n] + 1, score[n] + 2, score[n] + 3);
		if (judge (n))
		{
			score[n][4] = score[n][0] + score[n][1] + score[n][2] + score[n][3];
			n++;
		}
		else
			printf ("Duplicated SID.\n");
	}
	return;
}

int judge (int k)
{
	int i;
	for (i = 0; i < k; i++)
		if (!removed[i] && strcmp (sid[i], sid[k]) == 0)
			return 0;
	return 1;
}

void DQ (int q)
{
	int rank (int k);
	char s[maxl];
	int i, count;
	double avg;
	for (;;)
	{
		count = 0;
		printf ("Please enter SID or name. Enter 0 to finish.\n");
		scanf ("%s", s);
		if (strcmp (s, "0") == 0)
			break;
		for (i = 0; i < n; i++)
			if (!removed[i])
			{
				if (strcmp (s, sid[i]) == 0 || strcmp (s, name[i]) == 0)
				{
					if (!q)
					{
						removed[i] = 1;
						count++;
					}
					else
					{
						avg = (double) score[i][4] / 4 + EPS;
						printf ("%d %s %d %s %d %d %d %d %d %.2f\n", rank (i), sid[i], cid[i], name[i], score[i][0], score[i][1], score[i][2], score[i][3], score[i][4], avg);
					}
				}
			}
		if (!q)
			printf ("%d student(s) removed.\n", count);
	}
	return;
}

int rank (int k)
{
	int i, count = 1;
	for (i = 0; i < n; i++)
	{
		if (!removed[i] && score[i][4] > score[k][4])
			count++;
	}
	return count;
}

void stat()
{
	int class, s[4][3] = {{0}}, t[5] = {0}, i, j, pass;
	double avg;
	printf ("Please enter class ID, 0 for the whole statistics.\n");
	scanf ("%d", &class);
	for (i = 0; i < n; i++)
	{
		pass = 0;
		if (!removed[i] && (!class || cid[i] == class))
		{
			for (j = 0; j < 4; j++)
			{
				s[j][0] += score[i][j];
				if (score[i][j] >= 60)
				{
					pass++;
					s[j][1]++;
				}
				else
					s[j][2]++;
			}
			if (pass)
				for (j = 1; j <= pass; j++)
					t[j]++;
			else
				t[pass]++;
		}
	}
	for (i = 0; i < 4; i++)
	{
		avg = (double) s[i][0] / (s[i][1] + s[i][2]) + EPS;
		printf (
		    "%s\n"
		    "Average Score: %.2f\n"
		    "Number of passed students: %d\n"
		    "Number of failed students: %d\n"
		    "\n",
		    course[i], avg, s[i][1], s[i][2]
		);
	}
	printf (
	    "Overall:\n"
	    "Number of students who passed all subjects: %d\n"
	    "Number of students who passed 3 or more subjects: %d\n"
	    "Number of students who passed 2 or more subjects: %d\n"
	    "Number of students who passed 1 or more subjects: %d\n"
	    "Number of students who failed all subjects: %d\n\n",
	    t[4], t[3], t[2], t[1], t[0]
	);
	return;
}

int main()
{
	int choice;
#ifdef LOCAL
	freopen ("D:/in.txt", "r", stdin);
	freopen ("D:/out.txt", "w", stdout);
#endif
	for (;;)
	{
		print_menu();
		scanf ("%d", &choice);
		if (!choice)
			break;
		switch (choice)
		{
		case 1:
			add();
			break;
		case 2:
			DQ (0);
			break;
		case 3:
			DQ (1);
			break;
		case 4:
			printf ("Showing the ranklist hurts students' self-esteem. Don't do that.\n");
			break;
		case 5:
			stat();
			break;
		}
	}
}