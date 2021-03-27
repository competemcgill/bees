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
const int H = 4;
vl ans;
struct P {
	int x,y,idx;
};
vector<vector<P>> st[H];
int find(const P& pt, int s) {
	if(pt.x*2 < s) {
		if(pt.y*2 < s) {
			return 0;
		} else {
			return 1;
		}
	} else {
		if(pt.y*2 < s) {
			return 3;
		} else {
			return 2;
		}
	}
}
P tra(const P& pt, int qu, int s) {
	switch(qu) {
		case 0: {
					return {pt.y*2,pt.x*2,pt.idx};
				}
		case 1: {
					return {pt.x*2,pt.y*2-s,pt.idx};
				}
		case 2: {
					return {pt.x*2-s,pt.y*2-s,pt.idx};
				}
		case 3: {
					return {s-(pt.y*2),s-(pt.x*2-s),pt.idx};
				}
	}
	return pt;
}
void proc(int idx, int s) {
	for(int id=0;id<H;id++) {
		if(st[id][idx].size() == 0) {continue;}
		if(st[id][idx].size() == 1) {
			ans.push_back(st[id][idx].front().idx);
			continue;
		}
		for(int i=0;i<H;i++) {
			st[i].emplace_back();
		}
		for(const auto& it: st[id][idx]) {
			int ni = find(it,s);
			st[ni][idx+1].push_back(tra(it,ni,s));
		}
		proc(idx+1,s);
		for(int i=0;i<H;i++) {
			st[i].pop_back();
		}
	}
}
int main() {
	ios::sync_with_stdio(0);cout.precision(20);cout.tie(0);cin.tie(0);
	ll n,sz;
	cin >> n >> sz;
	for(int i=0;i<H;i++) {
		st[i].emplace_back();
	}
	vii go;
	for(int i=0;i<n;i++) {
		int a,b;
		cin >> a >> b;
		st[0][0].push_back({a,b,i});
		go.emplace_back(a,b);
	}
	proc(0,sz);
	for(int i=0;i<ans.size();i++) {
		ii po = go[ans[i]];
		cout << po.first << " " << po.second << '\n';
	}
}

