#include <iostream>
#include <sstream>
#include <string>
using namespace std;
int main()
{
	const int u[6][3] = {{0, 1, 2}, {0, 2, 1}, {1, 0, 2}, {1, 2, 0}, {2, 0, 1}, {2, 1, 0}};
	const char c[] = "BGC";
	unsigned long a[3][3];
	string line;
	while (getline (cin, line))
	{
		stringstream ss (line);
		for (int i = 0; i < 9; ++i)
			ss >> a[i / 3][i % 3];
		unsigned long maxsum = ~0;
		string maxstring;
		for (int i = 0; i < 6; ++i)
		{
			unsigned long sum = 0;
			for (int j = 0; j < 3; ++j)
				for (int k = 0; k < 3; ++k)
					if (j != u[i][k])
						sum += a[j][k];
			if (sum <= maxsum)
			{
				string s;
				for (int j = 0; j < 3; ++j)
					for (int k = 0; k < 3; ++k)
						if (u[i][k] == j)
							s += c[k];
				if (sum < maxsum || (sum == maxsum && s < maxstring))
					maxstring = s;
				maxsum = sum;
			}
		}
		cout << maxstring << " " << maxsum << endl;
	}
	return 0;
}