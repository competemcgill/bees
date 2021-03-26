#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

const int MN = 412;
const int MK = 20;

int n, k;
int a[MN];
int dp[(1 << MK) + 12];

int get_id(char c) {
  static int index = 0;
  static map<char, int> m;
  if (m.count(c) == 0)
    m[c] = index++;
  return m[c];
}

int ds(int msk) {
  if (msk == 0)
    return 0;
  if (dp[msk] > 0)
    return dp[msk];
  int cost[MK] = {0};
  int last = -1;
  for (int i = 0; i < n; i++) {
    if (!((msk >> a[i]) & 1)) continue;
    if (a[i] != last)
      cost[a[i]]++;
    last = a[i];
  }
  dp[msk] = n;
  for (int i = 0; i < k; i++) {
    if (cost[i] == 0) continue;
    dp[msk] = min(dp[msk], cost[i] + ds(msk ^ (1 << i)));
  }
  return dp[msk];
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> k;
  string s;
  cin >> s;
  for (int i = 0; i < n; i++)
    a[i] = get_id(s[i]);
  int res = n;
  for (int i = 0; i < k; i++)
    res = min(res, ds((1 << k) - 1));
  cout << res << '\n';
  return 0;
}

