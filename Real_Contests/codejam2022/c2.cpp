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

vector<int> g;
map<int, int> G;

map<ll, int> vis;

int rot(int a, int r){
	return ((1<<8) - 1) & ( (a << (8-r) ) | (a >> r ) );
}

pair<int, int> stform(int a){
	map<int, int>::iterator it;
	rep(r,0,8){
		if ( (it=G.find(rot(a, r))) != G.end() ) return *it;
	}
	return {a, -1};
}

ll disc(ll &c, int q, int l){
	ll poss = 0;
	rep(i,0,S){
		if (!(c & (1LL<<i))) continue;
		rep(r,0,8){
			int rr = rot(q, r);
			if (__builtin_popcount(rr ^ g[i]) == l){
				poss |= (1LL << stform(rr ^ g[i]).second);
			}
		}
	}
	// cout << poss << endl;
	return poss;
}

int lmove;
map<ll, int> mv;

int getnxt(ll st, int l_last){
	if (st == 1 || st == 0){
		return true;
	}
	int mv = -1;
	int M = 1e7;
	for(auto i:g){
		bool w = true;
		int lo = (l_last - __builtin_popcount(i));
		int hi = max((l_last + __builtin_popcount(i)), 9);
		int m = 0;
		ll dd = 0;
		rep(l,lo,hi){
			auto d = disc(st, i, l);
			if (vis.count(d)){
				m = max(m, vis[d]);
			}
		}
		if (m < M){
			M = m;
			mv = i;
		}
	}
	return mv;
}

/*
pair<int, int> bestq(ll &c, int l2, int dep = 1){
	if (l2 == 0) return {0, -1};
	int mp = 255;
	int q = 0;
	for(auto i:g){
		int M = 0, nl = 0;
		ll a;
		rep(l,abs(l2-__builtin_popcount(i)),l2 + __builtin_popcount(i)+1){
			auto d = disc(c,i,l);
			if (__builtin_popcountll(d) > M){
				M = __builtin_popcountll(d);
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

int bestq2(ll &c){
	rep(i,1,S){
		if (c & (1LL << i)) return i;
	}
	return (1<<8) - 1;
}
*/

void binprint(int q2){
	string st;
	rep(i,0,8){ st.push_back((q2 & 1 ? '1' : '0')); q2>>=1; }
	reverse(all(st));
	cout << st << endl;
}

// setmoves(int st){
// 	if ()
// }

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
	// for(auto gg : g){
	// 	cout << gg << endl;
	// }
	// cout << sz(guesses) << endl;

	mv[255] = 255;
	mv[85] = 85;
	mv[51] = 51;
	mv[17] = 17;



	int t;
	cin >> t;
	for(int T=1; T<=t; ++T){
		vis.clear();
		ll curr = 0;
		int lastl;
		curr = (1LL<<36)-1;
		cout << "00000000" << endl;
		int w;
		cin >> w;
		curr = disc(curr, 0, w);
		lastl = w;
		

		bool done = false;
		while(!done){
			vis[curr]++;
			auto nmv = getnxt(curr, lastl);
			binprint(nmv);
			cin >> lastl;
			if (lastl == 0){
				done = true;
				break;
			} else if (lastl == -1){
				exit(0);
			}
			curr = disc(curr, nmv, lastl);
		}
	}
}