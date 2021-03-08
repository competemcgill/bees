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
const ll BS = 56;
struct B {
	ll va[3];
	B() {memset(va,0,sizeof(va));}
	B ex(const B& ot) const {
		B res;
		for(int i=0;i<3;i++) {
			res.va[i] = va[i]^ot.va[i];
		}
		return res;
	};
	B(const string& s) {
		memset(va,0,sizeof(va));
		ll pt = 0,sup = 0;
		for(int i=0;i<s.size();i++) {
			ll ba;
			if(s[i] >= '0' && s[i] <= '9') {
				ba = s[i]-'0';
			} else {
				ba = s[i]-'a'+10;
			}
			va[sup] |= (ba<<pt);
			pt += 4;
			if(pt >= BS) {pt -= BS;sup++;}
		}
	}
	bool ek(const B& ot) const {
		for(int i=0;i<3;i++) {
			if(va[i] != ot.va[i]) {return false;}
		}
		return true;
	};
	bool ze() const {
		for(int i=0;i<3;i++) {
			if(va[i] != 0) {return false;}
		}
		return true;
	}
	bool has(int bi) {
		int pt = 0;
		while(bi >= BS) {
			bi -= BS;
			pt++;
		}
		return (1LL<<bi)&(va[pt]);
	}
};
int main() {
	ios::sync_with_stdio(0);cout.precision(20);cout.tie(0);cin.tie(0);
	ll n,m,k;
	cin >> n >> m >> k;
	vector<B> w;
	vector<B> ba;
	for(int i=0;i<n;i++) {
		string s;
		cin >> s;
		w.emplace_back(s);
	}
	vector<B> mat;
	vi bop;
	for(int i=0;i<m;i++) {
		string s;
		cin >> s;
		mat.emplace_back(s);
	}
	bool zof = false;
	vi ans(m,-1);
	for(int it=0;it<n;it++) {
		B bs = w[it];
		for(int i=0;i<bop.size();i++) {
			if(bs.has(bop[i])) {
				bs = bs.ex(ba[i]);
			}
		}
		if(bs.ze()) {
			zof = true;
		} else {
			int ls = -1;
			for(int i=0;i<4*k;i++) {
				if(bs.has(i)) {
					ls = i;
					break;
				}
			}
			ba.push_back(bs);
			bop.push_back(ls);
		}
		for(int j=0;j<m;j++) {
			if(ans[j] != -1) {continue;}
			if(mat[j].ze()) {
				if(zof) {ans[j] = it+1;}
			} else {
				B bt = mat[j];
				for(int i=0;i<bop.size();i++) {
					if(bt.has(bop[i])) {
						bt = bt.ex(ba[i]);
					}
				}
				if(bt.ze()) {
					ans[j] = it+1;
				}
			}
		}
	}
	for(int i=0;i<ans.size();i++) {
		cout << ans[i] << '\n';
	}
}

