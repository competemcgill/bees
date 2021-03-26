#include <bits/stdc++.h>
using namespace std;

constexpr int MN = 5012;

struct point { double x, y; };

int p[MN], sz[MN];

int rep(int i) {
  if (p[i] == i)
    return i;
  return p[i] = rep(p[i]);
}

void merge(int a, int b) {
  int x = rep(a), y = rep(b);
  if (x != y) {
    if (sz[x] > sz[y]) swap(x, y);
    p[x] = y;
    sz[y] += sz[x];
  }
}

double dist(const point& a, const point& b) {
  return hypot(a.x - b.x, a.y - b.y);
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<point> pos(n);
  for (int i = 0; i < n; i++) {
    p[i] = i;
    sz[i] = 1;
    cin >> pos[i].x >> pos[i].y;
  }
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (dist(pos[i], pos[j]) <= 2.0)
        merge(i, j);
    }
  }
  int res = *max_element(sz, sz + n) + 1;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      int x = rep(i), y = rep(j);
      if (x == y) continue;
      if (dist(pos[i], pos[j]) <= 4.0)
        res = max(res, sz[x] + sz[y] + 1);
    }
  }
  for (int i = 0; i < n; i++)
    cout << rep(i) << ' ';
  cout << '\n';
  cout << res << '\n';
  return 0;
}

