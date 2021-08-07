#include <bits/stdc++.h>
using namespace std;
// incomplete
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int tim = 0;
map<string, int> ID;
// pair<int, int> adj[507];
int L[507];
int R[507];
string val[507];
int has[507][29] = {0};
int findd[507][7][26];
char init[507] = {0};

bool DFS(int v, string& fig, int& pos) {
	// cout << v << endl;
	if (val[v] == ""){
		if(has[L[v]][fig[pos]-'a']){
			if (DFS(L[v], fig, pos)) return true;
		}
		if(has[R[v]][fig[pos]-'a']){
			if (DFS(R[v], fig, pos)) return true;
		}
		return false;
	} else {
		for(auto &c : val[v]){
			if (c == fig[pos]) pos++;
			if (pos == fig.size()) break;
		}
		if (pos == fig.size()) return true;
		else return false;
	}
}

void preDFS(int v) {
	if (init[v]) return;
	init[v] = true;
	if (val[v] == ""){
		preDFS(L[v]);
		preDFS(R[v]);
		for(int i=0; i<26; ++i){
			has[v][i] = has[L[v]][i] || has[R[v]][i];
			// if (has[L[v]][i]) has[v][i] |= 1;
			// if (has[R[v]][i]) has[v][i] |= 2;
		}
	}else{
		rep(i,0,26) has[v][i] = 0;
		for(auto& c : val[v]) has[v][c-'a'] = 1;
	}
}

int getID(string& s){
	if (ID.count(s)) return ID[s];
	// cout << s << " " << tim << endl;
	return ID[s] = tim++;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while(t--){
		int k;
		cin >> k;
		tim = 0;
		// rep(i,0,k+3) adj[i];
		ID.clear();
		rep(i,0,k+3) val[i] = "", init[i] = 0 ;
		rep(i,0,k){
			string a, b, c;
			cin >> a >> b >> c;
			if ('a' <= c[0]) val[getID(a)] = c;
			else{
				string d, e;
				cin >> d >> e;
				L[getID(a)] = getID(c);
				R[getID(a)] = getID(e);
			}
		}
		string start, fig;
		cin >> start >> fig;
		preDFS(getID(start));
		int pos = 0;
		if (DFS(getID(start), fig, pos)) {
			cout << "YES" << endl;
		}else{
			cout << "NO" << endl;
		}
	}
}