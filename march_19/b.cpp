#include <bits/stdc++.h>
using namespace std;

struct nm {
  int get_id(const string &s) {
    if (ids.count(s) == 0) {
      ids[s] = idx++;
      names.push_back(s);
    }
    return ids[s];
  }

  string get_name(int id) { return names[id]; }

  int idx = 0;
  unordered_map<string, int> ids;
  vector<string> names;
};

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  nm names;
  using pii = pair<int, int>;
  vector<priority_queue<pii, vector<pii>, greater<pii>>> prefs(n);
  priority_queue<pii, vector<pii>, greater<pii>> common;
  for (int i = 0; i < n; i++) {
    int m;
    cin >> m;
    for (int j = 0; j < m; j++) {
      string s;
      cin >> s;
      prefs[i].push({j, names.get_id(s)});
    }
  }
  int m;
  cin >> m;
  for (int i = 0; i < m; i++) {
    string s;
    cin >> s;
    common.push({i, names.get_id(s)});
  }
  vector<vector<int>> res(n);
  vector<bool> vis(m, false);
  for (int i = 0, idx = 0; i < n*k; i++, idx++) {
    if (idx == n)
      idx = 0;
    int p = -1;
    while (!prefs[idx].empty() && p == -1) {
      int t = prefs[idx].top().second;
      prefs[idx].pop();
      if (!vis[t])
        p = t;
    }
    while (p == -1) {
      int t = common.top().second;
      common.pop();
      if (!vis[t])
        p = t;
    }
    res[idx].push_back(p);
    vis[p] = true;
  }
  for (int i = 0; i < n; i++) {
    for (int x : res[i])
      cout << names.get_name(x) << ' ';
    cout << '\n';
  }
  return 0;
}

