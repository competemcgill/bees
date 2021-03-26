#include <bits/stdc++.h>
using namespace std;

bool upd(string &a, string &b) {
  long long x = stoll(a), y = stoll(b);
  for (int i = 0; i < (int)a.size(); i++) {
    string cur = a;
    cur[i] = '9';
    if (stoll(cur) > y) {
      a = cur;
      return true;
    }
  }
  if ((int)b.size() == 1 && x > 0) {
    b = "0";
    return true;
  }
  for (int i = 0; i < (int)b.size(); i++) {
    string cur = b;
    if (i == 0) {
      cur[i] = '1';
      if (stoll(cur) < x) {
        b = cur;
        return true;
      }
    } else {
      cur[i] = '0';
      if (stoll(cur) < x) {
        b = cur;
        return true;
      }
    }
  }
  return false;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<string> a(n);
  for (string &s : a)
    cin >> s;
  for (int i = 0; i < n - 1; i++) {
    if (upd(a[i], a[i + 1])) {
      for (int j = 0; j < n; j++) {
        if (j > 0) cout << ' ';
        cout << a[j];
      }
      cout << '\n';
      return 0;
    }
  }
  cout << "impossible\n";
  return 0;
}

