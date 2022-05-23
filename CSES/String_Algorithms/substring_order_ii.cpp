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
const int MX = 1e5+7;

struct node {
	int link, len, ct=0;
	map<char, int> nxt;
	bool term = 0;
};

int last = 0, ni = 0;
node nds[2*MX];
char vis[2*MX] = {0};
ll DP[2*MX];

void init_sa(){
	ni++;
	nds[0] = {-1, 0, 0};
}

void add_c(char c){
	int p = last;
	int cur = ni++;
	nds[cur] = {-1, nds[last].len+1, 1};
	while(p != -1 && !nds[p].nxt.count(c)){
		nds[p].nxt[c] = cur;
		p = nds[p].link;
	}
	if (p == -1) {
		nds[cur].link = 0;
	} else {
		int q = nds[p].nxt[c];
		if (nds[p].len+1 == nds[q].len) {
			nds[cur].link = q;
		} else {
			int clone = ni++;
			nds[clone].nxt = nds[q].nxt;
			nds[clone].link = nds[q].link;
			nds[clone].len = nds[p].len+1;
			while(p != -1 && nds[p].nxt[c] == q){
				nds[p].nxt[c] = clone;
				p = nds[p].link;
			}
			nds[q].link = nds[cur].link = clone;
		}
	}
	last = cur;
}

string res;

ll dfs1(int v){
	if (vis[v]) return DP[v];
	vis[v] = true;
	DP[v] = nds[v].ct;
	for(auto [c, e]: nds[v].nxt){
		DP[v] += dfs1(e);
	}
	// cout << v << " " << DP[v] << endl;
	return DP[v];
}

void dfs2(int v, ll k){
	if (k <= (ll)nds[v].ct) return;
	k -= nds[v].ct;
	for(auto [c, e]: nds[v].nxt){
		if (k <= DP[e]) {
			res.push_back(c);
			dfs2(e, k);
			return;
		}
		k -= DP[e];
	}
	return;
}

void print_sa(){
	rep(i,0,ni){
		cout << i << ":";
		for(auto [c, e]:nds[i].nxt){
			cout << " (" << c << "," << e << ")";
		}
		cout << endl << "link: " << nds[i].link << endl;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string s;
	ll k;
	cin >> s >> k;
	init_sa();
	for(auto c : s){
		add_c(c);
	}
	vi a(ni, 0);
	iota(all(a), 0);
	sort(all(a), [](int a, int b){return nds[a].len < nds[b].len;});
	for(int i=ni-1; i>0; --i){
		// cout << a[i] << ": " << nds[a[i]].ct << endl;
		nds[nds[a[i]].link].ct += nds[a[i]].ct;
	}
	nds[0].ct = 0;
	int p = last;
	while(p != -1){
		nds[p].term = true;
		p = nds[p].link;
	}
	// cout << dfs1(0) << endl;
	dfs1(0);
	dfs2(0, k);
	cout << res << endl;
	print_sa();
}