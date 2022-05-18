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
map<ll, int> nxtmove;

int rot(int a, int r) {
	return ((1<<8) - 1) & ( (a << (8-r) ) | (a >> r) );
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
	return poss;
}

void binprint(int q2){
	string st;
	rep(i,0,8){ st.push_back((q2 & 1 ? '1' : '0')); q2>>=1; }
	reverse(all(st));
	cout << st << endl;
}

void setmoves(){
	nxtmove[0] = 0;
	nxtmove[1] = 0;
	nxtmove[(1LL<<36)-1] = 0;
	vector<ll> p_sts;
	p_sts.push_back(0);
	rep(l,1,9){
		ll pset = 0;
		rep(i,0,S){
			if (__builtin_popcount(g[i]) == l){
				pset |= (1LL<<i);
			}
		}
		ll s = pset;
		while (s > 0) {
			p_sts.push_back(s);
			s = (s-1) & pset;
		}
	}
	bool e = true;
	while(e){
		e = false;
		for(auto &st: p_sts){
			if (nxtmove.count(st)) continue;
			for(auto& guess:g){
				bool w=true;
				rep(i,0,9){
					if (!nxtmove.count(disc(st,guess,i))){
						w = false;
						break;
					}
				}
				if (w) {
					e = true;
					nxtmove[st] = guess;
					break;
				}
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
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

	setmoves();

	int t;
	cin >> t;
	for(int T=1; T<=t; ++T){
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
			auto nmv = nxtmove[curr];
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