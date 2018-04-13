#include<iostream>
#include<string>
#include<vector>
using namespace std;

const int maxn = 30;
int n;
vector<int> pile[maxn];

void find_block (int a, int &p, int &h)
{
	for (p = 0; p < n; p++)
		for (h = 0; h < pile[p].size(); h++)
			if (pile[p][h] == a)
				return;
}

void clear_block (int p, int h)
{
	const auto it = pile[p].end() - 1;
	for (int i = 0; i < it - pile[p].begin() - h; ++i)
	{
		int a = * (it - i);
		pile[p].pop_back();
		pile[a].push_back (a);
	}
	return;
}

void pile_block (int p1, int h, int p2)
{
	for (auto it = pile[p1].begin() + h; it != pile[p1].end(); ++it)
		pile[p2].push_back (*it);
	pile[p1].resize (h);
	return;
}

int main()
{
	int a, b;
	string s1, s2;
	cin >> n;
	for (int i = 0; i < n; ++i)
		pile[i].push_back (i);
	while (cin >> s1 >> a >> s2 >> b)
	{
		int pa, pb, ha, hb;
		find_block (a, pa, ha);
		find_block (b, pb, hb);
		if (pa == pb)
			continue;
		if (s1 == "move")
			clear_block (pa, ha);
		if (s2 == "onto")
			clear_block (pb, hb);
		pile_block (pa, ha, pb);
	}
	for (int i = 0; i < n; ++i)
	{
		cout << i << ":";
		for (auto it = pile[i].begin(); it != pile[i].end(); ++it)
			cout << " " << *it;
		cout << endl;
	}
	return 0;
}