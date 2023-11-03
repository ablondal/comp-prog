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
const int MX = 2e5+7;

vector<int> wholes;
vector<int> G[MX];

vector<int> dists(int s, int n){
	vector<int> d(n+1, -1);
	vi q, nx;
	d[s] = 0;
	int dd = 1;
	q.push_back(s);
	while(!q.empty()){
		nx.clear();
		for(auto &a: q){
			for(auto e: G[a]){
				if (d[e] == -1) {
					d[e] = dd;
					nx.push_back(e);
				}
			}
		}
		swap(q, nx);
		dd++;
	}
	return d;
}

// struct frac{
// 	ll 
// }

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m, k;
	cin >> n >> m >> k;
	wholes.resize(k);
	rep(i,0,k) cin >> wholes[i];
	rep(i,0,m){
		int a, b;
		cin >> a >> b;
		G[a].push_back(b);
		G[b].push_back(a);
	}

	auto d1 = dists(1, n);
	auto dn = dists(n, n);
	ll aa = d1[n], bb = 1;

	int dl = 1000000;
	ll totdist = 0;
	for(auto w : wholes){
		totdist += dn[w];
	}
	for(auto w : wholes){
		ll dist = totdist - dn[w];
		ll a = dist, b = k-1;
		ll g = gcd(a, b);
		a /= g, b /= g;
		a += b * d1[w];
		if (a * bb < b * aa){
			aa = a;
			bb = b;
		}
	}
	ll g = gcd(aa, bb);
	aa /= g, bb /= g;
	cout << aa << "/" << bb << endl;



}