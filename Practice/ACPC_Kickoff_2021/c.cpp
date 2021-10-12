#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

// incomplete
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef pair<ll, ll> pll;

inline pll encodeedge(ll a, ll b, ll c, ll x, ll y, ll z){
	ll res1 = a + (b<<14) + (c<<28);
	ll res2 = x + (y<<14) + (z<<28);
	if (res1 > res2) swap(res1, res2);
	return {res1, res2};
}

struct custom_hash {
	// From https://codeforces.com/blog/entry/62393
    const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();

    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        return splitmix64(x + FIXED_RANDOM);
    }

    size_t operator()(pll x) const {
    	return splitmix64( x.first ^ (x.second>>1) + FIXED_RANDOM );
    }
};

gp_hash_table<pll, int, custom_hash> H;

int UF[100007];
int find(int a){
	return UF[a]<0 ? a : UF[a] = find(UF[a]);
}

void join(int a, int b){
	// cout << a << " " << b << endl;
	a = find(a);
	b = find(b);
	if (a!=b){
		UF[a] += UF[b];
		UF[b] = a;
	}
}

int main() {
	// ios_base::sync_with_stdio(false);
	// cin.tie(NULL);
    freopen("triangles.in","r",stdin);
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		H.clear();
		rep(i,0,n){
			UF[i] = -1;
		}
		rep(i,0,n){
			ll a, b, c, aa, bb, cc, x, y, z;
			cin >> a >> b >> c >> aa >> bb >> cc >> x >> y >> z;
			auto e1 = encodeedge(a, b, c, aa, bb, cc);
			auto e2 = encodeedge(a, b, c, x, y, z);
			auto e3 = encodeedge(aa, bb, cc, x, y, z);
			if (H.find(e1) != H.end()){
				join(i, H[e1]);
			}else H[e1] = i;

			if (H.find(e2) != H.end()){
				join(i, H[e2]);
			}else H[e2] = i;

			if (H.find(e3) != H.end()){
				join(i, H[e3]);
			}else H[e3] = i;
		}
		if (UF[find(0)] == -n){
			cout << "Yes" << endl;
		} else {
			cout << "No" << endl;
		}
	}
}