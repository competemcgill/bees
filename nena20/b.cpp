#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll k, r;
  cin >> k >> r;
  vector<ll> ind(k);
  for (ll &x : ind)
    cin >> x;
  ll res = 0;
  for (ll i = 0; i < r; i++) {
    ll ctr = INT_MAX;
    for (int j = 0; j < k; j++) {
      ll x;
      cin >> x;
      if (x > 0) {
        ctr = min(ctr, ind[j] / x);
      }
    }
    ll price;
    cin >> price;
    res = max(res, price * ctr);
  }
  cout << res << '\n';
  return 0;
}

