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
const ll mod = 998244353;

map<pair<int, int>, vector<vi> > M;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);



	vi a = {1, 2, 3, 4, 5};
	do {
		int n_inv = 0, n_nxt = 0;
		rep(i,0,sz(a)-1){
			if (a[i]>a[i+1]) n_nxt++;
		}
		rep(i,0,sz(a)){
			rep(j,i+1,sz(a)){
				if (a[i] > a[j]) n_inv++;
			}
		}
		M[{n_inv, n_nxt}].push_back(a);
		// if (n_inv == 3 && n_nxt == 2){
		// 	for(auto b : a){
		// 		cout << b << " ";
		// 	}
		// 	cout << endl;
		// }

	} while (next_permutation(all(a)));

	while(true){
		int k, x;
		cin >> k >> x;
		for(auto &b : M[{k,x}]){
			for(auto c : b){
				cout << c << " ";
			}
			cout << endl;
		}
	}
}