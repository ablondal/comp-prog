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
typedef complex<double> cd;
const int MX = 1e4+7;
const ll MOD = 1e9+7;

ll DP[MX][10][107] = {{0}};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string a;
	int d;
	vi b;
	cin >> a >> d;
	rep(i,0,sz(a)) b.push_back(a[i]-'0');

	DP[0][0][0] = 1;
	rep(i,0,sz(b)){
		// if (i % 1000 == 0) cout << i << endl;
		rep(j,0,10){
			rep(k,0,d){
				rep(l,0,10){
					DP[i+1][l][(k+l)%d] += DP[i][j][k];
					DP[i+1][l][(k+l)%d] %= MOD;
				}
			}
		}
	}

	ll tot = 0;
	int d_sum = 0;
	rep(i,0,sz(b)){
		rep(j,0,b[i]){
			tot += DP[sz(b)-i][j][(d-d_sum)%d];
			tot %= MOD;
		}
		// if (i == sz(b)) break;
		d_sum += b[i];
		d_sum %= d;
	}
	if (d_sum == 0) tot++;
	cout << (tot+MOD-1)%MOD << endl;

}