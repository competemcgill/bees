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
vvi g;
inline ll rad(ll a, ll b) {
	return min(a+b,INFL);
}
inline ll rmul(ll a, ll b) {
	if(b == 0) {return 0;}
	if(a > INFL/b) {return INFL;}
	return a*b;
}
vector<vl> dp;
void ds(int u, int p) {
	ll sz = 1;
	for(int i=0;i<g[u].size();i++) {
		int v = g[u][i];
		if(v == p) {continue;}
		ds(v,u);
		sz += dp[v].size();
	}
	dp[u].resize(sz+1);
	dp[u][1] = 1;
	ll rs = 1;
	for(int i=0;i<g[u].size();i++) {
		int v = g[u][i];
		if(v == p) {continue;}
		vl nx = dp[u];
		for(int j=1;j<dp[v].size();j++) {
			for(int k=1;k<=rs;k++) {
				nx[j+k] = rad(nx[j+k],rmul(dp[v][j],dp[u][k]));
			}
		}
		dp[u] = nx;
		rs += dp[v].size()-1;
	}
}
int main() {
	ios::sync_with_stdio(0);cout.precision(20);cout.tie(0);cin.tie(0);
	ll n,k;
	cin >> n >> k;
	g.assign(n,vi());
	dp.assign(n,vl());
	for(int i=1;i<n;i++) {
		ll a,b;
		cin >> a >> b;
		a--;b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	ds(0,0);
	vl ans(n+1,0);
	for(int i=0;i<n;i++) {
		for(int j=0;j<dp[i].size();j++) {
			ans[j] = rad(ans[j],dp[i][j]);
		}
	}
	for(int i=1;i<ans.size();i++) {
		ans[i] = rad(ans[i],ans[i-1]);
	}
	ll ls = -1;
	for(int i=0;i<=n;i++) {
		if(ans[i] >= k) {ls = i;break;}
	}
	cout << ls << '\n';
}

