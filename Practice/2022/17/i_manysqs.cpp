#include <bits/stdc++.h>
using namespace std;
// incomplete
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define minim(a, b) a = min(a, b)
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef complex<double> cd;

struct frac{
	ll top, bot;
	frac(ll t, ll b):top(t), bot(b){
		ll g = gcd(abs(top), bot);
		top /= g;
		bot /= g;
	}
	const bool operator<(frac b) const {
		return top*b.bot < bot*b.top;
	}
	frac operator-(frac b) const {
		return frac(top*b.bot - b.top*bot, bot*b.bot);
	}
};

map<pii, vector<frac>> M1, M2;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	rep(i,0,n){
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		if (tie(x2, y2) < tie(x1, y1)) {
			swap(x1, x2); swap(y1, y2);
		}
		int g = gcd(x2-x1, abs(y2-y1));
		int a = (x2-x1)/g;
		int b = (y2-y1)/g;
		if (b <= 0){
			M2[{a, b}].push_back( frac(y1*a - x1*b, a));
		} else {
			M1[{a, b}].push_back( frac(x1*b - y1*a, b));
		}
	}
	ll tot = 0;
	for(auto &[a, b] : M1){
		auto [x, y] = a;
		auto it = M2.find({y, -x});
		if (it == M2.end()) continue;
		sort(all(b));
		sort(all(it->second));
		map<frac, int> A, B;
		rep(i,0,sz(b)){
			rep(j,i+1,sz(b)){
				A[b[j]-b[i]]++;
			}
		}
		rep(i,0,sz(it->second)){
			rep(j,i+1,sz(it->second)){
				B[it->second[j]-it->second[i]]++;
			}
		}
		for(auto& [e, f] : A){
			auto it2 = B.find(e);
			if (it2 != B.end()){
				tot += it2->second * (ll)f;
			}
		}

	}
	cout << tot << endl;

}