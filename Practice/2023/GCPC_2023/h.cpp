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
typedef vector<ll> vll;
typedef complex<double> cd;
ll p = 1e9 + 7;
ll fib[207] = {0};

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

gp_hash_table<long long, vector<int>, custom_hash> M;

ll binpow(ll a, ll x){
	ll r = 1;
	while(x){
		if (x & 1) r = (r*a)%p;
		a = (a*a)%p;
		x >>= 1;
	}
	return r;
}

ll inv(ll x){
	return binpow(x, p-2);
}

int ct = 0;

void make_p(int space){
	using piv = tuple<int, int, vi>;
	priority_queue<piv, vector<piv>> Q;
	Q.push({space,1,{}});
	// M[1] = {};

	while(!Q.empty()){
		auto [l, c, curr] = Q.top();
		Q.pop();
		if (M.find(c) != M.end()) continue;
		M[c].assign(all(curr));
		ct++;
		rep(i,2,l-1){
			curr.push_back(i);
			ll nc = (c * fib[i]) % p;
			Q.push({l-i-1, nc, curr});
			curr.pop_back();
		}
	}
}

void ans(vector<int> a1, vector<int> a2){
	vi A(all(a1));
	for(auto aa: a2){
		A.push_back(aa);
	}
	rep(tt,0,2){
		rep(i,0,sz(A)){
			int a = A[i];
			rep(i,0,a){
				cout << ".";
			}
			if (i != sz(A)-1){
				cout << "#";
			}
		}
		cout << endl;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n;
	cin >> n;
	fib[0] = fib[1] = 1;
	rep(i,2,207) fib[i] = (fib[i-1]+fib[i-2]) % p;

	vi curr;
	make_p(60);
	// cout << ct << endl;

	vector<pair<ll, vector<int>>> Va;
	rep(i,2,200){
		rep(j,i,200){
			rep(k,j,200){
				if (i+j+k+2 <= 200) {
					ll bb = (fib[i]*fib[j])%p;
					bb = (bb * fib[k])%p;
					if (n == bb){
						ans({i,j,k}, {});
						return 0;
					}
				}
				// if (i+j+k+2 <= 140)
			}
			if (i + j + 1 <= 200) {
				ll bb = (fib[i]*fib[j])%p;
				// bb = (bb * fib[k])%p;
				if (n == bb){
					ans({i,j}, {});
					return 0;
				}
				// Va.push_back({(fib[i]*fib[j])%p, {i, j}});
			}
		}
	}

	rep(i,2,139) {
		ll a = fib[i];
		vi v1 = {i};
		ll m = (n * inv(a)) % p;
		if (M.find(m) != M.end()) {
			ans(v1, M[m]);
			return 0;
		}
	}

	for(auto &[a, v1]: M){
		ll m = (n * inv(a)) % p;
		if (M.find(m) != M.end()) {
			ans(v1, M[m]);
			return 0;
		}
	}
	// for(auto &[a, v])
}