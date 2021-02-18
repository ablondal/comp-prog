#include <bits/stdc++.h>
using namespace std;
// incomplete
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const ll INF = 1e18+7;
const int MAXN = 1e5+7;

ll DP[MAXN];
int lastTree[MAXN];
ll a[MAXN], b[MAXN], s[MAXN];

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int n;
	cin >> n;
	rep(i,0,n){
		cin >> a[i];
	}
	rep(i,0,n) cin >> b[i];
	// s[0] = a[0];
	// rep(i,1,n) s[i] = a[i]+s[i-1];
	DP[0] = 0;
	lastTree[0] = 0;
	rep(i,1,n) {
		ll la = INF;
		ll curr = INF;
		int j = lastTree[i-1];
		DP[i] = INF;
		while(j<i){
			if (DP[j] + (b[j]*a[i]) <= DP[i]){
				DP[i] = DP[j]+(b[j]*a[i]);
				lastTree[i] = j;
			}
			// tie(DP[i], lastTree[i]) = min(tie(DP[i], lastTree[i]), tie(DP[j]+(b[j]*a[i]), j));
			++j;
		}
		// do {
		// 	la = curr;
		// 	curr = DP[j];
		// 	curr += b[j]*(a[i]-1) + b[i];
		// 	j+=1;
		// }while(j < i && curr <= la);
		// if (curr <= la){
		// 	lastTree[i] = j-1;
		// 	DP[i] = curr;
		// }else{
		// 	lastTree[i] = j-2;
		// 	DP[i] = la;
		// }
		// printf("%lld %d\n", DP[i], lastTree[i]);
	}
	cout << DP[n-1] << endl;
}