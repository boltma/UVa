#include <iostream>
#include <sstream>
#include <stack>
#include <string>
#include <map>
using namespace std;

bool assign(map<string, map<int, int>> &m, const string &s);
void declare(map<string, map<int, int>> &m, const string& s);

int main()
{
	map<string, map<int, int>> m;
	string s;
	while (true)
	{
		int i = 1;
		bool flag = true, flag2 = true;
		m.clear();
		while ((cin >> s) && s != ".")
		{
			flag = false;
			if (s.find('=') == -1)
				declare(m, s);
			else
			{
				if (!assign(m, s))
				{
					cout << i << endl;
					while ((cin >> s) && s != ".");
					flag2 = false;
					break;
				}
			}
			++i;
		}
		if (flag)
			break;
		if (flag2)
			cout << "0" << endl;
	}
	return 0;
}

bool assign(map<string, map<int, int>> &m, const string &s)
{
	int k = s.find('='), l, n;
	string left = s.substr(0, k), right = s.substr(k + 1);
	stack<string> t;
	while ((k = right.find('[') != -1))
	{
		string name = right.substr(0, k);
		t.push(name);
		right = right.substr(k + 1);
	}
	stringstream ss(right);
	ss >> l;
	while (!t.empty())
	{
		string name = t.top();
		if (!m.count(name) || m[name][-1] <= l || !m[name].count(l))
			return false;
		l = m[name][l];
		t.pop();
	}
	while ((k = left.find('[') != -1))
	{
		string name = left.substr(0, k);
		t.push(name);
		left = left.substr(k + 1);
	}
	ss.clear();
	ss.str(left);
	ss >> n;
	while (!t.empty())
	{
		string name = t.top();
		if (t.size() > 1)
		{
			if (!m.count(name) || m[name][-1] <= n || !m[name].count(n))
				return false;
			n = m[name][n];
			t.pop();
		}
		else
		{
			if (!m.count(name) || m[name][-1] <= n)
				return false;
			m[name][n] = l;
			return true;
		}
	}
	return true;
}

void declare(map<string, map<int, int>> &m, const string& s)
{
	int k = s.find('['), l;
	string name = s.substr(0, k), r = s.substr(k + 1);
	stringstream ss(r);
	ss >> l;
	map<int, int> n;
	n[-1] = l;
	m[name] = n;
	return;
}