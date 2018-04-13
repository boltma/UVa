#include <iostream>
#include <algorithm>
#include <set>
using namespace std;
const int maxn = 105;
int n;

struct Building
{
	int id;
	double x, y, w, d, h;
	bool operator < (const Building& rhs) const
	{
		return x < rhs.x || (x == rhs.x && y < rhs.y);
	}
} b[maxn];

bool cover (int i, double mx)
{
	return b[i].x <= mx && b[i].x + b[i].w >= mx;
}

bool visible (int i, double mx)
{
	if (!cover (i, mx))
		return false;
	else
		for (int k = 0; k < n; ++k)
			if (b[k].y < b[i].y && cover (k, mx) && b[k].h >= b[i].h)
				return false;
	return true;
}

int main()
{
	int kase = 0;
	set<double> s;
	while (cin >> n && n)
	{
		for (int i = 0; i < n; ++i)
		{
			cin >> (b + i)->x >> (b + i)->y >> (b + i)->w >> (b + i)->d >> (b + i)->h;
			s.insert ( (b + i)->x);
			s.insert ( (b + i)->x + (b + i)->w);
			b[i].id = i + 1;
		}
		sort (b, b + n);
		if (kase++)
			cout << endl;
		cout << "For map #" << kase << ", the visible buildings are numbered as follows:" << endl
		     << b[0].id;
		for (int i = 1; i < n; ++i)
		{
			bool vis = false;
			for (auto it = s.begin(); it != --s.end();)
			{
				if (visible (i, (*it + * (++it)) / 2))
				{
					vis = true;
					break;
				}
			}
			if (vis)
				cout << " " << b[i].id;
		}
		cout << endl;
	}
	return 0;
}