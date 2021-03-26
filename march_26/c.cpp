#include <bits/stdc++.h>
using namespace std;

const int MN = 30;

int dx[] = {-1, -1, 1, 1};
int dy[] = {-1, 1, -1, 1};

int n;
char grid[MN][MN];
map<pair<int, int>, int> code;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  vector<pair<int, int>> black;
  int cw = 0;
  for (int i = 0; i < n; i++) {
    cin >> grid[i];
    for (int j = 0; j < n; j++) {
      if (grid[i][j] == '.')
        continue;
      code[{i, j}] = (int)code.size();
      if (grid[i][j] == 'B')
        black.emplace_back(i, j);
      else if (grid[i][j] == 'W')
        cw++;
    }
  }
  int res = 0;
  for (auto [sx, sy] : black) {
    vector<vector<int>> graph(code.size());
    vector<int> deg(code.size());
    vector<int> vis(code.size(), false);
    queue<pair<int, int>> q;
    q.push({sx, sy});
    vis[code[{sx, sy}]] = true;
    int jumps = 0;
    while (!q.empty()) {
      auto [x, y] = q.front();
      int u = code[{x, y}];
      q.pop();
      for (int i = 0; i < 4; i++) {
        int xx = x + 2 * dx[i];
        int yy = y + 2 * dy[i];
        if (xx < 0 || xx >= n)
          continue;
        if (yy < 0 || yy >= n)
          continue;
        if (grid[xx][yy] != '_')
          continue;
        if (grid[xx - dx[i]][yy - dy[i]] != 'W')
          continue;
        int v = code[{xx, yy}];
        int w = code[{xx - dx[i], yy - dy[i]}];
        if (!vis[w]) {
          vis[w] = true;
          graph[u].push_back(v);
          graph[v].push_back(u);
          deg[u]++;
          deg[v]++;
          jumps++;
        }
        if (vis[v])
          continue;
        vis[v] = true;
        q.push({xx, yy});
      }
    }
    if (jumps != cw)
      continue;
    int ctr = 0;
    for (int x : deg)
      if (x & 1) ctr++;
    if (ctr == 0) {
      res++;
    } else if (ctr == 2) {
      if (deg[code[{sx, sy}]] & 1)
        res++;
    }
  }
  cout << res << '\n';
  return 0;
}

