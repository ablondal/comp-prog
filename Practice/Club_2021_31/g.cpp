#include <bits/stdc++.h>
using namespace std;
// incomplete
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int maxn =5e5+7;

vector<ll> ps[maxn];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	rep(i,0,n-1){
		int u,v,d;
		cin >> u >> v >> d;
		ps[u].push_back(d);
		ps[v].push_back(d);
	}
	ll tot = 0;
	rep(i,0,n){
		ll t = accumulate(all(ps[i]), 0LL);
		auto m = max_element(all(ps[i]));
		if (*m > t-*m){
			tot += *m - (t-*m);
		} else {
			tot += t % 2;
		}
	}
	cout << tot/2 << endl;
}