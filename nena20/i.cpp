#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<ll> a(n);
  for (ll &x : a)
    cin >> x;
  ll res = 0;
  sort(a.begin(), a.end());
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      ll ctr = 0;
      for (int k = j + 1; k < n; k++) {
        if (a[i] + a[j] > a[k]) {
          ctr++;
        }
      }
      res += (1ll << ctr) - 1;
    }
  }
  cout << res << '\n';
  return 0;
}

