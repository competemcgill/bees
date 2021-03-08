#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll n, m;
  cin >> n >> m;
  map<ll, ll> last;
  for (ll i = 1; i <= m; i++) {
    ll x;
    cin >> x;
    last[x] = i;
    ll res = 0;
    for (auto [_, l] : last)
      res += i - l;
    res += (n - (int) last.size()) * i;
    cout << res << '\n';
  }
  return 0;
}
