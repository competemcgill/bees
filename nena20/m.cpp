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
const int MN = 100100;
const int D = 10;
const ll M = 998244353;
vi sad;
ll dp[MN][2][D+1];
ll ds(ll di, ll le, ll cu) {
	if(di == sad.size()) {return 1;}
	if(dp[di][le][cu] != -1) {return dp[di][le][cu];}
	ll res = 0;
	for(int i=0;i<D;i++) {
		if(i == 0 && cu == D) {continue;}
		if(i == cu) {continue;}
		if(le) {
			if(i > sad[di]) {break;}
			if(i == sad[di]) {
				res += ds(di+1,1,i);
			} else {
				res += ds(di+1,0,i);
			}
		} else {
			res += ds(di+1,0,i);
		}
	}
	res %= M;
	return dp[di][le][cu] = res;
}
int annoy(const string& st) {
	for(int i=1;i<st.size();i++) {
		if(st[i] == st[i-1]) {return 0;}
	}
	return 1;
}
int main() {
	ios::sync_with_stdio(0);cout.precision(20);cout.tie(0);cin.tie(0);
	string st[2];
	cin >> st[0] >> st[1];
	ll res[2] = {0,0};
	ll ann = annoy(st[0]);
	for(int it=0;it<2;it++) {
		sad.clear();
		memset(dp,-1,sizeof(dp));
		for(int i=0;i<st[it].size();i++) {
			sad.push_back(st[it][i]-'0');
		}
		for(int i=0;i<sad.size();i++) {
			res[it] += ds(i,i == 0,10);
		}
		//cout << ds(0,1,10) << " initial D\n";
		res[it] %= M;
	}
	ll ans = res[1]-res[0]+ann;
	ans = ((ans%M)+M)%M;
	cout << ans << '\n';
}



