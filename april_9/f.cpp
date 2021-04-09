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

int N, H, mn = 200000, ct;
int bot[500005], top[500005];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> H;

    for (int i = 1; i <= N; i++)
    {
        int h;
        cin >> h;
        if (i % 2)
            bot[h]++;
        else
            top[H - h + 1]++;
    }

    for (int i = H - 1; i >= 1; i--)
        bot[i] += bot[i + 1];
    for (int i = 2; i <= H; i++)
        top[i] += top[i - 1];

    for (int i = 1; i <= H; i++)
    {
        int numObstacles = bot[i] + top[i];
        if (numObstacles < mn)
        {
            mn = numObstacles;
            ct = 1;
        }
        else if (numObstacles == mn)
            ct++;
    }

    cout << mn << ' ' << ct << endl;

    return 0;
}
