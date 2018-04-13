#include <iostream>
#include <map>
#define LOCAL
using namespace std;

const int BASE = 10000;

int main()
{
#ifdef LOCAL
	freopen ("D:/in.txt", "r", stdin);
	freopen ("D:/out.txt", "w", stdout);
#endif
	int n;
	while (cin >> n && n)
	{
		map<int, int> m;
		while (n--)
		{
			int a, b;
			cin >> a >> b;
			int x = BASE * a + b, y = BASE * b + a;
			if (m.count (x))
			{
				if (m[x] == 1)
					m.erase (x);
				else
					m[x] -= 1;
			}
			else
			{
				if (m.count (y))
					m[y] += 1;
				else
					m[y] = 1;
			}
		}
		if (m.empty())
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}