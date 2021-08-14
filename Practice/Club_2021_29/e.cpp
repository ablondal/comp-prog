#include <bits/stdc++.h>
using namespace std;
// incomplete
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int n;

int query(int i){
	if (i == 0 || i == n+1) return 1e5;
	cout << "? " << i << endl;
	int a;
	cin >> a;
	return a;
}

void answer(int k){
	cout << "! " << k << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	int lo = 0, hi = n+1;
	while(hi-lo>5){
		int md = (hi + lo)/2;
		if (query(md) < query(md+1)){
			hi = md+1;
		} else {
			lo = md;
		}
		// cout << lo << " " << hi << endl;
	}
	int m = lo;
	int a = query(lo);
	rep(i, lo, hi+1){
		int x = query(i);
		if (x<a){
			a = x;
			m = i;
		}
	}

	answer(m);
}