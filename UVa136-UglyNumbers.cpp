#include <iostream>
#include <queue>
#include <vector>
#include <set>
using namespace std;
const int c[] = {2, 3, 5};

int main()
{
	priority_queue<long long, vector<long long>, greater<long long> > q;
	set<long long> s;
	q.push (1);
	s.insert (1);
	for (int i = 1;; ++i)
	{
		long long x = q.top();
		q.pop();
		if (i == 1500)
		{
			cout << "The 1500'th ugly number is " << x << "." << endl;
			break;
		}
		for (int j = 0; j < 3; ++j)
		{
			long long y = x * c[j];
			if (!s.count (y))
			{
				s.insert (y);
				q.push (y);
			}
		}
	}
	return 0;
}