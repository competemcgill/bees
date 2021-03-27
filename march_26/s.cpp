#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int MN = 1e7+10;
double dp[MN];
int vs[MN];
double ds(int e, int es, int ef) {
	if(e <= 0) {
		return 1;
	}
	if(vs[e]) {return dp[e];}
	double sa = ds(e-es,es,ef);
	double sb = ds(e-ef,es,ef);
	if(sa+sb < 1e-20) {
		vs[e] = 1;
		return dp[e] = 0;
	}
	vs[e] = 1;
	return dp[e] = (sa*sb)/(sa+sb);
}
int main() {
	cout.precision(20);
	memset(vs,0,sizeof(vs));
	ll e,es,ef;
	cin >> e >> es >> ef;
	double va = ds(e,es,ef);
	if(va < 1e-13) {
		cout << 225*va << '\n';
	} else {
		double tru = (va)/(1-va);
		cout << min(225*va,200*tru) << '\n';
	}
}

