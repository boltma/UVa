#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

int main()
{
	int n, a[10];
	bool flag = true;
	while (cin >> n && n)
	{
		if (flag)
			flag = false;
		else
			cout << endl;
		bool flag3 = true;
		for (int i = 0; i < 100000; ++i)
		{
			int k = n * i;
			if (k > 100000)
				break;
			memset(a, 0, sizeof(a));
			int l = k;
			bool flag2 = true;
			for (int j = 0; flag2 && j < 5; ++j)
			{
				int m = l % 10;
				if (a[m] == 0)
					a[m] = 1;
				else
					flag2 = false;
				l /= 10;
			}
			l = i;
			for (int j = 0; flag2 && j < 5; ++j)
			{
				int m = l % 10;
				if (a[m] == 0)
					a[m] = 1;
				else
					flag2 = false;
				l /= 10;
			}
			if (flag2)
			{
				cout << k << " / " << setw(5) << setfill('0') << i << " = " << n << endl;
				flag3 = false;
			}
		}
		if (flag3)
			cout << "There are no solutions for " << n << "." << endl;
	}
	return 0;
}