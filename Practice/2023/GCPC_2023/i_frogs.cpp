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
	int n, q;
	cin >> n;
	vi a(n);
	rep(i,0,n) cin >> a[i];
	cin >> q;
	vi js(q);
	rep(i,0,q) cin >> js[i];
	vi uo;
	int j = 0;
	rep(i,0,2000000){
		if (j < n && a[j] == i) {
			j++;
		} else {
			uo.push_back(i);
		}
	}
	set<int> unocc(all(uo));
	// cout << sz(unocc) << endl;
	// cout << "rdy" << endl;
	vector<int> as;
	for(auto jp: js){
		int c = a[jp-1];
		// cout << c << endl;
		auto nx = unocc.upper_bound(c);
		a[jp-1] = *nx;
		unocc.erase(a[jp-1]);
		unocc.insert(c);
		as.push_back(a[jp-1]);
		// cout << a[jp] << endl;
	}

	for(auto x:as){
		cout << x << " ";
	}
	cout << endl;
}