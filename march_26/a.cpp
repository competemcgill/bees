#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using query = tuple<ll, int, int>;

constexpr int MN = 512;

int n, m;
ll wtime[MN];
ll ftime[MN][MN];
ll cost[MN][MN];

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m;
  for (int i = 0; i < n; i++)
    cin >> wtime[i];
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) {
      cin >> ftime[i][j];
      cost[i][j] = numeric_limits<ll>::max();
    }
  for (int k = 0; k < n; k++) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (i == j)
          cost[i][j] = 0;
        else if (k == i || k == j)
          cost[i][j] = min(cost[i][j], ftime[i][j]);
        else
          cost[i][j] = min(cost[i][j], ftime[i][k] + wtime[k] + ftime[k][j]);
      }
    }
  }
  vector<query> queries;
  for (int i = 0; i < m; i++) {
    int s, f;
    ll t;
    cin >> s >> f >> t;
    --s, --f;
    queries.emplace_back(t, s, f);
  }
  sort(queries.begin(), queries.end());
  vector<pair<ll, int>> fs;
  for (auto [t, s, f] : queries) {
    int i = -1;
    ll mi = -1;
    for (int j = 0; j < (int)fs.size(); j++) {
      if (fs[j].first > t) continue;
      if (fs[j].second != s && fs[j].first + cost[fs[j].second][s] + wtime[s] > t)
        continue;
      ll ft = t + ftime[s][f] + wtime[f];
      if (mi == -1 || ft < mi) {
        mi = ft;
        i = j;
      }
    }
    //cout << t << ' ' << s << ' ' << f << ' ' << i << ' ' << mi << ' ' << ftime[s][f] + wtime[f] << '\n';
    if (i == -1)
      fs.emplace_back(t + ftime[s][f] + wtime[f], f);
    else
      fs[i] = {mi, f};
  }
  cout << fs.size() << '\n';
  return 0;
}

