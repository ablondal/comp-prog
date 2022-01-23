#include <bits/stdc++.h>
using namespace std;
// incomplete
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n,m;
	cin >> n >> m;
	vector<vi> g(n+2,vi(m+2,1));
	rep(i,1,n+1){
		string s;
		cin >> s;
		rep(j,0,m){
			if (s[j]=='.') g[i][j+1]=0;
		}
	}

	vector<ll> szs(max(n,m)+7,0);

	rep(i,1,n+2){
		int last = 0;
		rep(j,1,m+2){
			if (g[i][j]){
				if (!g[i][j-1]){
					szs[j-last-1]++;
					// cout << j-last-1 << endl;
					// cout << j << endl;
				}
				last = j;
			}
		}
	}

	rep(j,1,m+2){
		int last = 0;
		rep(i,1,n+2){
			if (g[i][j]){
				if (!g[i-1][j]){
					szs[i-last-1]++;
					// cout << i-last-1 << endl;
				}
				last = i;
			}
		}
	}

	ll tot = 0;
	ll tota = 0;
	for(int j=max(n,m); j>=0; --j){
		ll tmp = szs[j];
		tot += tota;
		szs[j] += tot;
		tota += tmp;
		tot += tmp;
	}

	szs[1] /= 2;

	rep(i,1,max(n,m)+1){
		cout << szs[i] << " ";
	}
	cout << endl;
}