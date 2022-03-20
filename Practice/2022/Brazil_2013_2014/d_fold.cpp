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
typedef vector<vll> mat;
const ll MAX = 507;

set<vi> V;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n;
	vi a(n);
	rep(i,0,n) cin >> a[i];
	cin >> m;
	vi b(m);
	rep(i,0,m) cin >> b[i];

	queue<vector<int>> Q;
	Q.push(a);
	V.insert(a);
	while(!Q.empty()){
		vi c = Q.front();
		Q.pop();
		rep(i,0,sz(c)){
			vi n(max(sz(c)-i, i), 0);
			rep(j,0,i) n[sz(n)-i+j] += c[j];
			rep(j,i,sz(c)) n[sz(n)-(j-i)-1] += c[j];
			if (V.count(n)) continue;
			else{
				V.insert(n);
				Q.push(n);
			}
		}
	}
	if (V.count(b)){
		cout << "S" << endl;
	} else {
		cout << "N" << endl;
	}


	
}