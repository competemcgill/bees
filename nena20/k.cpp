#include <bits/stdc++.h>
using namespace std;

int fr[30][30];
vector<int> g[30];
int dp[30];

void dfs(int u) {
  if (dp[u] > 0)
    return;
  for (int v : g[u]) {
    dfs(v);
    dp[u] = max(dp[u], dp[v]);
  }
  dp[u]++;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, sz;
  cin >> n >> sz;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    for (char &c : s)
      c -= 'A';
    for (int j = 1; j < sz; j++) {
      for (int k = 0; k < j; k++) {
        fr[s[j]][s[k]]++;
      }
    }
  }
  for (int i = 0; i < sz; i++) {
    for (int j = 0; j < sz; j++) {
      if (fr[i][j] == n)
        g[i].push_back(j);
    }
  }
  int res = 0;
  for (int i = 0; i < sz; i++) {
    if (dp[i] == 0) {
      dfs(i);
    }
    res = max(res, dp[i]);
  }
  cout << res << '\n';
  return 0;
}

