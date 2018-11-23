#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <string>
#include <utility>
#include <vector>
using namespace std;
const double EPS = 1e-6;

double dist(const pair<double, double> &a, const pair<double, double> &b)
{
	double x = a.first - b.first, y = a.second - b.second;
	return sqrt(x * x + y * y);
}

pair<double, double> p;

struct MAP
{
	string name;
	double x1, x2, y1, y2, area, ratio;
	pair<double, double> centre;
	int level = 0;
	MAP(string name, double _x1, double _x2, double _y1, double _y2) : name(name), x1(_x1), x2(_x2), y1(_y1), y2(_y2)
	{
		if (x1 > x2)
			swap(x1, x2);
		if (y1 > y2)
			swap(y1, y2);
		centre = make_pair((x1 + x2) / 2, (y1 + y2) / 2);
		area = (x2 - x1) * (y2 - y1);
		ratio = (y2 - y1) / (x2 - x1);
	}
	bool operator< (const MAP &b) const
	{
		return area > b.area;
		double d1 = dist(centre, p), d2 = dist(b.centre, p);
		if (fabs(d1 - d2) > EPS)
			return d1 < d2;
		d1 = fabs(ratio - 0.75), d2 = fabs(b.ratio - 0.75);
		if (fabs(d1 - d2) > EPS)
			return d1 < d2;
		d1 = dist(make_pair(x2, y1), p), d2 = dist(make_pair(b.x2, b.y1), p);
		if (fabs(d1 - d2) > EPS)
			return d1 < d2;
		return x1 < b.x1;
	}
};

bool contain(const MAP &a, const pair<double, double> &p)
{
	return p.first >= a.x1 && p.first <= a.x2 && p.second >= a.y1 && p.second <= a.y2;
}

int main()
{
	string name;
	vector<MAP> v;
	cin >> name;
	while (cin >> name && name != "LOCATIONS")
	{
		double x1, x2, y1, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		MAP m(name, x1, x2, y1, y2);
		v.push_back(m);
	}
	map<string, pair<double, double>> loc;
	while (cin >> name && name != "REQUESTS")
	{
		double x, y;
		cin >> x >> y;
		loc[name] = make_pair(x, y);
	}
	while (cin >> name && name != "END")
	{
		int l;
		cin >> l;
		cout << name << " at detail level " << l << ' ';
		if (!loc.count(name))
		{
			cout << "unknown location" << endl;
			continue;
		}
		p = loc[name];
		vector<MAP> u;
		for (auto &m : v)
			if (contain(m, p))
				u.push_back(m);
		if (u.empty())
		{
			cout << "no map contains that location" << endl;
			continue;
		}
		sort(u.begin(), u.end());
		double a;
		int i = 1;
		vector<int> id;
		a = u[0].area;
		for (int j = 0; j < u.size(); ++j)
		{
			MAP m = u[j];
			if (fabs(m.area - a) < EPS)
				m.level = i;
			else
			{
				id.push_back(j - 1);
				m.level = ++i;
				a = m.area;
			}
		}
		if (id.size() + 1 < l)
		{
			cout << "no map at that detail level; ";
			i = id.empty() ? 0 : id.back() + 1;
		}
		else
		{
			i = l == 1 ? 0 : id[l - 2] + 1;
		}
		cout << "using " << u[i].name << endl;
	}
	return 0;
}