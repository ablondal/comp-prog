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
const int N = 2e5+7;

struct SA{
	string s;
	vi link, len, ct, t;
	int la=0, ni=1;
	vector<map<char,int>> nx;
	void add_c(char x){
		int a=la, c=ni++;
		len[c] = len[a]+1; ct[c]=1; la=c;
		while(a!=-1 && !nx[a].count(x)){
			nx[a][x]=c;a = link[a];
		}
		if (a==-1) {
			link[c] = 0;
		} else {
			int q = nx[a][x];
			if (len[a]+1==len[q]){
				link[c]=q;
			} else {
				int cl = ni++;
				link[cl] = link[q]; nx[cl]=nx[q];
				len[cl] = len[a]+1;
				while(a != -1 && nx[a][x]==q){
					nx[a][x]=cl; a=link[a];
				}
				link[q] = link[c]=cl;
			}
		}
	}
	SA(string s):s(s),link(2*sz(s)+1, 0), len(2*sz(s)+1, 0), ct(2*sz(s)+1, 0), t(2*sz(s)+1, 0), nx(2*sz(s)+1){
		link[0]=-1; len[0]=0;
		for(auto x:s) add_c(x);
		t[la]=true;
		vi a(ni, 0); iota(all(a), 0);
		sort(all(a), [this](int b, int c){return len[b]<len[c];});
		for(int i=ni-1; i>0; --i){
			t[link[a[i]]] = t[a[i]];
			ct[link[a[i]]] += ct[a[i]];
		}
		ct[0]=0;
	}
};
char vis[N] = {0};
vector<ll> DP;

ll dfs1(int v, SA &sa){
	if (vis[v]) return DP[v];
	vis[v] = true;
	for(auto [c, e]: sa.nx[v]){
		DP[v] += dfs1(e, sa);
	}
	DP[v]++;
	sa.ct[v]=1;
	return DP[v];
}

string res;
void dfs2(int v, ll k, SA &sa){
	if (k <= (ll)sa.ct[v]) return;
	k -= sa.ct[v];
	for(auto [c, e]: sa.nx[v]){
		if (k <= DP[e]){
			res.push_back(c);
			dfs2(e, k, sa);
			return;
		}
		k -= DP[e];
	}
	return;	
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string s;
	ll k;
	cin >> s >> k;
	DP.resize(2*sz(s)+1, 0);
	SA sa(s);
	dfs1(0, sa);
	sa.ct[0] = 0;
	DP[0]--;
	dfs2(0, k, sa);
	cout << res << endl;
}