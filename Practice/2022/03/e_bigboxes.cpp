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
	int n, k;
	cin >> n >> k;
	vi w(n);
	int lo = 0;
	int hi = 0;
	rep(i,0,n){
		cin >> w[i];
		lo = max(lo, w[i]);
		hi += w[i];
	}
	while(hi-lo > 0){
		int md = (hi+lo)/2;
		int nn = 1;
		int c = 0;
		rep(i,0,n){
			if (c + w[i]>md){
				c = w[i];
				nn++;
			} else {
				c += w[i];
			}
		}
		// cout << nn << endl;
		if (nn > k){
			lo = md+1;
		} else {
			hi = md;
		}
	}
	cout << lo << endl;
}