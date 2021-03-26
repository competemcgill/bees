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

int n, newSum = 1e5;
int roundedW[105], last[100005];
double w[105], sum;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	while (true)
	{
		cin >> n;
		if (!n)
			break;

		sum = 0;
		for (int i = 1; i <= n; i++)
		{
			cin >> w[i];
			sum += w[i];
		}

		for (int i = 1; i <= n; i++)
			roundedW[i] = ceil(w[i] * newSum / sum);

		memset(last, 0, sizeof last);

		last[0] = -1;

		for (int i = 1; i <= n; i++)
			for (int j = newSum / 2; j >= 0; j--)
			{
				if (!last[j])
					continue;

				last[j + roundedW[i]] = i;
			}

		for (int i = newSum / 2; i >= 0; i--)
		{
			if (last[i])
			{
				while (i)
				{
					cout << last[i] << ' ';
					i = i - roundedW[last[i]];
				}
				cout << endl;
				break;
			}
		}
	}

	return 0;
}
