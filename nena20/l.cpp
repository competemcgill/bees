#include <bits/stdc++.h>
using namespace std;

const int MN = 112;

int n, m;
char color[MN][MN];
vector<int> g[MN];
int a, b, c;
bool vis[MN][MN][MN];
bool painted[MN][MN];

void paint(int u, int v) {
  painted[u][v] = painted[v][u] = true;
}

void dfs(int i, int j, int k) {
  if (vis[i][j][k])
    return;
  // i = red, j = blue, k = yellow
  vis[i][j][k] = true;
  for (int v : g[i]) {
    if (color[i][v] == 'R' || color[i][v] == 'X') {
      paint(i, v);
      dfs(v, j, k);
    }
    if (color[i][v] == 'P' && i == j) {
      paint(i, v);
      dfs(v, v, k);
    }
    if (color[i][v] == 'O' && i == k) {
      paint(i, v);
      dfs(v, j, v);
    }
  }
  for (int v : g[j]) {
    if (color[j][v] == 'B' || color[j][v] == 'X') {
      paint(j, v);
      dfs(i, v, k);
    }
    if (color[j][v] == 'G' && j == k) {
      paint(j, v);
      dfs(i, v, v);
    }
  }
  for (int v : g[k]) {
    if (color[k][v] == 'Y' || color[k][v] == 'X') {
      paint(k, v);
      dfs(i, j, v);
    }
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  memset(color, -1, sizeof(color));
  for (int i = 0; i < MN; i++)
    for (int j = 0; j < MN; j++)
      painted[i][j] = true;
  cin >> n >> m >> a >> b >> c;
  for (int i = 0; i < m; i++) {
    int u, v;
    char ch;
    cin >> u >> v >> ch;
    color[u][v] = color[v][u] = ch;
    if (ch != 'X')
      painted[u][v] = painted[v][u] = false;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  dfs(a, b, c);
  bool poss = true;
  for (int i = 0; poss && i < MN; i++) {
    for (int j = 0; poss && j < MN; j++) {
      if (!painted[i][j])
        poss = false;
    }
  }
  if (poss)
    cout << 1 << '\n';
  else
    cout << 0 << '\n';
  return 0;
}

