#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
// done
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
constexpr int MAXN = 2e5;

ll B[MAXN] = {0};

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
}; // 11111100000000

typedef gp_hash_table<long long, int, custom_hash> hash_set;

int main() {
	srand (time(NULL));
	int n, m, p;
	scanf("%d%d%d", &n, &m, &p);
	rep(i,0,n){
		char c[m+1];
		scanf("%s", c);
		rep(j,0,m){
			// char c;
			// scanf(" %c", &c);
			if (c[j]-'0') B[i] |= (1LL << j);
		}
	}
	ll M = 0;
	int Ms = 0;
	
	rep(t,0,10){
		int x= (unsigned ll)custom_hash::splitmix64(rand()) % n;
		map<ll, int> S;
		rep(i,0,n){
			ll mm = B[i] & B[x];
			S[mm]++;
		}
		hash_set S2;
		for(auto &[mm, c] : S){
			ll s = mm;
			while(s>0){
				S2[s]+=c;
				s = (s-1) & mm;
			}
		}
		for(auto &[k, c] : S2){
			if (c >= (n+1)/2 && __builtin_popcountll(k) > Ms){
				Ms = __builtin_popcountll(k);
				M = k;

			}
		}
	}

	rep(i,0,m) {
		printf("%c", '0'+ (M&1));
		M>>=1;
	}
	
	printf("\n", Ms);
}