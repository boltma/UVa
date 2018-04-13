#include <cctype>
#include <iostream>
#include <string>
#define LOCAL

using namespace std;

unsigned chance, remain;
bool win, lose;
string ans, s;

void guess (char c)
{
	bool bad = true;
	if (isalpha (c))
		for (char &a : ans)
		{
			if (a == c)
			{
				a = ' ';
				remain--;
				bad = false;
			}
		}
	else
		bad = false;
	for (char &b : s)
		if (b == c)
			b = ' ';
	if (bad)
		--chance;
	if (!remain)
		win = true;
	if (!chance)
		lose = true;
	return;
}

int main()
{
#ifdef LOCAL
	freopen ("D:/in.txt", "r", stdin);
	freopen ("D:/out.txt", "w", stdout);
#endif
	int kase;
	while (cin >> kase && kase != -1)
	{
		cout << "Round " << kase << endl;
		cin >> ans >> s;
		win = lose = false;
		chance = 7;
		remain = ans.size();
		for (char c : s)
		{
			guess (c);
			if (win || lose)
				break;
		}
		if (win)
			cout << "You win." << endl;
		else if (lose)
			cout << "You lose." << endl;
		else
			cout << "You chickened out." << endl;
	}
	return 0;
}