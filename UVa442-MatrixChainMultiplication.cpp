#include <iostream>
#include <stack>
#include <string>
#include <cctype>
using namespace std;

struct Matrix
{
	int a, b;
	Matrix (int a = 0, int b = 0) : a (a), b (b) {}
} m[26];

int main()
{
	int n;
	cin >> n;
	while (n--)
	{
		char c;
		cin >> c >> m[c - 'A'].a >> m[c - 'A'].b;
	}
	string expr;
	while (cin >> expr)
	{
		stack<Matrix> s;
		bool error = false;
		int sum = 0;
		for (char c : expr)
		{
			if (isalpha (c))
				s.push (m[c - 'A']);
			else if (c == ')')
			{
				Matrix m1 = s.top();
				s.pop();
				Matrix m2 = s.top();
				s.pop();
				if (m1.a != m2.b)
				{
					error = true;
					break;
				}
				else
				{
					sum += m1.b * m2.a * m2.b;
					s.push (Matrix (m2.a, m1.b));
				}
			}
		}
		if (error)
			cout << "error" << endl;
		else
			cout << sum << endl;
	}
	return 0;
}