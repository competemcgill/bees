#include <algorithm>
#include <iostream>
#include <cassert>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <string>
#include <vector>
#include <cmath>
#include <ctime>
#include <queue>
#include <stack>
#include <unordered_set>

using namespace std;

#define mp make_pair
#define st first
#define nd second
#define ll long long
#define pll pair<long long, long long>
#define pb push_back

int n, k, ans;

unordered_set<string> marked;

string str;

void transform()
{
	string temp;
	for (int i = 0; i < str.size(); i++)
	{
		if (i)
		{
			if (str[i - 1] == str[i])
				temp += 'B';
			else
				temp += 'W';
		}
		else
		{
			if (str[0] == str[str.size() - 1])
				temp += 'B';
			else
				temp += 'W';
		}
	}
	str = temp;
}

void mark(string str)
{
	marked.insert(str);
	for (int i = 1; i < str.size(); i++)
	{
		string rotated_str;
		for (int j = i; j < str.size(); j++)
			rotated_str += str[j];
		for (int j = 0; j < i; j++)
			rotated_str += str[j];
		marked.insert(rotated_str);
	}
}

void f(string str, int x)
{
	if (x == 0)
	{
		if (marked.find(str) == marked.end())
		{
			mark(str);
			ans++;
		}
		return;
	}

	string new_str;

	if (str[0] == 'B')
		new_str += "BB";
	else
		new_str += "BW";

	for (int i = 1; i < str.size() - 1; i++)
	{
		if (str[i] == 'B')
			new_str += new_str[i];
		else
			new_str += new_str[i] == 'B' ? 'W' : 'B';
	}

	if ((str[str.size() - 1] == 'B' and new_str[0] == new_str[new_str.size() - 1]) or
		(str[str.size() - 1] == 'W' and new_str[0] != new_str[new_str.size() - 1]))
		f(new_str, x - 1);

	new_str = "";

	if (str[0] == 'B')
		new_str += "WW";
	else
		new_str += "WB";

	for (int i = 1; i < str.size() - 1; i++)
	{
		if (str[i] == 'B')
			new_str += new_str[i];
		else
			new_str += new_str[i] == 'B' ? 'W' : 'B';
	}

	if ((str[str.size() - 1] == 'B' and new_str[0] == new_str[new_str.size() - 1]) or
		(str[str.size() - 1] == 'W' and new_str[0] != new_str[new_str.size() - 1]))
		f(new_str, x - 1);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> k;

	cin >> str;

	for (int i = 1; i <= k; i++)
		transform();

	f(str, k);

	cout << ans;

	return 0;
}
