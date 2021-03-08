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
const int MZ = 29;
vl dist[MZ];
vi g[MZ][MN];
int cont[MZ][MN];
int main() {
	ios::sync_with_stdio(0);cout.precision(20);cout.tie(0);cin.tie(0);
	ll n,k;
	cin >> n >> k;
	for(int i=0;i<MZ;i++) {
		dist[i].assign(n+1,-1);
	}
	vii ord;
	vi w;
	ord.push_back({0,0});
	w.push_back(0);
	for(int i=0;i<n;i++) {
		ll t;
		cin >> t;
		ord.push_back({t,i+1});
		w.push_back(t);
	}
	memset(cont,0,sizeof(cont));
	sort(ord.begin(),ord.end());
	for(int it=0;it<MZ;it++) {
		int ls = 0,rs = 0;
		set<int> bs;
		for(int j=0;j<ord.size();j++) {
			while(rs < ord.size() && ord[rs].first <= ord[j].first+(1<<it)) {
				bs.insert(ord[rs].second);
				rs++;
			}
			while(ls < ord.size() && ord[ls].first < ord[j].first-(1<<it)) {
				bs.erase(ord[ls].second);
				ls++;
			}
			auto iter = bs.rbegin();
			int idx = ord[j].second;
			for(;iter != bs.rend() && g[it][idx].size() < k;iter++) {
				if((*iter) == idx) {
					cont[it][idx] = 1;
				}
				g[it][idx].push_back(*iter);
			}
		}
	}
	dist[0][0] = 0;
	queue<ii> q;
	q.push({0,0});
	while(!q.empty()) {
		ii co = q.front();q.pop();
		int zo = co.first;
		int u = co.second;
		for(int i=0;i<g[zo][u].size();i++) {
			int v = g[zo][u][i];
			if(dist[zo][v] == -1) {
				dist[zo][v] = dist[zo][u]+1;
				q.push({zo,v});
			}
		}
		if(zo+1 < MZ && dist[zo+1][u] == -1) {
			dist[zo+1][u] = dist[zo][u]+1;
			q.emplace(zo+1,u);
		}
		if(zo-1 >= 0 && dist[zo-1][u] == -1) {
			dist[zo-1][u] = dist[zo][u]+1;
			q.emplace(zo-1,u);
		}
	}
	vl ans(n,-1);
	for(int i=1;i<=n;i++) {
		bool fod = false;
		ll ls = -1;
		for(int j=0;j<MZ;j++) {
			if(dist[j][i] != -1) {
				if(cont[j][i]) {
					if(!fod) {
						ls = dist[j][i];
					} else {
						ls = min(ls,dist[j][i]);
					}
				} else {
					if(!fod) {
						ls = dist[j][i]+j+1;
					} else {
						ls = min(ls,dist[j][i]+j+1);
					}
				}
				fod = true;
			}
		}
		ans[i-1] = ls;
	}
	for(int i=0;i<ans.size();i++) {
		cout << ans[i] << '\n';
	}
}

