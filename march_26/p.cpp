#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<ll> vl;
const int A = 26;
int main() {
	cout.precision(20);
	string s;
	cin >> s;
	vl kt(A,0);
	for(int i=0;i<s.size();i++) {
		kt[s[i]-'a']++;
	}
	sort(kt.begin(),kt.end());
	ll ma = kt[A-1]+kt[A-2];
	cout << s.size()-ma << '\n';
}

