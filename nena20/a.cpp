#include <bits/stdc++.h>
using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  double sum = 0.0;
  for (int i = 0; i < k; i++) {
    int x;
    cin >> x;
    sum += x;
  }
  double mi = (sum + -3.0 * (n - k)) / n;
  double ma = (sum + 3.0 * (n - k)) / n;
  cout << mi << ' ' << ma << '\n';
  return 0;
}

