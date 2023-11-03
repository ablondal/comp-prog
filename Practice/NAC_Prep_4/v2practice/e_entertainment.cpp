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
	vector<pii> a(n);
	rep(i,0,n) cin >> a[i].first >> a[i].second;
	sort(all(a));
	int tot = 0;
	multiset<int> S;
	rep(i,0,n){
		while(!S.empty() && *S.begin()<=a[i].first){
			S.erase(S.begin());
		}
		if (sz(S) < k){
			S.insert(a[i].second);
			tot++;
		} else {
			auto it = S.end();
			it--;
			if (*it > a[i].second){
				S.erase(it);
				S.insert(a[i].second);
			}
		}
	}
	cout << tot << endl;
}