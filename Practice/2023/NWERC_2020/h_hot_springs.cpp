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
	int n;
	cin >> n;
	vi t(n);
	rep(i,0,n) cin >> t[i];
	sort(all(t));
	vi t2;
	while(sz(t2) < sz(t)){
		int a = t.back();
		t.pop_back();
		t2.push_back(a);
	}
	while(sz(t)){
		int a = t2.back();
		int b = t.back();
		t2.pop_back();
		t.pop_back();
		cout << a << " " << b << " ";
	}
	if (sz(t2)) {
		cout << t2.back();
	}
	cout << endl;
}