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

struct node{
	map<string, int> nxt;
	map<string, int> ans;
	vi adj;
};

vector<node> nds;
vector<double> chance;
void add_phrase(int c, vector<string> &q, string &a){
	for(auto w: q){
		auto it = nds[c].nxt.find(w);
		if (it == nds[c].nxt.end()) {
			nds[c].nxt[w] = sz(nds);
			nds.emplace_back();
		}
		nds[c].adj.push_back(nds[c].nxt[w]);
		nds[c].ans[a]++;
		c = nds[c].nxt[w];
	}
	nds[c].ans[a]++;
	nds[c].adj.push_back(-1);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t, n;
	cin >> t >> n;
	nds.emplace_back();
	rep(i,0,n){
		vector<string> q;
		string a;
		while(cin >> a){
			q.push_back(a);
			if (a.back() == '?'){
				cin >> a;
				break;
			}
		}
		// cout << "adding" << endl;
		add_phrase(0, q, a);
	}
	chance.resize(sz(nds));
	rep(i,0,sz(nds)){
		int M = 0;
		for(auto& [s, ct]:nds[i].ans){
			M = max(M, ct);
		}
		chance[i] = (double)M / sz(nds[i].adj);
		// cout << i << " " << chance[i] << endl;
	}

	vector<vector<double>> DP(t+2, vector<double>(sz(nds), 0));
	for(int j = t-1; j>=0; --j){
		rep(i,0,sz(nds)){
			for(auto e : nds[i].adj){
				if (e != -1)
					DP[j][i] += (DP[j+1][e]) / sz(nds[i].adj);
			}
			DP[j][i] = max(DP[j][i], DP[j+1][0]+chance[i]);
		}
	}
	cout << setprecision(10) << DP[0][0] << endl;
}