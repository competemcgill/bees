#include <bits/stdc++.h>
using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<pair<int, int>> v;
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    --a, --b;
    v.emplace_back(a, b);
  }
  int res = 0;
  for (int i = 0, lm = (1 << n); i < lm; i++) {
    bool poss = true;
    for (auto [a, b] : v) {
      if (((i >> a) & 1) && ((i >> b) & 1)) {
        poss = false;
        break;
      }
    }
    if (poss)
      res++;
  }
  cout << res << '\n';
  return 0;
}

