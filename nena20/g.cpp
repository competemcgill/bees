#include <algorithm>
#include <cassert>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <vector>

using namespace std;

#define mp make_pair
#define st first
#define nd second
#define ll long long
#define pll pair<long long, long long>
#define pb push_back

int n, c, mn;
int A[1005], suffixSum[1005];
bool H[1005][100005];

void f(int curIndex, int curSum) {
  // cout << curIndex << ' ' << curSum << endl;
  if (H[curIndex][curSum])
    return;
  H[curIndex][curSum] = true;

  if (curIndex == n)
    return;

  if (suffixSum[curIndex] + curSum <= c) {
    mn = min(mn, suffixSum[curIndex] + curSum);
    return;
  }

  if (curSum + A[n - 1] > c) {
    mn = min(mn, curSum);
    return;
  }

  f(curIndex + 1, curSum);
  if (curSum + A[curIndex] <= c)
    f(curIndex + 1, curSum + A[curIndex]);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> c;
  mn = c;

  for (int i = 0; i < n; i++) {
    cin >> A[i];
  }

  sort(A, A + n);

  reverse(A, A + n);

  suffixSum[n - 1] = A[n - 1];
  for (int i = n - 2; i >= 0; i--)
    suffixSum[i] = suffixSum[i + 1] + A[i];

  f(0, 0);

  cout << mn;

  return 0;
}
