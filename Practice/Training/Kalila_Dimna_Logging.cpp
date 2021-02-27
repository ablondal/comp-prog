#include <bits/stdc++.h>
using namespace std;
// incomplete
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef complex<ll> pt;
#define x real
#define y imag
const ll INF = 1e18+7;
const int MAXN = 1e5+7;

ll DP[MAXN];
int lastTree[MAXN];
ll a[MAXN], b[MAXN], s[MAXN];

ll dot(pt a, pt b){
	return (conj(a) * b).x();
}

ll cross(pt a, pt b){
	return (conj(a) * b).y();
}

vector<pt> hull, vecs;

void add_line(ll k, ll b){
	// Add the line kx + b
	// ks monotonically decrease, bs should increase
	pt nw = {k, b};
	// while(!vecs.empty() && dot(vecs.back(), nw-hull.back()) < 0){
	// 	hull.pop_back();
	// 	vecs.pop_back();
	// }
	// if(!hull.empty()) {
	// 	pt ol = hull.back() - nw;
	// 	vecs.push_back({-ol.y(), ol.x()});
	// }
	hull.push_back(nw);
	// for(auto lin : hull){
	// 	cout << lin << endl;
	// }
}

ll get(ll x){
	pt query = {x, 1};
	// auto it = lower_bound(vecs.begin(), vecs.end(), query, [](pt a, pt b){
	// 	return cross(a,b) < 0;
	// });
	// return dot(query, hull[it - vecs.begin()]);
	ll m = 1e18+7;
	for(auto h : hull){
		m = min(m, dot(query, h));
	}
	return m;
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int n;
	cin >> n;
	rep(i,0,n){
		cin >> a[i];
	}
	rep(i,0,n) cin >> b[i];
	
	DP[0] = 0;
	add_line(b[0], DP[0]);
	rep(i,1,n){
		DP[i] = get(a[i]);
		add_line(b[i], DP[i]);
		// cout << i << " " << DP[i] << endl;
	}
	cout << DP[n-1] << endl;
}