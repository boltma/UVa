#include <iostream>
#include <algorithm>
#include <vector>
#define LOCAL
using namespace std;

struct point
{
	int x, y;
	point (int x = 0, int y = 0) : x (x), y (y) {}
	bool operator < (const point& b) const
	{
		if (x != b.x)
			return x < b.x;
		else
			return y < b.y;
	}
	bool operator == (const point& b) const
	{
		return x == b.x && y == b.y;
	}
	bool operator!= (const point &b) const
	{
		return ! (*this == b);
	}
};

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
		int n;
		cin >> n;
		vector<point> v;
		while (n--)
		{
			int a, b;
			cin >> a >> b;
			v.push_back (point (a, b));
		}
		sort (v.begin(), v.end());
		int s, t;
		if (v.size() % 2 == 1)
		{
			s = 2 * v[v.size() / 2].x;
			t = v.size() / 2;
		}
		else
		{
			s = v[v.size() / 2 - 1].x + v[v.size() / 2].x;
			t = v.size() / 2;
		}
		while (t < v.size() && 2 * v[t].x == s)
			++t;
		vector<point> v2;
		for (int i = t; i < v.size(); ++i)
		{
			point temp = v[i];
			temp.x = s - temp.x;
			v2.push_back (temp);
		}
		sort (v2.begin(), v2.end());
		bool flag = true;
		for (int i = 0; i < v2.size(); ++i)
		{
			if (v2[i] != v[i])
			{
				cout << "NO" << endl;
				flag = false;
				break;
			}
		}
		if (flag)
			cout << "YES" << endl;
	}
	return 0;
}