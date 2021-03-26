#include <bits/stdc++.h>
using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  unordered_map<string, int> dict;
  for (int i = 0; i < n; i++) {
    string s;
    int x;
    cin >> s >> x;
    dict[s] = x;
  }
  for (int i = 0; i < m; i++) {
    int res = 0;
    string s;
    while (cin >> s, s != ".")
      res += dict[s];
    cout << res << '\n';
  }
  return 0;
}

