#include <bits/stdc++.h>
using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  while (cin >> n, n > 0) {
    vector<int> p(n);
    for (int &x : p) {
      cin >> x;
      --x;
    }
    string s;
    cin.ignore();
    getline(cin, s);
    while ((int)s.size() % n != 0)
      s += ' ';
    string res;
    for (int i = 0; i < (int)s.size(); i += n) {
      string cur;
      for (int j = 0; j < n; j++)
        cur += s[i + p[j]];
      res += cur;
    }
    cout << "'" << res << "'\n";
  }
  return 0;
}

