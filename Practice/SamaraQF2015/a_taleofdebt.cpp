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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<pair<ll, int>> ms(n);
	rep(i,0,n){
		ms[i].first = 0;
		ms[i].second = i;
	}
	rep(i,0,n){
		rep(j,0,n){
			ll a;
			cin >> a;
			ms[i].first -= a;
			ms[j].first += a;
		}
	}

	sort(all(ms));

	// rep(i,0,n){
	// 	cout << ms[i].first << " " << ms[i].second << endl;
	// }
	// cout << endl;

	int i=0, j=n-1;

	vector<vector<ll>> mat(n, vector<ll>(n,0));

	while(i<j){
		ll mamt = min(-ms[i].first, ms[j].first);
		// cout << mamt << endl;
		mat[ms[i].second][ms[j].second] += mamt;
		// cout << ms[i].second << " " << ms[j].second << endl;
		ms[i].first += mamt;
		ms[j].first -= mamt;
		if (ms[i].first == 0) i++;
		if (ms[j].first == 0) j--;
		// cout << i << j << endl;
	}
	rep(k,0,n){
		rep(l,0,n){
			cout << mat[k][l] << " ";
		}
		cout << endl;
	}
}