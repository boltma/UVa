#include <iostream>
#define LEFT(i) ((i) << 1)
#define RIGHT(i) (((i) << 1) + 1)
using namespace std;

int main()
{
	int n;
	cin >> n;
	while (n--)
	{
		int l, k;
		cin >> l >> k;
		int t = 1;
		for (int i = 0; i < l - 1; ++i)
		{
			if (k % 2)
			{
				t = LEFT (t);
				k = (k + 1) / 2;
			}
			else
			{
				t = RIGHT (t);
				k /= 2;
			}
		}
		cout << t << endl;
	}
	return 0;
}