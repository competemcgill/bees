#include <bits/stdc++.h>
using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int &x : a)
    cin >> x;
  sort(a.begin(), a.end(), greater<int>());
  long long res = 0;
  for (int i = 0; i < n; i++)
    if (i % 3 != 2)
      res += a[i];
  cout << res << '\n';
  return 0;
}

