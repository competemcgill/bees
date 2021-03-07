#include <bits/stdc++.h>
using namespace std;

int fr[10][10];
int cost[10][10];

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s;
  cin >> s;
  int n = (int) s.size();
  for (char &c : s)
    c -= '0';
  for (int i = 0; i + 1 < n; i++) {
    fr[s[i]][s[i+1]]++;
  }
  vector<int> digits = {1,2,3,4,5,6,7,8,9};
  int res = INT_MAX;
  do {
    memset(cost, 0, sizeof(cost));
    vector<int> pos(10);
    for (int i = 0; i < 9; i++)
      pos[digits[i]] = i;
    for (int i = 1; i < 10; i++) {
      for (int j = 1; j < 10; j++) {
        cost[i][j] = abs(pos[i] - pos[j]) + 1;
      }
    }
    int cur = cost[digits[0]][s[0]];
    for (int i = 1; i < 10; i++) {
      for (int j = 1; j < 10; j++) {
        cur += fr[i][j] * cost[i][j];
      }
    }
    res = min(res, cur);
  } while (next_permutation(digits.begin(), digits.end()));
  cout << res << '\n';
  return 0;
}

