#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#define LOCAL
using namespace std;
const int maxcol = 60;

int main()
{
#ifdef LOCAL
	freopen ("D:/in.txt", "r", stdin);
	freopen ("D:/out.txt", "w", stdout);
#endif
	int n;
	while (cin >> n)
	{
		int M = 0;
		vector<string> filenames;
		string file_name;
		for (int i = 0; i < n; ++i)
		{
			cin >> file_name;
			if (file_name.length() > M)
				M = file_name.length();
			filenames.push_back (file_name);
		}
		sort (filenames.begin(), filenames.end());
		int cols = (maxcol - M) / (M + 2) + 1, rows = ceil (static_cast<double> (n) / cols);
		for (int i = 0; i < 60; ++i)
			cout << "-";
		cout << endl;
		for (int r = 0; r < rows; ++r)
		{
			string line;
			for (int c = 0; c < cols; ++c)
			{
				int index = c * rows + r;
				if (index < n)
				{
					if (c)
						line += "  ";
					line += filenames[index];
				}
				else
					continue;
				int num = M - filenames[index].length();
				line.insert (line.end(), num, ' ');
			}
			cout << line << endl;
		}
	}
	return 0;
}