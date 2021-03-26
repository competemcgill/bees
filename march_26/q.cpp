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
#include <cassert>
#include <unordered_map>

using namespace std;

#define mp make_pair
#define st first
#define nd second
#define ll long long
#define pll pair<long long, long long>
#define pb push_back

int n, idCount = 0, node_id, neighbour_id, src, dst;
string str, node_str, neighbour_str;
unordered_map<string, int> name_to_id;
unordered_map<int, string> id_to_name;
vector<int> adj_list[1050000];
bool visited[1050000];
int to[1050000];

int dfs(int cur)
{
	if (cur == dst)
		return true;

	for (int neighbour : adj_list[cur])
	{
		if (!visited[neighbour])
		{
			visited[neighbour] = true;
			if (dfs(neighbour))
			{
				to[cur] = neighbour;
				return true;
			}
		}
	}

	return false;
}

int main()
{
	memset(to, -1, sizeof to);
	cin >> n;
	getchar();

	for (int i = 0; i < n; i++)
	{
		getline(cin, str);

		node_str = "";
		int j = 0;
		for (; j < str.size(); j++)
		{
			if (str[j] == ' ')
			{
				while (j < str.size() and str[j] == ' ')
					j++;
				break;
			}
			node_str += str[j];
		}

		if (name_to_id.find(node_str) == name_to_id.end())
		{
			id_to_name[idCount] = node_str;
			name_to_id[node_str] = idCount++;
		}
		node_id = name_to_id[node_str];

		neighbour_str = "";
		for (; j < str.size(); j++)
		{
			if (str[j] == ' ')
			{
				if (name_to_id.find(neighbour_str) == name_to_id.end())
				{
					id_to_name[idCount] = neighbour_str;
					name_to_id[neighbour_str] = idCount++;
				}
				neighbour_id = name_to_id[neighbour_str];

				adj_list[node_id].pb(neighbour_id);
				adj_list[neighbour_id].pb(node_id);

				neighbour_str = "";
				while (j < str.size() and str[j] == ' ')
					j++;
				j--;
				continue;
			}

			neighbour_str += str[j];
		}

		if (neighbour_str.size())
		{
			if (name_to_id.find(neighbour_str) == name_to_id.end())
			{
				id_to_name[idCount] = neighbour_str;
				name_to_id[neighbour_str] = idCount++;
			}
			neighbour_id = name_to_id[neighbour_str];

			adj_list[node_id].pb(neighbour_id);
			adj_list[neighbour_id].pb(node_id);
			neighbour_str = "";
		}
	}

	cin >> str;
	if (name_to_id.find(str) == name_to_id.end())
	{
		cout << "no route found";
		return 0;
	}
	src = name_to_id[str];

	cin >> str;
	if (name_to_id.find(str) == name_to_id.end())
	{
		cout << "no route found";
		return 0;
	}
	dst = name_to_id[str];

	visited[src] = true;
	if (dfs(src))
	{
		int cur = src;
		while (true)
		{
			assert(cur != -1);
			cout << id_to_name[cur];
			if (cur != dst)
			{
				cout << ' ';
				cur = to[cur];
			}
			else
				break;
		}
	}
	else
		cout << "no route found";

	cout << endl;

	return 0;
}
