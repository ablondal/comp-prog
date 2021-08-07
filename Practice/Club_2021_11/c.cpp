#include <bits/stdc++.h>
using namespace std;
// done
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int INF = 1e9;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	scanf("%d", &n);
	vector<pair<int, int>> a;
	ll tot1 = 0;
	ll tot2 = 0;
	ll m1 = 0;
	ll m2 = INF;
	rep(i,0,n){
		ll c,d;
		scanf("%lld%lld", &c, &d);
		a.push_back({c-d, c});
		tot1 += c;
		tot2 += d;
		m1 = max(m1, c);
		m2 = min(m2, c-d);
	}
	// printf("%lld\n", max(m1, tot2 + m2) );
	sort(all(a));
	ll nn = 0;
	ll rem = 0;
	for(int i=sz(a)-1; i>=0; --i){
		if (rem < a[i].second){
			nn += a[i].second - rem;
			rem = a[i].second;
		}
		rem -= (a[i].second-a[i].first);
	}
	printf("%lld\n", nn);
}