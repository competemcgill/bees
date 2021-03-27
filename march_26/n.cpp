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
typedef pair<ll,ll> pl;
const int INF = 1e9;
const ll INFL = 1LL<<61;
class ST {
	private:
		int n;
		vl st;
	public:
		ST(int n_) {
			n = n_;
			st.assign(2*n,0);
		}
		void up(int p, ll v) {
			p += n;
			st[p] = v;
			while(p > 1) {
				st[p>>1] = max(st[p],st[p^1]);
				p >>= 1;
			}
		}
		ll get(int l, int r) {
			l += n;r += n;
			ll res = -INFL;
			for(;l<r;l>>=1,r>>=1) {
				if(l&1) {
					res = max(res,st[l]);
					l++;
				}
				if(r&1) {
					--r;
					res = max(res,st[r]);
				}
			}
			return res;
		}
};
int main() {
	ios::sync_with_stdio(0);cout.precision(20);cout.tie(0);cin.tie(0);
	ll n,ra,wo,ho;
	cin >> n >> ra >> wo >> ho;
	vector<pl> w;
	for(int i=0;i<n;i++) {
		ll x,y;
		cin >> x >> y;
		x *= 2*ra;y *= 2*ra;
		w.emplace_back(x+y/ra,y);
	}
	sort(w.begin(),w.end());
	vl ms;
	for(int i=0;i<w.size();i++) {
		w[i].second = w[i].second-ra*w[i].first/2;
		ms.push_back(w[i].second);
	}
	sort(ms.begin(),ms.end());
	ST st(w.size()+3);
	for(int i=w.size()-1;i>=0;i--) {
		int idx = lower_bound(ms.begin(),ms.end(),w[i].second)-ms.begin();
		ll gu = st.get(idx,w.size());
		st.up(idx,gu+1);
	}
	ll res = st.get(0,w.size());
	cout << res << '\n';
}

