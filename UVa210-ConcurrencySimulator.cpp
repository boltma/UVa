#include <iostream>
#include <queue>
#include <string>
#include <deque>
#include <vector>
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
	while (kase--)
	{
		int n, t1, t2, t3, t4, t5, Q;
		cin >> n >> t1 >> t2 >> t3 >> t4 >> t5 >> Q;
		deque<int> rq;
		queue<int> bq;
		int var[26] = {0};
		bool lock = false;
		vector<queue<string>> v (n);
		for (int i = 0; i < n; ++i)
		{
			string cmd;
			do
			{
				getline (cin, cmd);
				v[i].push (cmd);
			}
			while (cmd != "end");
			rq.push_back (i + 1);
		}
		while (!rq.empty())
		{
			int t_left = Q, cur = rq.front();
			rq.pop_front();
			queue<string> &q = v[cur - 1];
			bool flag_end = false, flag_block = false;
			while (t_left > 0)
			{
				string cmd;
				cmd = q.front();
				if (cmd.length() < 2)
				{
					q.pop();
					continue;
				}
				if (cmd[2] != 'c')
					q.pop();
				switch (cmd[2])
				{
				case 'd':
					t_left = 0;
					flag_end = true;
					break;
				case 'l':
					if (!bq.empty())
					{
						rq.push_front (bq.front());
						bq.pop();
					}
					lock = false;
					t_left -= t4;
					break;
				case 'c':
					if (!lock)
					{
						lock = true;
						t_left -= t3;
						q.pop();
					}
					else
					{
						t_left = 0;
						bq.push (cur);
						flag_block = true;
					}
					break;
				case 'i':
					cout << cur << ": " << var[cmd[6] - 'a'] << endl;
					t_left -= t2;
					break;
				case '=':
					int x = cmd[4] - '0';
					if (cmd.length() == 6)
						x = x * 10 + (cmd[5] - '0');
					var[cmd[0] - 'a'] = x;
					t_left -= t1;
					break;
				}
			}
			if (!flag_end && !flag_block)
				rq.push_back (cur);
		}
		if (kase)
			cout << endl;
	}
	return 0;
}