#include <bits/stdc++.h>
using namespace std;

void rotate(vector<string> &v) {
  int n = (int)v.size();
  for (int i = 0; i < n / 2; i++) {
    for (int j = i; j < n - i - 1; j++) {
      char temp = v[i][j];
      v[i][j] = v[j][n - 1 - i];
      v[j][n - 1 - i] = v[n - 1 - i][n - 1 - j];
      v[n - 1 - i][n - 1 - j] = v[n - 1 - j][i];
      v[n - 1 - j][i] = temp;
    }
  }
}

void flip(vector<string> &v) {
  for (string &s : v)
    reverse(s.begin(), s.end());
}

vector<pair<int, int>> get_config(const vector<string> &v) {
  int x = -1, y = -1;
  for (int i = 0; i < (int)v.size(); i++) {
    for (int j = 0; j < (int)v[i].size(); j++) {
      if (v[i][j] == '#') {
        x = i;
        y = j;
        break;
      }
    }
    if (x != -1)
      break;
  }
  vector<pair<int, int>> res;
  for (int i = 0; i < (int)v.size(); i++) {
    for (int j = 0; j < (int)v[i].size(); j++) {
      if (v[i][j] == '#')
        res.emplace_back(i - x, j - y);
    }
  }
  sort(res.begin(), res.end());
  return res;
}

void print(const vector<string> &v) {
  for (const string& s : v)
    cout << s << '\n';
  cout << '\n';
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  vector<vector<pair<int, int>>> ans(11);
  ans[0] = {{0, 0}, {1, 0}, {1, 1}, {1, 2}, {1, 3}, {2, 0}};
  ans[1] = {{0, 0}, {1, -1}, {1, 0}, {1, 1}, {1, 2}, {2, -1}};
  ans[2] = {{0, 0}, {1, -2}, {1, -1}, {1, 0}, {1, 1}, {2, -2}};
  ans[3] = {{0, 0}, {1, -3}, {1, -2}, {1, -1}, {1, 0}, {2, -3}};
  ans[4] = {{0, 0}, {1, -1}, {1, 0}, {1, 1}, {1, 2}, {2, 0}};
  ans[5] = {{0, 0}, {1, -2}, {1, -1}, {1, 0}, {1, 1}, {2, -1}};
  ans[6] = {{0, 0}, {1, 0}, {1, 1}, {1, 2}, {2, -1}, {2, 0}};
  ans[7] = {{0, 0}, {1, -1}, {1, 0}, {1, 1}, {2, -2}, {2, -1}};
  ans[8] = {{0, 0}, {1, -2}, {1, -1}, {1, 0}, {2, -3}, {2, -2}};
  ans[9] = {{0, 0}, {0, 1}, {1, -1}, {1, 0}, {2, -2}, {2, -1}};
  ans[10] = {{0, 0}, {0, 1}, {0, 2}, {1, -2}, {1, -1}, {1, 0}};
  vector<string> in(6);
  for (int i = 0; i < 6; i++)
    cin >> in[i];
  vector<vector<pair<int, int>>> configs;
  for (int i = 0; i < 4; i++) {
    configs.push_back(get_config(in));
    //print(in);
    flip(in);
    configs.push_back(get_config(in));
    //print(in);
    flip(in);
    rotate(in);
  }
  bool poss = false;
  for (const auto &cfg : configs) {
    if (find(ans.begin(), ans.end(), cfg) != ans.end()) {
      poss = true;
      break;
    }
  }
  if (poss)
    cout << "can fold\n";
  else
    cout << "cannot fold\n";
  return 0;
}

