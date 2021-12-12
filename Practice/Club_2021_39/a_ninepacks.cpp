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
const int MAXN = 1e5+7;

int DP1[MAXN] = {0};
int DP2[MAXN] = {0};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int h, b;
	cin >> h;
	vi hs(h);
	rep(i,0,h) cin >> hs[i];
	cin >> b;
	vi bs(b);
	rep(i,0,b) cin >> bs[i];
	
	rep(i,0,MAXN){
		DP1[i] = 2e8;
		DP2[i] = 2e8;
	}
	DP1[0] = 0;
	DP2[0] = 0;
	rep(j,0,h){
		for(int i=MAXN-1; i>=0; --i){
			if (i-hs[j] >=0 ){
				DP1[i] = min(DP1[i], DP1[i-hs[j]]+1);
			}
		}
	}
	rep(j,0,b){
		for(int i=MAXN-1; i>=0; --i){
			if (i-bs[j] >=0 ){
				DP2[i] = min(DP2[i], DP2[i-bs[j]]+1);
			}
		}
	}
	int M = 1e8;
	rep(i,1,MAXN){
		M = min(M, DP1[i] + DP2[i]);
	}
	if (M == 1e8){
		cout << "impossible" << endl;
	}else{
		cout << M << endl;
	}
}