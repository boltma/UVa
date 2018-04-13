#include <iostream>
#include <vector>
#include <set>
#include <math.h>
#define LOCAL
using namespace std;
int main()
{
#ifdef LOCAL
	freopen ("D:/in.txt", "r", stdin);
	freopen ("D:/out.txt", "w", stdout);
#endif
	int n;
	cin >> n;
	while (n--)
	{
		int m, size;
		cin >> m;
		size = m;
		vector<int> v;
		set<vector<int>> s;
		while (m--)
		{
			int k;
			cin >> k;
			v.push_back (k);
		}
		s.insert (v);
		bool flag_loop = false, flag_zero = false;
		vector<int> currv;
		for (int i = 1; i <= 1000; ++i)
		{
			currv = v;
			bool flag = true;
			for (int j = 0; j < size; j++)
			{
				if (j != size - 1)
					v[j] = abs (currv[j + 1] - currv[j]);
				else
					v[j] = abs (currv[0] - currv[j]);
				if (v[j])
					flag = false;
			}
			if (flag)
			{
				flag_zero = true;
				break;
			}
			if (s.count (v))
			{
				flag_loop = true;
				break;
			}
			else
				s.insert (v);
		}
		if (flag_loop)
			cout << "LOOP" << endl;
		else if (flag_zero)
			cout << "ZERO" << endl;
	}
	return 0;
}