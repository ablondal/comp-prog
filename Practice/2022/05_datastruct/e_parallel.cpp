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
	for(int tt = 1; tt<= t; ++tt){
		int n, MM;
		MM = 0;
		cin >> n;
		unordered_map<int, int> M;
		rep(i,0,n){
			int a, r, w;
			cin >> a;
			int tim = 0;
			rep(i,0,a-1){
				cin >> r;
				if (M.count(r)) tim = max(tim, M[r]);
			}
			tim++;
			MM = max(MM, tim);
			cin >> w;
			M[w] = tim;
		}
		cout << tt << " " << MM << endl;
	}
}