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
#include <map>

using namespace std;

#define mp make_pair
#define st first
#define nd second
#define ll long long
#define pll pair<long long, long long>
#define pb push_back

int n, m, x, y, step, nextx, nexty;
queue<pair<pair<int, int>, int>> Q;
bool visited[505][505];
char c;
int num[505][505];
int d[4][2] = {
	{0, 1},
	{1, 0},
	{0, -1},
	{-1, 0}};

bool isWithinBounds(int x, int y)
{
	return x >= 1 and x <= n and y >= 1 and y <= m;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
		{
			cin >> c;
			num[i][j] = c - '0';
		}

	Q.push(mp(mp(1, 1), 0));

	while (!Q.empty())
	{
		x = Q.front().st.st;
		y = Q.front().st.nd;
		step = Q.front().nd;
		Q.pop();

		if (visited[x][y])
			continue;

		visited[x][y] = true;

		if (x == n and y == m)
		{
			cout << step << endl;
			return 0;
		}

		for (int i = 0; i < 4; i++)
		{
			nextx = x + d[i][0] * num[x][y];
			nexty = y + d[i][1] * num[x][y];
			if (isWithinBounds(nextx, nexty))
				Q.push(mp(mp(nextx, nexty), step + 1));
		}
	}

	cout << -1 << endl;
	return 0;
}
