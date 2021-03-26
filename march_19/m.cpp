#include <bits/stdc++.h>
using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, a, b;
  cin >> n >> a >> b;
  int c = n - a;
  int d = n - b;
  cout << 4 * max({a*b, c*d, a*d, b*c}) << '\n';
  return 0;
}

