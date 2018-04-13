#include <iostream>
#include <queue>
#include <map>
using namespace std;
#define LOCAL

const int maxt = 1000 + 10;

int main()
{
#ifdef LOCAL
	freopen ("D:/in.txt", "r", stdin);
	freopen ("D:/out.txt", "w", stdout);
#endif
	ios::sync_with_stdio (false);
	cin.tie (0);
	int t, kase = 0;
	while (cin >> t && t)
	{
		cout << "Scenario #" << ++kase << endl;
		map<int, int> team;
		for (int i = 0; i < t; ++i)
		{
			int n, x;
			cin >> n;
			while (n--)
			{
				cin >> x;
				team[x] = i;
			}
		}
		queue<int> q, q2[maxt];
		string cmd;
		bool flag = true;
		while (flag)
		{
			cin >> cmd;
			switch (cmd[0])
			{
			case 'S':
				flag = false;
				break;
			case 'D':
				int m;
				m = q.front();
				cout << q2[m].front() << endl;
				q2[m].pop();
				if (q2[m].empty())
					q.pop();
				break;
			case 'E':
				int x;
				cin >> x;
				m = team[x];
				if (q2[m].empty())
					q.push (m);
				q2[m].push (x);
				break;
			}
		}
		cout << endl;
	}
	return 0;
}