#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define fore(b,c) for(int val0=b;val0<c;val0++)
#define forr(k,c,s) for(int k=c;k<s;k++)
#define pb push_back
#define mmp make_pair
using namespace __gnu_pbds;
using namespace std;
template<typename T>
using oset = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
typedef pair<int,int> ii;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef long double ld;
typedef vector<vii> al;
typedef vector<ll> vl;
const int INF = 1e9;
const ll INFL = 1LL<<61;
const int H = 5;
bool tos(const vl& wa, ll val) {
	ll rem = 0;
	for(auto& it: wa) {
		if(it+val <= 0) {return false;}
		rem += ((it+val)-1)/2;
	}
	return rem >= val;
}
ll am[H][H];
vl los;
ll check() {
	for(int i=0;i<los.size();i++) {
		if(los[los[i]] == i) {return INFL;}
	}
	bitset<H> bs;
	vi st;
	int ok = 0;
	vi cy;
	while(1) {
		if(bs[ok]) {
			while(st.back() != ok) {
				cy.push_back(st.back());
				st.pop_back();
			}
			cy.push_back(ok);
			break;
		}
		bs.set(ok);
		st.push_back(ok);
		ok = los[ok];
	}
	reverse(cy.begin(),cy.end());
	ll ma = 0;
	for(int i=0;i<los.size();i++) {
		ma = max(ma,am[i][los[i]]+1);
	}
	vl dif;
	for(int i=0;i<cy.size();i++) {
		dif.push_back(-am[cy[i]][cy[(i+1)%cy.size()]]);
	}
	ll sa = 0,ea = INF;
	ll la = INF;
	while(sa <= ea) {
		ll m = (sa+ea)/2;
		if(m*2 >= ma && tos(dif,m*2)) {
			la = 2*m;
			ea = m-1;
		} else {
			sa = m+1;
		}
	}
	sa = 0,ea = INF;
	ll lb = INF;
	while(sa <= ea) {
		ll m = (sa+ea)/2;
		if(m*2+1 >= ma && tos(dif,m*2+1)) {
			lb = 2*m+1;
			ea = m-1;
		} else {
			sa = m+1;
		}
	}
	/*
	cout << "loser graph:\n";
	for(int i=0;i<los.size();i++) {
		cout << los[i] << " ";
	}
	cout << '\n';
	for(int i=0;i<dif.size();i++) {
		cout << dif[i] << " ";
	}
	cout << '\n';
	cout << "minimum extra " << ma << '\n';
	cout << "result " << min(la,lb) << '\n';
	*/
	return min(la,lb);
}
ll bt(int pos) {
	if(pos == los.size()) {
		return check();
	}
	ll res = INFL;
	for(int i=0;i<los.size();i++) {
		if(i == pos) {continue;}
		los[pos] = i;
		res = min(res,bt(pos+1));
	}
	return res;
}
int main() {
	ios::sync_with_stdio(0);cout.precision(20);cout.tie(0);cin.tie(0);
	ll n,m;
	cin >> n >> m;
	los.assign(n,-1);
	memset(am,0,sizeof(am));
	for(int i=0;i<m;i++) {
		string s;
		cin >> s;
		ll kt;
		cin >> kt;
		for(int j=0;j<s.size();j++) {
			for(int k=j+1;k<s.size();k++) {
				int ji = s[j]-'A';
				int ki = s[k]-'A';
				am[ji][ki]+= kt;
				am[ki][ji]-= kt;
			}
		}
	}
	ll res = bt(0);
	cout << res << '\n';
}

