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
	map<char, int> nx;
	string word;
	vi aut;
};
node nds[1000000];
int Ni = 1;

void put_in_tree(string s){
	int c = 0;
	rep(i,0,sz(s)){
		if (nds[c].nx.find(s[i]) == nds[c].nx.end()){
			nds[c].nx[s[i]] = Ni;
			c = Ni++;
		} else {
			c = nds[c].nx[s[i]];
		}
	}
	nds[c].word = s;
}

void get_lex(int v){
	for(auto [ch, to]: nds[v].nx){
		if (nds[to].word.size()){
			nds[v].aut.push_back(to);
		}
		get_lex(to);
		for(auto l:nds[to].aut){
			nds[v].aut.push_back(l);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n; cin >> n;
	// vector<string> words;
	rep(i, 0, n){
		string s; cin >> s;
		put_in_tree(s);
	}
	get_lex(0);
	int q; cin >> q;
	rep(i,0,q){
		string s; cin >> s;
	}

}