#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <sstream>
#include <algorithm>
#define LOCAL
using namespace std;

struct Book
{
	string name, author;
	Book (string x, string y) : name (x), author (y) {}
	bool operator < (const Book& b) const
	{
		return author < b.author || (author == b.author && name < b.name);
	}
};

int main()
{
#ifdef LOCAL
	freopen ("D:/in.txt", "r", stdin);
	freopen ("D:/out.txt", "w", stdout);
#endif
	string line;
	vector<Book> Bookcache;
	map<string, int> IDcache;
	set<int> shelf;
	while (getline (cin, line))
	{
		stringstream ss (line);
		char c = ss.get();
		if (c == 'E')
			break;
		string book_name, temp, book_author;
		getline (ss, book_name, '"');
		ss.get();
		getline (ss, temp, ' ');
		getline (ss, book_author);
		Book B (book_name, book_author);
		Bookcache.push_back (B);
	}
	sort (Bookcache.begin(), Bookcache.end());
	int cnt = 0;
	for (auto it = Bookcache.begin(); it != Bookcache.end(); ++it, ++cnt)
	{
		IDcache[it->name] = cnt;
		shelf.insert (cnt);
	}
	set<int> book_return;
	while (getline (cin, line))
	{
		stringstream ss (line);
		string command;
		ss >> command;
		if (command[0] == 'E')
			break;
		string book_name;
		if (command[0] != 'S')
		{
			ss.get();
			ss.get();
			getline (ss, book_name, '"');
		}
		switch (command[0])
		{
		case 'B':
			shelf.erase (IDcache[book_name]);
			break;
		case 'R':
			book_return.insert (IDcache[book_name]);
			break;
		case 'S':
			for (int i : book_return)
			{
				cout << "Put \"" << Bookcache[i].name << "\" ";
				auto it = upper_bound (shelf.begin(), shelf.end(), i);
				int x = distance (shelf.begin(), it);
				if (!x)
					cout << "first" << endl;
				else
					cout << "after \"" << Bookcache[* (--it)].name << "\"" << endl;
				shelf.insert (i);
			}
			cout << "END" << endl;
			book_return.clear();
			break;
		}
	}
	return 0;
}