#include <iostream>
#include <set>
#include <string>
//#define LOCAL
using namespace std;

int main()
{
#ifdef LOCAL
	freopen ("D:/in.txt", "r", stdin);
	freopen ("D:/out.txt", "w", stdout);
#endif
	set<string> dict;
	set<string> ans;
	string word;
	while (cin >> word)
		dict.insert (word);
	for (auto it = dict.begin(); it != dict.end(); ++it)
	{
		for (int i = 0; i < it->size(); ++i)
		{
			string s1 = it->substr (0, i);
			if (dict.count (s1))
			{
				string s2 = it->substr (i);
				if (dict.count (s2))
					ans.insert (*it);
			}
		}
	}
	for (auto s : ans)
		cout << s << endl;
	return 0;
}