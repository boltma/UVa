#include <iostream>
#include <stack>
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
		int a;
		while (cin >> a && a)
		{
			queue<int> q;
			stack<int> s;
			q.push (a);
			for (int i = 1; i < n; ++i)
			{
				int b;
				cin >> b;
				q.push (b);
			}
			int k = 1;
			bool flag = true;
			while (!q.empty())
			{
				if (k == q.front())
				{
					q.pop();
					++k;
				}
				else if (!s.empty() && s.top() == q.front())
				{
					q.pop();
					s.pop();
				}
				else if (k <= n)
					s.push (k++);
				else
				{
					flag = false;
					break;
				}
			}
			cout << (flag ? "Yes" : "No") << endl;
		}
		cout << endl;
	}
	return 0;
}