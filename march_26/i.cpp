#include <bits/stdc++.h>
using namespace std;

using crane = tuple<int, int, int>;

int sdist(int a, int b, int c, int d) {
  return (a - c) * (a - c) + (b - d) * (b - d);
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<crane> cranes;
    for (int i = 0; i < n; i++) {
      int x, y, r;
      cin >> x >> y >> r;
      cranes.emplace_back(x, y, r);
    }
    int res = 0;
    for (int i = 1, lm = (1 << n); i < lm; i++) {
      vector<crane> cur;
      for (int j = 0; j < n; j++) {
        if ((i >> j) & 1)
          cur.push_back(cranes[j]);
      }
      bool poss = true;
      for (int j = 0; poss && j < (int)cur.size(); j++) {
        for (int k = j + 1; poss && k < (int)cur.size(); k++) {
          auto [a, b, r1] = cur[j];
          auto [c, d, r2] = cur[k];
          if (sdist(a, b, c, d) <= (r1 + r2) * (r1 + r2))
            poss = false;
        }
      }
      if (!poss)
        continue;
      int cur_area = 0;
      for (auto [a, b, r] : cur)
        cur_area += r * r;
      res = max(res, cur_area);
    }
    cout << res << '\n';
  }
  return 0;
}

