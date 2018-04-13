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
	int kase;
	cin >> kase;
	while (kase--)
	{
		priority_queue<int> pq;
		queue<int> q;
		int n, index;
		cin >> n >> index;
		while (n--)
		{
			int m;
			cin >> m;
			pq.push (m);
			q.push (m);
		}
		int count = 0, cur_index = index;
		bool flag = true;
		while (flag)
		{
			if (pq.top() != q.front())
			{
				int m = q.front();
				q.pop();
				q.push (m);
				if (cur_index == 0)
					cur_index = q.size();
			}
			else
			{
				pq.pop();
				q.pop();
				count++;
				if (cur_index == 0)
				{
					flag = false;
				}
			}
			--cur_index;
		}
		cout << count << endl;
	}
	return 0;
}