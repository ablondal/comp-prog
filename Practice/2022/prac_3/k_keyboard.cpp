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

int DP[1007][1007] = {{0}};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	vector<unordered_set<int>> k(n);
	vi l(m);
	rep(i,0,n){
		int ki;
		cin >> ki;
		rep(j,0,ki){
			int tmp;
			cin >> tmp;
			k[i].insert(tmp);
		}
	}
	rep(i,0,1006) rep(j,0,1006){
		DP[i][j] = 1e6;
	}
	rep(j,0,1006){
		DP[0][j] = 0;
	}
	rep(i,1,m+1){
		int mm = 1e6;
		rep(j,0,1006) mm = min(mm, DP[i-1][j]);
		int li;
		cin >> li;
		rep(j,0,n){
			if (k[j].count(li)){
				DP[i][j] = min(mm+1, DP[i-1][j]);
			}
		}
	}
	int mm = 1e6;
	rep(j,0,1006){
		mm = min(mm, DP[m][j]);
	}
	cout << mm << endl;

}