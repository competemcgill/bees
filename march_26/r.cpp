#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<ll> vl;
const int A = 26;
int main() {
	cout.precision(20);
	int n,m;
	cin >> n >> m;
	vl wa,wb;
	for(int i=0;i<n;i++) {
		int t;
		cin >> t;
		wa.push_back(t);
	}
	for(int i=0;i<m;i++) {
		int t;
		cin >> t;
		wb.push_back(t);
	}
	sort(wb.begin(),wb.end());
	set<int> bs;
	for(int i=0;i<n;i++) {
		int mi = 0;
		for(int j=0;j<m;j++) {
			if(abs(wb[j]-wa[i]) < abs(wb[mi]-wa[i])) {
				mi = j;
			}
		}
		bs.insert(mi);
	}
	cout << wa.size()-bs.size() << '\n';
}

