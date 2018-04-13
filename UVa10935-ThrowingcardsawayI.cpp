#include <iostream>
#include <queue>
#define LOCAL
using namespace std;
int main()
{
#ifdef LOCAL
	freopen ("D:/in.txt", "r", stdin);
	freopen ("D:/out.txt", "w", stdout);
#endif
	int n;
	while (cin >> n && n)
	{
		queue<int> q;
		for (int i = 1; i <= n; ++i)
			q.push (i);
		cout << "Discarded cards:";
		bool flag = true;
		if (q.size() == 1)
		{
			cout << "\nRemaining card: 1" << endl;
			continue;
		}
		cout << " ";
		while (!q.empty())
		{
			int x = q.front();
			q.pop();
			if (flag)
			{
				cout << x;
				if (q.size() != 1 && q.size() != 0)
					cout << ", ";
				else if (q.size() == 1)
					cout << "\nRemaining card: ";
				else if (q.size() == 0)
					cout << endl;
			}
			else
				q.push (x);
			flag = !flag;
		}
	}
	return 0;
}