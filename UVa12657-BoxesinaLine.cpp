#include <iostream>
#include <algorithm>
#define LOCAL
using namespace std;
const int maxn = 100005;
int left[maxn], right[maxn];

void link (int L, int R)
{
	::right[L] = R;
	::left[R] = L;
	return;
}

int main()
{
#ifdef LOCAL
	freopen ("D:/in.txt", "r", stdin);
	freopen ("D:/out.txt", "w", stdout);
#endif
	int m, n, kase = 0;
	while (cin >> n >> m)
	{
		for (int i = 1; i <= n; ++i)
		{
			::left[i] = i - 1;
			::right[i] = (i + 1) % (n + 1);
		}
		::left[0] = n;
		::right[0] = 1;
		bool inv = false;
		int x, y, cmd;
		while (m--)
		{
			cin >> cmd;
			int l;
			if (cmd != 4)
				cin >> x >> y;
			if (cmd < 3 && inv)
				cmd = 3 - cmd;
			switch (cmd)
			{
			case 1:
				if (::left[y] == x)
					break;
				l = ::left[y];
				link (::left[x], ::right[x]);
				link (x, y);
				link (l, x);
				break;
			case 2:
				if (::right[y] == x)
					break;
				l = ::right[y];
				link (::left[x], ::right[x]);
				link (y, x);
				link (x, l);
				break;
			case 3:
				int lx, rx, ly, ry;
				lx = ::left[x];
				ly = ::left[y];
				rx = ::right[x];
				ry = ::right[y];
				::left[rx] = ::right[lx] = y;
				::left[ry] = ::right[ly] = x;
				swap (::left[x], ::left[y]);
				swap (::right[x], ::right[y]);
				break;
			case 4:
				inv = !inv;
				break;
			}
		}
		long long sum = 0;
		int b = 0;
		for (int i = 1; i <= n; ++i)
		{
			if (!inv)
				b = ::right[b];
			else
				b = ::left[b];
			if (i % 2 == 1)
				sum += b;
		}
		cout << "Case " << ++kase << ": " << sum << endl;
	}
	return 0;
}