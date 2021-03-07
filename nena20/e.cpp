#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<ll> a(n);
  for (ll &x : a)
    cin >> x;
  sort(a.begin(), a.end());
  ll sum = 0;
  for (int i = 0; i < n; i++) {
    if (i == 0 || a[i] != a[i - 1] + 1)
      sum += a[i];
  }
  cout << sum << '\n';
  return 0;
}

