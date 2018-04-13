#include <iostream>
#include <cstring>
using namespace std;
const int maxn = 100005;
int last, cur, next[maxn];
char s[maxn];

int main()
{
	while (cin.getline (s + 1, maxn - 1))
	{
		int n = strlen (s + 1);
		last = cur = 0;
		::next[0] = 0;
		for (int i = 1; i <= n; ++i)
		{
			char c = s[i];
			if (c == '[')
				cur = 0;
			else if (c == ']')
				cur = last;
			else
			{
				::next[i] = ::next[cur];
				::next[cur] = i;
				if (cur == last)
					last = i;
				cur = i;
			}
		}
		for (int i = ::next[0]; i != 0; i =::next[i])
			cout << s[i];
		cout << endl;
	}
	return 0;
}