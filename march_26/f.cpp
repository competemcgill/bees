#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;
const ll INF = 1e9;
//push relabel
//O(n+m) memory
//wack runtime
class PR {
	private:
		typedef ll Flow;
		struct Edge {
			int dest, back;
			Flow f,c;
		};
		vector<vector<Edge> > g;
		vector<Flow> ec;
		vector<Edge*> cur;
		vvi hs;
		vi H;
	public:
		PR(int n) {
			g.assign(n,vector<Edge>());
			ec.assign(n,0);
			cur.assign(n,nullptr);
			hs.assign(2*n,vi());
			H.assign(n,0);
		}
		void add(int s, int t, Flow cap, Flow rcap=0) {
			if(s == t) return;
			Edge a = {t,int(g[t].size()),0,cap};
			Edge b = {s,int(g[s].size()),0,rcap};
			g[s].push_back(a);
			g[t].push_back(b);
		}
		void addf(Edge& e, Flow f) {
			Edge& back = g[e.dest][e.back];
			if(!ec[e.dest] && f) {hs[H[e.dest]].push_back(e.dest);}
			e.f += f;e.c -= f;
			ec[e.dest] += f;
			back.f -= f;
			back.c += f;
			ec[back.dest] -= f;
		}
		Flow maxflow(int s, int t) {
			int v = g.size();
			H[s] = v;ec[t] = 1;
			vi co(2*v);
			co[0] = v-1;
			for(int i=0;i<v;i++) {cur[i] = g[i].data();}
			for(auto& e: g[s]) {
				addf(e,e.c);
			}
			for(int hi = 0;;) {
				while(hs[hi].empty()) {if(!hi--) return -ec[s];}
				int u = hs[hi].back();hs[hi].pop_back();
				while(ec[u] > 0) {
					if(cur[u] == g[u].data() + g[u].size()) {
						H[u] = 1e9;
						for(auto& e: g[u]) {
							if(e.c && H[u] > H[e.dest]+1) {
								H[u] = H[e.dest]+1;cur[u] = &e;
							}
						}
						if(++co[H[u]],!--co[hi] && hi < v) {
							for(int i=0;i<v;i++) {
								if(hi < H[i] && H[i] < v) {--co[H[i]];H[i] = v+1;}
							}
						}
						hi = H[u];
					} else if(cur[u] -> c && H[u] == H[cur[u]->dest]+1) {
						addf(*cur[u],min(ec[u],cur[u]->c));
					} else {
						++cur[u];
					}
				}
			}
			return -1;
		}
		bool leftMinCut(int a) {
			return H[a] >= g.size();
		}

};

const int dr[4] = {0,1,0,-1};
const int dc[4] = {1,0,-1,0};
typedef vector<ll> vl;
int main() {
	ll n,m,k;
	cin >> n >> m >> k;
	PR pr(2*n*m+2);
	int SO = 2*n*m;
	int TO = 2*n*m+1;
	for(int i=0;i<m;i++) {
		for(int j=0;j<n;j++) {
			int lo = n*m+i*n+j;
			for(int di=0;di<4;di++) {
				int u = i+dr[di];
				int v = j+dc[di];
				if(u < 0 || u >= m) {
					pr.add(lo,TO,INF);
					continue;
				}
				if(v < 0 || v >= n) {
					pr.add(lo,TO,INF);
					continue;
				}
				int go = u*n+v;
				pr.add(lo,go,INF);
			}
		}
	}
	vector<string> ew;
	for(int i=0;i<m;i++) {
		string s;
		cin >> s;
		ew.push_back(s);
	}
	vl ka;
	for(int i=0;i<k;i++) {
		ll t;
		cin >> t;
		ka.push_back(t);
	}
	for(int i=0;i<m;i++) {
		string& s = ew[i];
		for(int j=0;j<n;j++) {
			int fo = i*n+j;
			int no = n*m+fo;
			if(s[j] == 'B') {
				pr.add(SO,fo,INF);
				pr.add(fo,no,INF);
			} else if(s[j] >= 'a' && s[j] <= 'z') {
				pr.add(fo,no,ka[s[j]-'a']);
			} else {
				pr.add(fo,no,INF);
			}
		}
	}
	ll res = pr.maxflow(SO,TO);
	if(res >= INF) {
		cout << -1 << '\n';
	} else {
		cout << res << '\n';
	}
}

