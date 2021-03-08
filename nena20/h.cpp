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
int main() {
	ios::sync_with_stdio(0);cout.precision(20);cout.tie(0);cin.tie(0);
	ll n;
	cin >> n;
	vii ord;
	for(int i=0;i<n;i++) {
		int t;
		cin >> t;
		ord.push_back({t,i});
	}
	sort(ord.begin(),ord.end());
	vi w(n);
	for(int i=0;i<ord.size();i++) {
		w[ord[i].second] = i;
	}
	ll res = 0;
	oset<ii> bs;
	oset<int> bos;
	for(int i=n-1;i>=0;i--) {
		int pos = bos.order_of_key(ord[i].second);
		int pa = bs.order_of_key({0,ord[i].first});
		int pb = bs.order_of_key({1,-ord[i].first});
		res += min(abs(pos-pa),abs(pos-pb));
		bos.insert(ord[i].second);
		if(abs(pos-pa) < abs(pos-pb)) {
			bs.insert({0,ord[i].first});
		} else {
			bs.insert({1,-ord[i].first});
		}
	}
	cout << res << '\n';
}

