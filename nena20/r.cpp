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
inline ll mul(ll a, ll b, ll m) {
	return (a*b)%m;
}
ll bp(ll b, ll p, ll m) {
	ll ac = 1;
	while(p) {
		if(p&1) {
			ac = mul(ac,b,m);
		}
		b = mul(b,b,m);
		p >>= 1;
	}
	return ac;
}
inline ll inv(ll b, ll m) {
	return bp(b,m-2,m);
}
vl ph;
void pre(ll n) {
	ph.assign(n+2,1);
	for(ll i=2;i<=n;i++) {
		if(ph[i] == 1) {
			for(ll j=1;j*i<=n;j++) {
				//cout << "J " << j << '\n';
				ll ok = j;
				ph[j*i] *= i-1;
				while(!(ok%i)) {
					ok /= i;
					ph[j*i] *= i;
				}
			}
		}
	}
}
ll calc(ll n, ll k, ll m) {
	ll bo = n/k;
	ll reb = bp(2,bo-1,m)-1;
	if(reb < 0) {reb += m;}
	reb = mul(reb,ph[k],m);
	return reb;
}
int main() {
	ios::sync_with_stdio(0);cout.precision(20);cout.tie(0);cin.tie(0);
	ll n, m;
	cin >> n >> m;
	pre(n);
	ll res = 0;
	for(ll i=2;i<n;i++) {
		if(!(n%i)) {
			res += calc(n,i,m);
		}
	}
	res = mul(res,n-2,m);
	res %= m;
	cout << res << '\n';
}



