#include <bits/stdc++.h>
using namespace std;
// incomplete
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef complex<double> cd;
const int S = 36;
typedef bitset<S> BS;

vector<int> g;
map<int, int> G;

set<BS> vis;

int rot(int a, int r){
	return ((1<<8) - 1) & ( (a << (8-r) ) | (a >> r ) );
}

pair<int, int> stform(int a){
	map<int, int>::iterator it;
	rep(r,0,8){
		if ( (it=G.find(rot(a, r))) != G.end() ) return *it;
	}
	return {a, 0};
}

BS disc(BS &c, int q, int l){
	BS poss = 0;
	rep(i,0,S){
		if (!c[i]) continue;
		rep(r,0,8){
			int rr = rot(q, r);
			if (__builtin_popcount(rr ^ g[i]) == l){
				poss[ stform(rr ^ g[i]).second ] = true;
			}
		}
	}
	return poss;
}

void dfs(BS st, int l_last){
	for(auto i:g){
		bool w = true;
		int lo = (l_last - __builtin_popcount(i));
		int hi = max((l_last + __builtin_popcount(i)), 9);
		rep(l,lo,hi){
			if (vis.count(disc(st,i,l))){
				w = false;
				break;
			}
		}
	}
}

pair<int, int> bestq(BS &c, int l2, int dep = 1){
	if (l2 == 0) return {0, -1};
	int mp = 255;
	int q = 0;
	for(auto i:g){
		int M = 0, nl = 0;
		BS a;
		rep(l,abs(l2-__builtin_popcount(i)),l2 + __builtin_popcount(i)+1){
			auto d = disc(c,i,l);
			if (d.count() > M){
				M = d.count();
				a = d;
				nl = l;
			}
		}
		if (dep) {
			auto [q2, mp2] = bestq(a, nl, dep-1);
			if (mp2 < mp){
				mp = mp2;
				q = i;
			}
		} else {
			if (M < mp){
				mp = M;
				q = i;
			}
		}
	}
	return {q, mp};
}

int bestq2(BS &c){
	rep(i,1,S){
		if (c[i]) return i;
	}
	return (1<<8) - 1;
}

void binprint(int q2){
	string st;
	rep(i,0,8){ st.push_back((q2 & 1 ? '1' : '0')); q2>>=1; }
	reverse(all(st));
	cout << st << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	// cout << rot(7, 0) << endl;
	// cout << rot(5, 2) << endl;
	// rep(i,0,8) cout << rot(4, i) << endl;
	rep(i,0,(1<<8)){
		bool w = true;
		rep(r,0,8){
			if (G.count(rot(i,r))){
				w = false;
				break;
			}
		}
		if (w){
			G[i] = sz(g);
			g.push_back(i);
		}
	}
	// cout << stform(66).first << endl;
	// g.assign(all(G));
	for(auto gg : g){
		cout << gg << endl;
	}
	// cout << sz(guesses) << endl;

	int t;
	cin >> t;
	for(int T=1; T<=t; ++T){
		BS curr = 0;
		int lastl;
		curr.reset();
		curr.flip();
		cout << "00000000" << endl;
		int w;
		cin >> w;
		curr = disc(curr, 0, w);
		lastl = w;
		bool done = false;
		while(!done){
			// int q1, q2;
			// int mm;
			auto [mm, q1] = bestq(curr, lastl);
			cout << q1 << endl;
			int q2 = q1;
			// q1 = q2 = bestq(curr);
			binprint(q2);
			int l;
			cin >> l;
			if (l == 0){
				done = true;
				continue;
			} else if (l == -1){
				exit(0);
			}
			curr = disc(curr, q1, l);
			lastl = l;
			// rep(i,0,sz(g)){
			// 	if (curr[i]){
			// 		binprint(g[i]);
			// 	}
			// }
			// cout << endl;
			// cout << curr << endl;
		}
	}
}