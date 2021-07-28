#include <bits/stdc++.h>
using namespace std;
// done
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

vector<ll> lsums;
vector<pii> segs;

ll sumto(int l){
	int lo=0, hi=sz(segs);
	while(hi-lo>1){
		int md = (hi+lo)>>1;
		if (segs[md].first<=l) lo = md;
		else hi = md;
	}
	return (ll)lsums[lo] + (ll)segs[lo].second * ( (ll)l-segs[lo].first);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N, Q;
	cin >> N >> Q;
	// vector<pii> segs;
	rep(i,0,N){
		int l, r, v;
		cin >> l >> r >> v;
		segs.push_back({l, v});
		segs.push_back({r, -v});
	}
	segs.push_back({0,0});
	sort(all(segs));
	lsums.resize(sz(segs));
	// vector<ll> lsums(sz(segs));
	ll t=0;
	ll s=0;
	ll tot = 0;
	int i=0;
	for(auto &[u, v] : segs){
		tot += s * (u-t);
		t = u;
		lsums[i++] = tot;
		v += s;
		s = v;
	}

	rep(j,0,Q){
		int l, r;
		cin >> l >> r;
		// cout << sumto(r) << " " << sumto(l);
		cout << sumto(r)-sumto(l) << endl;
	}
}