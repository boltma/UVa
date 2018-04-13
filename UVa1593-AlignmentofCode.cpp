#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#define LOCAL
using namespace std;
int main()
{
#ifdef LOCAL
	freopen ("D:/in.txt", "r", stdin);
	freopen ("D:/out.txt", "w", stdout);
#endif
	vector<vector<string>> code;
	vector<int> len;
	string line;
	unsigned line_cnt = 0;
	while (getline (cin, line))
	{
		vector<string> temp;
		int cnt = 1;
		stringstream ss (line);
		string word;
		line_cnt++;
		while (ss >> word)
		{
			temp.push_back (word);
			if (len.size() < cnt)
				len.push_back (word.size());
			else
			{
				if (len[cnt - 1] < word.size())
					len[cnt - 1] = word.size();
			}
			cnt++;
		}
		code.push_back (temp);
	}
	for (auto l : code)
	{
		unsigned sum = 0, currsum = 0, cnt = 0;
		string line_out;
		for (string s : l)
		{
			if (cnt)
				sum++;
			line_out.append (sum - currsum, ' ');
			line_out += s;
			currsum = sum + s.size();
			sum += len[cnt++];
		}
		cout << line_out << endl;
	}
	return 0;
}