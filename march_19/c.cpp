#include <bits/stdc++.h>
using namespace std;

int dx[] = {-1,1,0,0,0};
int dy[] = {0,0,-1,1,0};
bool vis[50][50][50];

int normalize(int x, int m) {
  return (x % m + m) % m;
}

void solve() {
  memset(vis, 0, sizeof(vis));
  int limit;
  cin >> limit;
  int n, m;
  cin >> n >> m;
  n += 2;
  vector<string> grid(n);
  for (string &s : grid)
    cin >> s;
  pair<int, int> src, dst;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (grid[i][j] == 'G')
        dst = {i, j};
      else if (grid[i][j] == 'F')
        src = {i, j};
    }
  }
  auto good = [&](int x, int y, int t) -> bool {
    if (vis[x][y][t % m])
      return false;
    int sy = -1;
    if (x == 0 || x == n - 1) {
      sy = y;
    } else {
      int d = ((n - x) % 2 == 0) ? 1 : -1;
      sy = normalize(y - d * t, m);
    }
    return grid[x][sy] != 'X' && abs(x - dst.first) + abs(y - dst.second) <= limit - t;
  };
  queue<pair<pair<int, int>, int>> q;
  q.push({src, 0});
  vis[src.first][src.second][0] = true;
  while (!q.empty()) {
    auto [u, t] = q.front();
    q.pop();
    if (u == dst) {
      cout << "The minimum number of turns is " << t << ".\n";
      return;
    }
    if (t == limit)
      continue;
    for (int i = 0; i < 5; i++) {
      int x = u.first + dx[i];
      int y = u.second + dy[i];
      if (x < 0 || x >= n) continue;
      if (y < 0 || y >= m) continue;
      if (!good(x, y, t + 1)) continue;
      vis[x][y][(t + 1) % m] = true;
      q.push({{x, y}, t + 1});
    }
  }
  cout << "The problem has no solution.\n";
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--)
    solve();
  return 0;
}

