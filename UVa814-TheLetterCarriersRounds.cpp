#include <iostream>
#include <map>
#include <string>
#include <set>
#include <vector>
#define LOCAL
using namespace std;

void parse_address (const string& s, string& user, string& mta)
{
	int k = s.find ('@');
	user = s.substr (0, k);
	mta = s.substr (k + 1);
	return;
}

int main()
{
#ifdef LOCAL
	freopen ("D:/in.txt", "r", stdin);
	freopen ("D:/out.txt", "w", stdout);
#endif
	int k;
	string s, t, user1, mta1, user2, mta2;
	set<string> addr;
	while (cin >> s && s != "*")
	{
		cin >> s >> k;
		while (k--)
		{
			cin >> t;
			addr.insert (t + "@" + s);
		}
	}
	while (cin >> s && s != "*")
	{
		parse_address (s, user1, mta1);
		vector<string> mta;
		map<string, vector<string> > dest;
		set<string> vis;
		while (cin >> t && t != "*")
		{
			parse_address (t, user2, mta2);
			if (vis.count (t))
				continue;
			vis.insert (t);
			if (!dest.count (mta2))
			{
				mta.push_back (mta2);
				dest[mta2] = vector<string>();
			}
			dest[mta2].push_back (t);
		}
		getline (cin, t);
		string data;
		while (getline (cin, t) && t[0] != '*')
			data += "     " + t + "\n";
		for (string mta2 : mta)
		{
			vector<string>& users = dest[mta2];
			cout << "Connection between " << mta1 << " and " << mta2 << endl;
			cout << "     HELO " << mta1 << "\n"
			     << "     250" << endl;
			cout << "     MAIL FROM:<" << s << ">\n"
			     << "     250" << endl;
			bool flag = false;
			for (string u : users)
			{
				cout << "     RCPT TO:<" << u << ">" << endl;
				if (addr.count (u))
				{
					flag = true;
					cout << "     250" << endl;
				}
				else
					cout << "     550" << endl;
			}
			if (flag)
			{
				cout << "     DATA\n"
				     << "     354\n"
				     << data << "     .\n"
				     << "     250" << endl;
			}
			cout << "     QUIT\n"
			     << "     221" << endl;
		}
	}
	return 0;
}