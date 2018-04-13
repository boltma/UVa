#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <sstream>
#define LOCAL
using namespace std;
const int maxn = 10005, maxm = 105;
const int BIG = 100000;
int database[maxn][maxm];

int main()
{
#ifdef LOCAL
	freopen ("D:/in.txt", "r", stdin);
	freopen ("D:/out.txt", "w", stdout);
#endif
	int n, m;
	while (cin >> n >> m && n)
	{
		getchar();
		vector<string> Scache;
		map<string, int> IDcache;
		for (int i = 1; i <= n; ++i)
		{
			string line;
			getline (cin, line);
			stringstream ss (line);
			for (int j = 1; j <= m; ++j)
			{
				string s;
				getline (ss, s, ',');
				if (!IDcache.count (s))
				{
					Scache.push_back (s);
					IDcache[s] = Scache.size();
				}
				database[i][j] = IDcache[s];
			}
		}
		bool flag = true;
		for (int c1 = 1; c1 <= m - 1; ++c1)
		{
			for (int c2 = c1 + 1; c2 <= m; ++c2)
			{
				map<int, int> Mcache;
				for (int r = 1; r <= n; ++r)
				{
					int x = BIG * database[r][c1] + database[r][c2];
					if (!Mcache.count (x))
						Mcache[x] = r;
					else
					{
						cout << "NO" << endl;
						cout << Mcache[x] << " " << r << endl;
						cout << c1 << " " << c2 << endl;
						flag = false;
						break;
					}
				}
				if (!flag)
					break;
			}
			if (!flag)
				break;
		}
		if (flag)
			cout << "YES" << endl;
	}
	return 0;
}