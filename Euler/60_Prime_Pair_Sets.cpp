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

const int LIM = 1e8;
bitset<LIM> isPrime;
vi eratosthenes() {
	const int S = (int)round(sqrt(LIM)), R = LIM / 2;
	vi pr = {2}, sieve(S+1); pr.reserve(int(LIM/log(LIM)*1.1));
	vector<pii> cp;
	for (int i = 3; i <= S; i += 2) if (!sieve[i]) {
		cp.push_back({i, i * i / 2});
		for (int j = i * i; j <= S; j += 2 * i) sieve[j] = 1;
	}
	for (int L = 1; L <= R; L += S) {
		array<bool, S> block{};
		for (auto &[p, idx] : cp)
			for (int i=idx; i < S+L; idx = (i+=p)) block[i-L] = 1;
		rep(i,0,min(S, R - L))
			if (!block[i]) pr.push_back((L + i) * 2 + 1);
	}
	for (int i : pr) isPrime[i] = 1;
	return pr;
}

int toint(string s){
	int i=0;
	for(auto c : s){
		i *= 10;
		i+= c-'0';
	}
	return i;
}

string tostring(int i){
	string res;
	do{
		res.push_back('0'+ (i%10));
		i /= 10;
	}while(i);
	reverse(all(res));
	return res;
}

vector<vi> adj;
vi curr;
vi prs;
const int siz = 5;
bool buildclique(vi poss){
	if (sz(poss) < siz-sz(curr)) return false;
	if (sz(curr) == siz) return true;
	for (auto p : poss){
		vi n_poss(sz(poss) + sz(adj[p]));
		auto it = set_intersection(all(poss), all(adj[p]), n_poss.begin());
		n_poss.resize(it-n_poss.begin());
		curr.push_back(p);
		if (buildclique(n_poss)) return true;
		curr.pop_back();
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	prs = eratosthenes();
	cout << sz(prs) << endl;

	vector<pii> e;
	adj.resize(LIM+7);

	for(auto p : prs){
		// cout << p << endl;
		string s = tostring(p);
		rep(i,1,sz(s)){
			if (s[i] == '0') continue;
			int a1 = toint(s.substr(0,i));
			int a2 = toint(s.substr(i,sz(s)));
			if (a1 < a2 && isPrime[a1] && isPrime[a2] && isPrime[toint(tostring(a2)+tostring(a1))]) {
				// cout << p << " " << a1 << " " << a2 << endl;
				e.push_back({a1, a2});
				adj[a1].push_back(a2);
				adj[a2].push_back(a1);
			}
		}
	}
	cout << sz(e) << endl << endl;
	// sort(all(e));
	// rep(i,0,LIM){
	// 	if (sz(adj[i])){
	// 		cout << i << " " << sz(adj[i]) << endl;
	// 	}
	// 	// cout << e[i].first << " " << e[i].second << endl;
	// }
	for(auto p : prs){
		curr.push_back(p);
		if (buildclique(adj[p])) break;
		curr.pop_back();
	}
	// curr.push_back(7);
	// buildclique(adj[7]);

	for(auto a : curr){
		cout << a << endl;
	}
}