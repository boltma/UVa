#include <algorithm>
#include <iostream>
#include <map>
#include <utility>
#include <vector>
#define LOCAL
using namespace std;

bool cmp(const vector<int> &a, const vector<int> &b, int n)
{
	//judge whether a could be put into b
	for (int i = 0; i < n; ++i)
		if (a[i] >= b[i])
			return false;
	return true;
}

void dp(vector<int> &u, vector<int> &w, const map<pair<int, int>, bool> &m, int i)
{
	if (u[i])
		return;
	u[i] = -1; //mark that u[i] is being computed, in case of infinite loop
	int k = u.size(), max = 1, t = -1;
	for (int j = 0; j < k; ++j)
	{
		if (j == i)
			continue;
		if (m.at(make_pair(i, j)))
		{
			dp(u, w, m, j);
			if (u[j] == -1)
				continue; //u[j] is still being computed
			if (u[j] + 1 > max)
			{
				max = u[j] + 1;
				t = j;
			}
		}
	}
	u[i] = max;
	w[i] = t;
	return;
}

int main()
{
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int k, n;
	while (cin >> k >> n)
	{
		vector<vector<int>> v(k);
		for (int i = 0; i < k; ++i)
		{
			v[i].resize(n);
			for (int j = 0; j < n; ++j)
				cin >> v[i][j];
			sort(v[i].begin(), v[i].end());
		}
		map<pair<int, int>, bool> m;
		for (int i = 0; i < k - 1; ++i)
			for (int j = i + 1; j < k; ++j)
			{
				if (cmp(v[i], v[j], n))
					m[make_pair(i, j)] = true;
				else
					m[make_pair(i, j)] = false;
				if (cmp(v[j], v[i], n))
					m[make_pair(j, i)] = true;
				else
					m[make_pair(j, i)] = false;
			}
		vector<int> u(k), w(k);
		for (int i = 0; i < k; ++i)
			dp(u, w, m, i);
		auto it = max_element(u.begin(), u.end());
		int i = it - u.begin();
		cout << *it << endl;
		bool flag = false;
		do
		{
			if (flag)
				cout << ' ';
			else
				flag = true;
			cout << i + 1;
			i = w[i];
		}
		while (i != -1);
		cout << endl;
	}
}