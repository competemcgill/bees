#include <bits/stdc++.h>
using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  vector<string> exams(n);
  for (int i = 0; i < n; i++) {
    cin >> exams[i];
    for (int j = 0; j < k; j++) {
      exams[i][j] = exams[i][j] == 'T' ? 1 : 0;
    }
  }
  int lim = (1 << k);
  int res = 0;
  for (int i = 0; i < lim; i++) {
    vector<int> scores;
    for (int j = 0; j < n; j++) {
      int score = 0;
      for (int b = 0; b < k; b++) {
        score += (exams[j][b] == ((i >> b) & 1));
      }
      scores.push_back(score);
    }
    res = max(res, *min_element(scores.begin(), scores.end()));
  }
  cout << res << '\n';
  return 0;
}

