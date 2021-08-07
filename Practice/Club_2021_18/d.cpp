#include <bits/stdc++.h>
using namespace std;
// done
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n, k;
	cin >> n >> k;
	vector<ll> a(n);
	rep(i,0,n){
		cin >> a[i];
	}
	sort(all(a));
	unordered_map<ll, ll> M;
	rep(i,n/2,n){
		M[a[i]]++;
	}
	ll cs = a[n/2];
	rep(j,n/2,n-1){
		ll max_j = a[j+1]-a[j];
		if (M[cs] * max_j <= k){
			k -= M[cs]*max_j;
			if (a[j+1] != a[j])
				M[a[j+1]] += M[cs];
			cs = a[j+1];
		} else {
			cs += k / M[cs];
			k = 0;
			break;
		}
		// cout << cs << " " << k << endl;
	}
	// cout << k << endl;
	if (k) {
		cs += k / M[cs];
	}
	cout << cs << endl;
}