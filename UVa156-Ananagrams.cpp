#include <iostream>
#include <map>
#include <string>
#include <cctype>
#include <vector>
#include <algorithm>
using namespace std;

string rep (const string &s)
{
	string t = s;
	for (char &c : t)
		c = tolower (c);
	sort (t.begin(), t.end());
	return t;
}

int main()
{
	string s;
	vector<string> list;
	map<string, int> ans;
	while (cin >> s && s != "#")
	{
		list.push_back (s);
		string t = rep (s);
		if (!ans.count (t))
			ans[t] = 0;
		ans[t]++;
	}
	vector<string> list2;
	for (string t : list)
		if (ans[rep (t)] == 1)
			list2.push_back (t);
	sort (list2.begin(), list2.end());
	for (string t : list2)
		cout << t << endl;
	return 0;
}