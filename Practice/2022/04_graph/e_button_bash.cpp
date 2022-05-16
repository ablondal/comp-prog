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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	while(t--){
		int n, ti;
		cin >> n >> ti;
		vi bu(n);
		unordered_map<int, int> V;
		vi Q, a;
		int g;
		rep(i,0,n){
			cin >> bu[i];
			// V[bu[i]] = 1;
			// Q.push_back(bu[i]);
			if (i==0) g = abs(bu[i]);
			else g = gcd(g, abs(bu[i]));
		}
		V[0] = 0;
		int tot = 0;
		Q.push_back(0);

		while(!Q.empty()){
			tot++;
			a.clear();
			for(auto e:Q){
				for(auto b : bu){
					int r = b+e;
					r = min(3600, max(b+e,0));
					if (!V.count(r)){
						V[r] = tot;
						a.push_back(r);
					}
				}
			}
			swap(a, Q);
		}
		rep(i,0,3600){
			if (V.count(ti+i)){
				cout << V[ti+i] << " " << i << endl;
				break;
			}
		}
	}
}