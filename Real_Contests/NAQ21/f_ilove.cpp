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
const ll MOD = 1e9+7;

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

typedef gp_hash_table<int, ll, custom_hash> safe_ht;

map<char, int> M;
set<char> vow = {'a','e','i','o','u','A','E','I','O','U'};

safe_ht statectv;
safe_ht statectc;

ll dub[5][1<<10] = {{0}};
ll sinn[46][5][1<<10] = {{{0}}};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int as = 0;
	for(auto &c : vow){
		M[c] = as++;
	}
	string s;
	cin >> s;

	statectc[0] = 1;
	ll tot = 0;

	dub[0][0] = 1;
	rep(i,0,46){
		sinn[i][0][0] = 1;
	}

	rep(i,0,sz(s)){

		if (vow.count(s[i])) {
			int n = M[s[i]];
			rep(j,0,5){
				if (j%2) continue;
				rep(k,0,1<<10){
					if (! (k & (1<<n)) ) {
						dub[j+1][k | (1<<n)] += dub[j][k];
						dub[j+1][k | (1<<n)] %= MOD;
					}
				}
			}
			rep(l,0,46){
				rep(j,0,5){
					if (j%2) continue;
					rep(k,0,1<<10){
						if (! (k & (1<<n)) ) {
							sinn[l][j+1][k | (1<<n)] += sinn[l][j][k];
							sinn[l][j+1][k | (1<<n)] %= MOD;
						}
					}
				}
			}
		} else {
			int n = s[i] - 'A' - ('a' < s[i] ? 'a'-'A' : 0);
			rep(j,0,5){
				if (!(j%2)) continue;
				rep(k,0,1<<10){
					dub[j+1][k] += dub[j][k];
					dub[j+1][k] %= MOD;
				}
			}
			rep(j,0,5){
				if (!(j%2)) continue;
				rep(k,0,1<<10){
					sinn[n][j+1][k] += sinn[n][j][k];
					sinn[n][j+1][k] %= MOD;
				}
			}
		}
	}
	rep(k,0,46){
		rep(j,0,1<<10){
			tot -= sinn[k][5][j];
			tot %= MOD;
		}
	}
	rep(k,0,1<<10){
		tot += dub[5][k];
		tot %= MOD;
	}
	tot += MOD;
	tot %= MOD;
	cout << tot << endl;
}