#include <bits/stdc++.h>
using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<pair<int, int>> a(n);
  a[0] = {-1, 1};
  for (int i = 1; i < n; i++) {
    cin >> a[i].first;
    a[i].second = i + 1;
  }
  sort(a.begin(), a.end());
  for (auto [_, x] : a)
    cout << x << ' ';
  cout << '\n';
  return 0;
}

