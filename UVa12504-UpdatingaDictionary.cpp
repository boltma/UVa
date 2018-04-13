#include <iostream>
#include <map>
#include <set>
#include <string>
#define LOCAL
using namespace std;
int main()
{
#ifdef LOCAL
	freopen ("D:/in.txt", "r", stdin);
	freopen ("D:/out.txt", "w", stdout);
#endif
	int kase;
	cin >> kase;
	getchar();
	while (kase--)
	{
		string dict1, dict2, *dict;
		getline (cin, dict1);
		getline (cin, dict2);
		map<string, string> d1, d2, *d;
		string temp, k;
		for (int i = 1; i <= 2; ++i)
		{
			switch (i)
			{
			case 1:
				d = &d1;
				dict = &dict1;
				break;
			case 2:
				d = &d2;
				dict = &dict2;
				break;
			}
			for (char c : *dict)
			{
				if (c == '{')
					continue;
				switch (c)
				{
				case ':':
					k = temp;
					temp.clear();
					break;
				case ',':
				case '}':
					if (k.size())
						(*d) [k] = temp;
					k.clear();
					temp.clear();
					break;
				default:
					temp += c;
					break;
				}
			}
		}
		set<string> s_add, s_del, s_change;
		for (auto it = d2.begin(); it != d2.end(); ++it)
		{
			if (d1.count (it->first))
			{
				if (d1[it->first] != it->second)
					s_change.insert (it->first);
			}
			else
				s_add.insert (it->first);
		}
		for (auto it = d1.begin(); it != d1.end(); ++it)
		{
			if (!d2.count (it->first))
				s_del.insert (it->first);
		}
		if (s_add.size())
		{
			bool flag = false;
			cout << '+';
			for (auto s : s_add)
			{
				if (flag)
					cout << ",";
				else
					flag = true;
				cout << s;
			}
			cout << endl;
		}
		if (s_del.size())
		{
			bool flag = false;
			cout << '-';
			for (auto s : s_del)
			{
				if (flag)
					cout << ",";
				else
					flag = true;
				cout << s;
			}
			cout << endl;
		}
		if (s_change.size())
		{
			bool flag = false;
			cout << '*';
			for (auto s : s_change)
			{
				if (flag)
					cout << ",";
				else
					flag = true;
				cout << s;
			}
			cout << endl;
		}
		if (!s_add.size() && !s_del.size() && !s_change.size())
			cout << "No changes" << endl;
		cout << endl;
	}
	return 0;
}