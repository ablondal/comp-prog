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

    size_t operator()(pii x) const {
    	return splitmix64( x.first ^ (x.second>>1) + FIXED_RANDOM );
    }
};

gp_hash_table<pii, int, custom_hash> safe_hash_table;
// Supports .find(), []++


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vi xs(n);
	vi ys(n);
	rep(i,0,n){
		cin >> xs[i] >> ys[i];
	}
	rep(i,0,n){
		rep(j,i+1,n){
			int dx = xs[i]-xs[j];
			int dy = ys[i]-ys[j];
			if (dx<0){
				dx*=-1;
				dy*=-1;
			}else if(dx==0){
				dy = abs(dy);
			}
			safe_hash_table[{dx,dy}]++;
		}
	}
	ll tot = 0;
	for(auto a : safe_hash_table){
		ll x = a.second;
		tot += x*(x-1)/2;
	}
	tot /= 2;
	cout << tot << endl;
}