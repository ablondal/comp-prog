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

// vector<ll> nums;
vector<ll> aa, bb;
unordered_map<ll, int> loca;
unordered_set<ll> V;

void match(ll a, ll b, ll mask, int n){
	if (V.count(mask)) return;
	
	cout << a << " " << b << " " << n << endl;

	if (loca.count(mask | (1LL << n))){
		match(a, b, mask | (1LL << n));
		match(a | (1LL << n), b, mask | (1LL << n), n-1);
		match(a, b | (1LL << n), mask | (1LL << n), n-1);
	}
	match(a, b, mask, n-1);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	aa.resize(n);
	bb.resize(n, -1);
	rep(i,0,n){
		cin >> aa[i];
		loca[aa[i]] = i;
	}
	match(0, 0, 0, 63);
	rep(i,0,n){
		cout << bb[i] << endl;
	}

}